/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_Deadline;
    QSpinBox *spinBox_DeadlineHour;
    QLabel *label_Colon1;
    QSpinBox *spinBox_DeadlineMinute;
    QLabel *label_Colon2;
    QSpinBox *spinBox_DeadlineSecond;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Title;
    QLineEdit *lineEdit_Title;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Content;
    QTextEdit *textEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_Repeat;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Priority;
    QComboBox *comboBox_Priority;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName("InputDialog");
        InputDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(InputDialog);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(InputDialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        label_Deadline = new QLabel(widget);
        label_Deadline->setObjectName("label_Deadline");

        horizontalLayout->addWidget(label_Deadline);

        spinBox_DeadlineHour = new QSpinBox(widget);
        spinBox_DeadlineHour->setObjectName("spinBox_DeadlineHour");
        spinBox_DeadlineHour->setMaximum(23);

        horizontalLayout->addWidget(spinBox_DeadlineHour);

        label_Colon1 = new QLabel(widget);
        label_Colon1->setObjectName("label_Colon1");
        label_Colon1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_Colon1);

        spinBox_DeadlineMinute = new QSpinBox(widget);
        spinBox_DeadlineMinute->setObjectName("spinBox_DeadlineMinute");
        spinBox_DeadlineMinute->setMaximum(59);

        horizontalLayout->addWidget(spinBox_DeadlineMinute);

        label_Colon2 = new QLabel(widget);
        label_Colon2->setObjectName("label_Colon2");
        label_Colon2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(label_Colon2);

        spinBox_DeadlineSecond = new QSpinBox(widget);
        spinBox_DeadlineSecond->setObjectName("spinBox_DeadlineSecond");
        spinBox_DeadlineSecond->setMaximum(59);

        horizontalLayout->addWidget(spinBox_DeadlineSecond);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(InputDialog);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_Title = new QLabel(widget_2);
        label_Title->setObjectName("label_Title");

        horizontalLayout_2->addWidget(label_Title);

        lineEdit_Title = new QLineEdit(widget_2);
        lineEdit_Title->setObjectName("lineEdit_Title");

        horizontalLayout_2->addWidget(lineEdit_Title);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(InputDialog);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_Content = new QLabel(widget_3);
        label_Content->setObjectName("label_Content");
        label_Content->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        horizontalLayout_3->addWidget(label_Content);

        textEdit = new QTextEdit(widget_3);
        textEdit->setObjectName("textEdit");

        horizontalLayout_3->addWidget(textEdit);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(InputDialog);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        checkBox_Repeat = new QCheckBox(widget_4);
        checkBox_Repeat->setObjectName("checkBox_Repeat");

        horizontalLayout_4->addWidget(checkBox_Repeat);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_Priority = new QLabel(widget_4);
        label_Priority->setObjectName("label_Priority");
        label_Priority->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_Priority);

        comboBox_Priority = new QComboBox(widget_4);
        comboBox_Priority->addItem(QString());
        comboBox_Priority->addItem(QString());
        comboBox_Priority->addItem(QString());
        comboBox_Priority->setObjectName("comboBox_Priority");

        horizontalLayout_4->addWidget(comboBox_Priority);


        verticalLayout->addWidget(widget_4);

        buttonBox = new QDialogButtonBox(InputDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(InputDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, InputDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, InputDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QDialog *InputDialog)
    {
        InputDialog->setWindowTitle(QCoreApplication::translate("InputDialog", "Create Task", nullptr));
        label_Deadline->setText(QCoreApplication::translate("InputDialog", "Deadline:", nullptr));
        label_Colon1->setText(QCoreApplication::translate("InputDialog", ":", nullptr));
        label_Colon2->setText(QCoreApplication::translate("InputDialog", ":", nullptr));
        label_Title->setText(QCoreApplication::translate("InputDialog", "Title:", nullptr));
        label_Content->setText(QCoreApplication::translate("InputDialog", "Content:", nullptr));
        checkBox_Repeat->setText(QCoreApplication::translate("InputDialog", "Repeat", nullptr));
        label_Priority->setText(QCoreApplication::translate("InputDialog", "Priority:", nullptr));
        comboBox_Priority->setItemText(0, QCoreApplication::translate("InputDialog", "Important", nullptr));
        comboBox_Priority->setItemText(1, QCoreApplication::translate("InputDialog", "Normal", nullptr));
        comboBox_Priority->setItemText(2, QCoreApplication::translate("InputDialog", "Casual", nullptr));

    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
