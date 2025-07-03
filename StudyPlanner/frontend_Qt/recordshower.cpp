#include "recordshower.h"
#include "ui_recordshower.h"

RecordShower::RecordShower(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecordShower)
{
    ui->setupUi(this);
}

RecordShower::~RecordShower()
{
    delete ui;
}

void RecordShower::showRecords(const RecordManager &backend)
{
    ui->treeWidget_Records->clear();
    ui->treeWidget_Records->setHeaderLabels(QStringList() << "日期/记录");

    for (const auto& [dateStr, dateEntry] : backend.date_entries) {
        QTreeWidgetItem* dateItem = new QTreeWidgetItem(ui->treeWidget_Records);
        dateItem->setText(0, QString::fromStdString(dateStr));
        for (const auto& [recordId, record] : dateEntry.records) {
            QTreeWidgetItem* recordItem = new QTreeWidgetItem(dateItem);
            recordItem->setText(0, QString("ID:%1 %2").arg(recordId).arg(QString::fromStdString(record.getTitle())));
        }
    }
}
