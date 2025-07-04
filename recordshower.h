#ifndef RECORDSHOWER_H
#define RECORDSHOWER_H

#include <QWidget>
#include "backend/include/RecordManager.h"
#include "backend/include/TaskManager.h"
namespace Ui {
class RecordShower;
}

class RecordShower : public QWidget
{
    Q_OBJECT

public:
    explicit RecordShower(QWidget *parent = nullptr);
    ~RecordShower();

    void showRecords(const RecordManager& backend);
private:
    Ui::RecordShower *ui;
};

#endif // RECORDSHOWER_H
