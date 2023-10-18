#ifndef VAR_ELEVEN_H
#define VAR_ELEVEN_H

#include "qstandarditemmodel.h"
#include <QDockWidget>

namespace Ui {
class var_eleven;
}

class var_eleven : public QDockWidget
{
    Q_OBJECT
public:
    explicit var_eleven(QWidget *parent = nullptr);
    ~var_eleven();
private slots:
    void on_rand_table_clicked();

    void on_file_array_clicked();

    void on_cube_root_max_clicked();

    void on_Shell_sort_Button_clicked();

private:
    Ui::var_eleven *ui;
    std::vector<std::vector<double>> table;
    QStandardItemModel* model = nullptr;
};

#endif // VAR_ELEVEN_H
