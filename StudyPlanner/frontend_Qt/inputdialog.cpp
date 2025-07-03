#include "inputdialog.h"
#include "ui_inputdialog.h"
#include <QMessageBox>
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

void InputDialog::on_buttonBox_accepted()
{
    QMessageBox::information(this,"test","OK");
}


void InputDialog::on_buttonBox_rejected()
{
    QMessageBox::information(this,"test","Canceled");
}

