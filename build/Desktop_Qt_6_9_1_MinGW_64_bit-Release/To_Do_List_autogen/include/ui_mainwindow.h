/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget_PendingTasks;
    QListWidget *listWidget_FinishedTasks;
    QGroupBox *groupBox_RightPanel;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_CompleteRate;
    QVBoxLayout *verticalLayout;
    QLabel *label_TaskNumber;
    QProgressBar *progressBar;
    QGroupBox *groupBox_Time;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_Date;
    QLabel *label_Time;
    QGroupBox *groupBox_Buttons;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_CreateTask;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ViewRecord;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 500);
        QIcon icon;
        icon.addFile(QString::fromUtf8("build/Desktop_Qt_6_9_1_MinGW_64_bit-Release/assets/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(7);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName("verticalLayout_4");
        listWidget_PendingTasks = new QListWidget(frame);
        listWidget_PendingTasks->setObjectName("listWidget_PendingTasks");
        listWidget_PendingTasks->setAlternatingRowColors(true);

        verticalLayout_4->addWidget(listWidget_PendingTasks);

        listWidget_FinishedTasks = new QListWidget(frame);
        listWidget_FinishedTasks->setObjectName("listWidget_FinishedTasks");
        QFont font;
        font.setStrikeOut(true);
        listWidget_FinishedTasks->setFont(font);
        listWidget_FinishedTasks->setStyleSheet(QString::fromUtf8("QListWidget::item { color: gray;}"));

        verticalLayout_4->addWidget(listWidget_FinishedTasks);


        horizontalLayout_2->addWidget(frame);

        groupBox_RightPanel = new QGroupBox(centralwidget);
        groupBox_RightPanel->setObjectName("groupBox_RightPanel");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_RightPanel->sizePolicy().hasHeightForWidth());
        groupBox_RightPanel->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(groupBox_RightPanel);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox_CompleteRate = new QGroupBox(groupBox_RightPanel);
        groupBox_CompleteRate->setObjectName("groupBox_CompleteRate");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_CompleteRate->sizePolicy().hasHeightForWidth());
        groupBox_CompleteRate->setSizePolicy(sizePolicy2);
        verticalLayout = new QVBoxLayout(groupBox_CompleteRate);
        verticalLayout->setObjectName("verticalLayout");
        label_TaskNumber = new QLabel(groupBox_CompleteRate);
        label_TaskNumber->setObjectName("label_TaskNumber");
        label_TaskNumber->setFrameShape(QFrame::Shape::NoFrame);
        label_TaskNumber->setTextFormat(Qt::TextFormat::MarkdownText);
        label_TaskNumber->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_TaskNumber);

        progressBar = new QProgressBar(groupBox_CompleteRate);
        progressBar->setObjectName("progressBar");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy3);
        progressBar->setMinimum(0);
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_3->addWidget(groupBox_CompleteRate);

        groupBox_Time = new QGroupBox(groupBox_RightPanel);
        groupBox_Time->setObjectName("groupBox_Time");
        verticalLayout_2 = new QVBoxLayout(groupBox_Time);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_Date = new QLabel(groupBox_Time);
        label_Date->setObjectName("label_Date");
        label_Date->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_Date);

        label_Time = new QLabel(groupBox_Time);
        label_Time->setObjectName("label_Time");
        label_Time->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_Time);


        verticalLayout_3->addWidget(groupBox_Time);

        groupBox_Buttons = new QGroupBox(groupBox_RightPanel);
        groupBox_Buttons->setObjectName("groupBox_Buttons");
        horizontalLayout = new QHBoxLayout(groupBox_Buttons);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_CreateTask = new QPushButton(groupBox_Buttons);
        pushButton_CreateTask->setObjectName("pushButton_CreateTask");
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::ListAdd));
        pushButton_CreateTask->setIcon(icon1);
        pushButton_CreateTask->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_CreateTask);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_ViewRecord = new QPushButton(groupBox_Buttons);
        pushButton_ViewRecord->setObjectName("pushButton_ViewRecord");
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpenRecent));
        pushButton_ViewRecord->setIcon(icon2);
        pushButton_ViewRecord->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_ViewRecord);


        verticalLayout_3->addWidget(groupBox_Buttons);


        horizontalLayout_2->addWidget(groupBox_RightPanel);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "StudyPlanner", nullptr));
        groupBox_RightPanel->setTitle(QString());
        groupBox_CompleteRate->setTitle(QString());
        label_TaskNumber->setText(QCoreApplication::translate("MainWindow", "Today finished/total", nullptr));
        groupBox_Time->setTitle(QString());
        label_Date->setText(QCoreApplication::translate("MainWindow", "YYYY/MM/DD", nullptr));
        label_Time->setText(QCoreApplication::translate("MainWindow", "HH/MM/SS", nullptr));
        groupBox_Buttons->setTitle(QString());
#if QT_CONFIG(tooltip)
        pushButton_CreateTask->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Add a new task</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_CreateTask->setText(QString());
#if QT_CONFIG(tooltip)
        pushButton_ViewRecord->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>View Records</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_ViewRecord->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
