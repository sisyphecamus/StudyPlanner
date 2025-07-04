#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>
#include "backend/include/Task.h"
namespace Ui {
class TaskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();
    void setTask(const Task& task);
private slots:
    void on_pushButton_Delete_clicked();

    void on_pushButton_Complete_clicked();

    void on_pushButton_Edit_clicked();

private:
    Ui::TaskItem *ui;
    int taskID;
signals:
    void requestDelete(int taskID);
    void requestEdit(int taskID);
    void requestComplete(int taskID);
};

#endif // TASKITEM_H
