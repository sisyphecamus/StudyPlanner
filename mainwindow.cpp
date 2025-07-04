#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskitem.h"
#include "inputdialog.h"
#include "recordshower.h"
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_Date->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->label_Time->setText(QTime::currentTime().toString());

    setWindowIcon(QIcon(QDir::currentPath()+"/assets/icon.png"));

    date = QDate::currentDate();

    RMPath = QCoreApplication::applicationDirPath().toStdString() + "/data/RecordManager.json";
    RM.loadFromJson(RMPath);
    TMPath = QCoreApplication::applicationDirPath().toStdString() + "/data/TaskManager.json";
    TM.loadTaskfromJson(TMPath);
    TRPath = QCoreApplication::applicationDirPath().toStdString() + "/data/reviewTasks.json";

    //startup check
    if(date.toString("yyyy-MM-dd").toStdString()!=TM.current_date)
    {
        dateChange();
    }


    showTasks();


    startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTasks()
{
    ui->listWidget_PendingTasks->clear();
    ui->listWidget_FinishedTasks->clear();
    taskItemMap.clear();

    for (const auto& [id, task] : TM.getAllTasks())
    {
        if(!task.getCompletedStats())
        {
            QListWidgetItem* listItem = new QListWidgetItem(ui->listWidget_PendingTasks);
            TaskItem* itemWidget = new TaskItem();
            itemWidget->setTask(task);
            listItem->setSizeHint(itemWidget->sizeHint());//!!important
            ui->listWidget_PendingTasks->addItem(listItem);
            ui->listWidget_PendingTasks->setItemWidget(listItem, itemWidget);
            connect(itemWidget,&TaskItem::requestComplete,this,&MainWindow::completeTask);
            connect(itemWidget,&TaskItem::requestEdit,this,&MainWindow::editTask);
            connect(itemWidget,&TaskItem::requestDelete,this,&MainWindow::deleteTask);
            taskItemMap[id] = itemWidget;
        }
        else
        {
            QListWidgetItem* listItem = new QListWidgetItem(ui->listWidget_FinishedTasks);
            listItem->setText(QString::fromStdString(task.getTitle()));
        }
    }
    //whoa it supports Markdown XD
    ui->label_TaskNumber->setText(QString("## Today  \n # %1/%2  ").arg(TM.getCompletedTasks()).arg(TM.getTotalTasks()));
    ui->progressBar->setValue(100*(float)TM.getCompletedTasks()/(float)TM.getTotalTasks());

}




void MainWindow::on_pushButton_CreateTask_clicked()
{
    auto input = new InputDialog(this);
    input->setCreateUI();
    if(input->exec() == QDialog::Accepted)
    {
        // 1. 获取输入数据
        std::string title = input->getTitle().toStdString();
        std::string content = input->getContent().toStdString();
        int priority = input->getPriority();
        QDateTime deadline = input->getDeadLine();
        bool needs_review = input->getNeedsReview();

        // 2. 构造 TaskContent
        TaskContent task_content{title, content};

        // 3. 构造 Task
        Task new_task(priority, task_content, false, needs_review, TM, std::chrono::system_clock::time_point(std::chrono::milliseconds(deadline.toMSecsSinceEpoch())));
        TM.loadTask(new_task);

    }
    delete input;
    showTasks();
}



void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    ui->label_Time->setText(QTime::currentTime().toString());
    if(QDate::currentDate() != date)
    {
        dateChange();
    }
    // deadline check
    auto now = std::chrono::system_clock::now();
    for (const auto& [id, task] : TM.getAllTasks())
    {
        if (!task.getCompletedStats() && now >= task.getDeadLine())
        {
            taskItemMap[id]->setStyleSheet("color: red;");
            auto deadline = task.getDeadLine();
            auto diff = std::chrono::duration_cast<std::chrono::seconds>(deadline - now).count();
            if(diff <= 1 && diff >= 0 )
            QMessageBox::information(this, "Reminder",QString("[ %1 ] is overdue.").arg(QString::fromStdString(task.getTitle())));

        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    RM.dumpEntries(RMPath);
    TM.dumpTask(TMPath,0);

}
/*
 * 1. dump repeat tasks to file
 * 2. generate a date entry from taskmanager -> calling constructor of date entry (will add a date entry to recordmanager)
 * 3. change current date(both mainwindow and taskmanager)
 * 4. load repeat tasks to taskmanager
 */
void MainWindow::dateChange()
{
    TM.dumpTask(TRPath,1);
    DateEntry(TM.current_date,TM,RM);
    date = QDate::currentDate();
    TM.loadTaskfromJson(TRPath);
    TM.current_date = QDate::currentDate().toString("yyyy-MM-dd").toStdString();
}

void MainWindow::deleteTask(int taskID)
{
    TM.deleteTask(taskID);
    showTasks();
}

void MainWindow::editTask(int taskID)
{
    auto input = new InputDialog(this);
    input->setEditUI(TM.tasks[taskID]);
    if(input->exec() == QDialog::Accepted)
    {
        // 1. 获取输入数据
        std::string title = input->getTitle().toStdString();
        std::string content = input->getContent().toStdString();
        int priority = input->getPriority();
        QDateTime deadline = input->getDeadLine();
        bool needs_review = input->getNeedsReview();

        // 2. 构造 TaskContent
        TaskContent task_content{title, content};


        TM.updateTask(taskID,task_content,std::chrono::system_clock::time_point(std::chrono::milliseconds(deadline.toMSecsSinceEpoch())),priority,needs_review);

        showTasks();
    }
    delete input;
}

void MainWindow::completeTask(int taskID)
{
    TM.tasks[taskID].markCompleted();
    showTasks();
}


void MainWindow::on_pushButton_ViewRecord_clicked()
{
    if(record==nullptr)
    {
        record = new RecordShower(this);
        record->setWindowFlag(Qt::Window);
    }
    record->showRecords(RM);
    record->show();
}


