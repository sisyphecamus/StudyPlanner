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

void RecordShower::showRecords(const RecordManager &RM)
{
    ui->treeWidget_Records->clear();
    ui->treeWidget_Records->setHeaderLabels(QStringList() << "Records" << "");

    for (const auto& [dateStr, dateEntry] : RM.date_entries)
    {
        QTreeWidgetItem* dateItem = new QTreeWidgetItem(ui->treeWidget_Records);
        dateItem->setText(0, QString::fromStdString(dateStr));
        dateItem->setFirstColumnSpanned(true);
        for (const auto& [recordId, record] : dateEntry.records)
        {
            QTreeWidgetItem* recordItem = new QTreeWidgetItem(dateItem);

            recordItem->setText(0, QString::fromStdString(record.getTitle()));
            recordItem->setText(1, QString::fromStdString(record.getCompletedStats() ? "Complete" : "Overdue"));
        }
    }
}
