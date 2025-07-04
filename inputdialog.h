#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include "backend/include/Task.h"
namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = nullptr);
    ~InputDialog();

    void setCreateUI();
    void setEditUI(Task &t);

    QString getTitle() const;
    QString getContent() const;
    int getPriority() const;
    bool getNeedsReview() const;
    QDateTime getDeadLine() const;

private:
    Ui::InputDialog *ui;

};

#endif // INPUTDIALOG_H
