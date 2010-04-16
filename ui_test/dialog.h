#include "ui_dialog.h"

class DialogForm : public QDialog
{
    Q_OBJECT

public:
    DialogForm();

private slots:
    void say_hello();

private:
    Ui::Dialog ui;

};
