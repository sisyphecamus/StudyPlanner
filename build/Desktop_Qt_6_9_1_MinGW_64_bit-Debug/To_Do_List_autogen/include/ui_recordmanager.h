/********************************************************************************
** Form generated from reading UI file 'recordmanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDMANAGER_H
#define UI_RECORDMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordManager
{
public:
    QTreeWidget *treeWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *RecordManager)
    {
        if (RecordManager->objectName().isEmpty())
            RecordManager->setObjectName("RecordManager");
        RecordManager->resize(511, 379);
        treeWidget = new QTreeWidget(RecordManager);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(90, 30, 256, 192));
        pushButton = new QPushButton(RecordManager);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 280, 81, 24));

        retranslateUi(RecordManager);

        QMetaObject::connectSlotsByName(RecordManager);
    } // setupUi

    void retranslateUi(QWidget *RecordManager)
    {
        RecordManager->setWindowTitle(QCoreApplication::translate("RecordManager", "Records", nullptr));
        pushButton->setText(QCoreApplication::translate("RecordManager", "CreateEntry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordManager: public Ui_RecordManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDMANAGER_H
