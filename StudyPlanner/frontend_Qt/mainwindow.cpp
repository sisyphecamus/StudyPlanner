#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskitem.h"
#include "inputdialog.h"
#include "recordshower.h"
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QDir>
#include <QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_Date->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->label_Time->setText(QTime::currentTime().toString());
    auto trayicon = new QSystemTrayIcon(this);
    trayicon->show();
    trayicon->showMessage("testtitle","testmsg",QIcon("C:/Users/14642/Desktop/mainwindow.png"));
    startTimer(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}



// void MainWindow::on_pushButton_clicked()
// {
//     auto item = new QListWidgetItem();
//     ui->listWidget->addItem(item);
//     ui->listWidget->setItemWidget(item,new TaskItem());
// }


void MainWindow::on_pushButton_CreateTask_clicked()
{
    auto input = new InputDialog(this);
    input->exec();
}



void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    ui->label_Time->setText(QTime::currentTime().toString());
}


void MainWindow::on_pushButton_ViewRecord_clicked()
{
    // if(record==nullptr)
    // {
    //     record = new RecordShower(this);
    //     record->setWindowFlag(Qt::Window);
    // }
    // record->show();
    static RecordManager backend;
    static bool loaded = false;
    if (!loaded) {
        //the path only for test use. change in distribution.
        backend.loadFromJson("E:/QtProjects/To_Do_List/backend/saved_json_file/RecordManager.json");
        loaded = true;
    }

    if(record==nullptr)
    {
        record = new RecordShower(this);
        record->setWindowFlag(Qt::Window);
    }
    record->showRecords(backend);
    record->show();
}

