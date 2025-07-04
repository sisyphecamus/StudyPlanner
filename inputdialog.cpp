#include "inputdialog.h"
#include "ui_inputdialog.h"
#include <QMessageBox>
#include <QTime>
InputDialog::InputDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::setCreateUI()
{
    ui->spinBox_DeadlineHour->setValue(QTime::currentTime().hour());
    ui->spinBox_DeadlineMinute->setValue(QTime::currentTime().minute());
    ui->spinBox_DeadlineSecond->setValue(QTime::currentTime().second());
}

void InputDialog::setEditUI(Task &t)
{
    auto dateTime =  QDateTime::fromMSecsSinceEpoch(std::chrono::duration_cast<std::chrono::milliseconds>(t.getDeadLine().time_since_epoch()).count());
    ui->spinBox_DeadlineHour->setValue(dateTime.time().hour());
    ui->spinBox_DeadlineMinute->setValue(dateTime.time().minute());
    ui->spinBox_DeadlineSecond->setValue(dateTime.time().second());
    ui->lineEdit_Title->setText(QString::fromStdString(t.getTitle()));
    ui->textEdit->setText(QString::fromStdString(t.getContent()));
    ui->checkBox_Repeat->setChecked(t.getReviewStats());
    ui->comboBox_Priority->setCurrentIndex(t.getPriority());
}

QString InputDialog::getTitle() const
{
    return ui->lineEdit_Title->text();
}

QString InputDialog::getContent() const
{
    return ui->textEdit->toPlainText();
}

int InputDialog::getPriority() const
{
    return ui->comboBox_Priority->currentIndex();
}

bool InputDialog::getNeedsReview() const
{
    return ui->checkBox_Repeat->isChecked();
}

QDateTime InputDialog::getDeadLine() const
{
    int hour = ui->spinBox_DeadlineHour->value();
    int minute = ui->spinBox_DeadlineMinute->value();
    int second = ui->spinBox_DeadlineSecond->value();
    QDateTime deadLine(QDate::currentDate(),QTime(hour,minute,second));
    return deadLine;
}
