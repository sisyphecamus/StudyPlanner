/********************************************************************************
** Form generated from reading UI file 'taskitem.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKITEM_H
#define UI_TASKITEM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskItem
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Delete;
    QLabel *label_Title;
    QLabel *label_DeadLine;
    QLabel *label_Priority;
    QPushButton *pushButton_Complete;
    QPushButton *pushButton_Edit;

    void setupUi(QWidget *TaskItem)
    {
        if (TaskItem->objectName().isEmpty())
            TaskItem->setObjectName("TaskItem");
        TaskItem->resize(370, 77);
        horizontalLayout = new QHBoxLayout(TaskItem);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_Delete = new QPushButton(TaskItem);
        pushButton_Delete->setObjectName("pushButton_Delete");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_Delete->sizePolicy().hasHeightForWidth());
        pushButton_Delete->setSizePolicy(sizePolicy);
        pushButton_Delete->setMinimumSize(QSize(16, 16));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        pushButton_Delete->setIcon(icon);

        horizontalLayout->addWidget(pushButton_Delete);

        label_Title = new QLabel(TaskItem);
        label_Title->setObjectName("label_Title");

        horizontalLayout->addWidget(label_Title);

        label_DeadLine = new QLabel(TaskItem);
        label_DeadLine->setObjectName("label_DeadLine");

        horizontalLayout->addWidget(label_DeadLine);

        label_Priority = new QLabel(TaskItem);
        label_Priority->setObjectName("label_Priority");

        horizontalLayout->addWidget(label_Priority);

        pushButton_Complete = new QPushButton(TaskItem);
        pushButton_Complete->setObjectName("pushButton_Complete");
        sizePolicy.setHeightForWidth(pushButton_Complete->sizePolicy().hasHeightForWidth());
        pushButton_Complete->setSizePolicy(sizePolicy);
        pushButton_Complete->setMinimumSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_Complete);

        pushButton_Edit = new QPushButton(TaskItem);
        pushButton_Edit->setObjectName("pushButton_Edit");
        sizePolicy.setHeightForWidth(pushButton_Edit->sizePolicy().hasHeightForWidth());
        pushButton_Edit->setSizePolicy(sizePolicy);
        pushButton_Edit->setMinimumSize(QSize(16, 16));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        pushButton_Edit->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_Edit);


        retranslateUi(TaskItem);

        QMetaObject::connectSlotsByName(TaskItem);
    } // setupUi

    void retranslateUi(QWidget *TaskItem)
    {
        TaskItem->setWindowTitle(QCoreApplication::translate("TaskItem", "Form", nullptr));
        pushButton_Delete->setText(QString());
        label_Title->setText(QCoreApplication::translate("TaskItem", "Title", nullptr));
        label_DeadLine->setText(QCoreApplication::translate("TaskItem", "DeadLine", nullptr));
        label_Priority->setText(QCoreApplication::translate("TaskItem", "Priority", nullptr));
        pushButton_Complete->setText(QString());
        pushButton_Edit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TaskItem: public Ui_TaskItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKITEM_H
