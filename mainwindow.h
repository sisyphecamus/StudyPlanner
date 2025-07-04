#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recordshower.h"
#include <QDate>
#include <QHash>
#include "taskitem.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void showTasks();

private slots:

    void on_pushButton_CreateTask_clicked();

    void on_pushButton_ViewRecord_clicked();

private:
    Ui::MainWindow *ui;
    RecordShower * record = nullptr;
    RecordManager RM;
    string RMPath;
    TaskManager TM;
    string TMPath;
    string TRPath;
    QDate date;
    QHash<int, TaskItem*> taskItemMap;
    // QObject interface
protected:
    void timerEvent(QTimerEvent *event) override;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;

public slots:
    void dateChange();
    void deleteTask(int taskID);
    void editTask(int taskID);
    void completeTask(int taskID);
};
#endif // MAINWINDOW_H
