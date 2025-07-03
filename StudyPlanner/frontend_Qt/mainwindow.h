#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recordshower.h"
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

private slots:
    // void on_pushButton_clicked();

    void on_pushButton_CreateTask_clicked();

    void on_pushButton_ViewRecord_clicked();

private:
    Ui::MainWindow *ui;
    RecordShower * record = nullptr;
    // QObject interface
protected:
    void timerEvent(QTimerEvent *event) override;
};
#endif // MAINWINDOW_H
