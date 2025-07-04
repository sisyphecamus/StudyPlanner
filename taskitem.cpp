#include "taskitem.h"
#include "ui_taskitem.h"
#include <QTime>
#include <QDir>
TaskItem::TaskItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TaskItem)
{
    ui->setupUi(this);
    ui->pushButton_Complete->setIcon(QIcon(QDir::currentPath() + "/assets/check.png"));
}

TaskItem::~TaskItem()
{
    delete ui;
}

void TaskItem::setTask(const Task &task)
{
    this->taskID = task.getId();

    ui->label_Title->setText(QString::fromStdString(task.getTitle()));

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(task.getDeadLine().time_since_epoch()).count();
    QDateTime dt = QDateTime::fromMSecsSinceEpoch(ms);
    ui->label_DeadLine->setText(dt.toString("HH:mm:ss"));

    QString priorty;
    switch(task.getPriority())
    {
    case 0:
        priorty = QString("Important");break;
    case 1:
        priorty = QString("Normal");break;
    case 2:
        priorty = QString("Casual");break;
    }
    ui->label_Priority->setText(priorty);
}

void TaskItem::on_pushButton_Delete_clicked()
{
    emit requestDelete(taskID);
}


void TaskItem::on_pushButton_Complete_clicked()
{
    emit requestComplete(taskID);
}


void TaskItem::on_pushButton_Edit_clicked()
{
    emit requestEdit(taskID);
}

