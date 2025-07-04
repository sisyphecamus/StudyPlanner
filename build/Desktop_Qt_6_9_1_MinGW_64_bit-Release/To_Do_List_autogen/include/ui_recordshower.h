/********************************************************************************
** Form generated from reading UI file 'recordshower.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDSHOWER_H
#define UI_RECORDSHOWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordShower
{
public:
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget_Records;

    void setupUi(QWidget *RecordShower)
    {
        if (RecordShower->objectName().isEmpty())
            RecordShower->setObjectName("RecordShower");
        RecordShower->resize(480, 300);
        RecordShower->setMinimumSize(QSize(480, 300));
        horizontalLayout = new QHBoxLayout(RecordShower);
        horizontalLayout->setObjectName("horizontalLayout");
        treeWidget_Records = new QTreeWidget(RecordShower);
        treeWidget_Records->headerItem()->setText(1, QString());
        treeWidget_Records->setObjectName("treeWidget_Records");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget_Records->sizePolicy().hasHeightForWidth());
        treeWidget_Records->setSizePolicy(sizePolicy);
        treeWidget_Records->header()->setCascadingSectionResizes(false);
        treeWidget_Records->header()->setMinimumSectionSize(60);
        treeWidget_Records->header()->setDefaultSectionSize(300);
        treeWidget_Records->header()->setStretchLastSection(true);

        horizontalLayout->addWidget(treeWidget_Records);


        retranslateUi(RecordShower);

        QMetaObject::connectSlotsByName(RecordShower);
    } // setupUi

    void retranslateUi(QWidget *RecordShower)
    {
        RecordShower->setWindowTitle(QCoreApplication::translate("RecordShower", "Records", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_Records->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("RecordShower", "Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordShower: public Ui_RecordShower {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDSHOWER_H
