#ifndef VAR_TEN_H
#define VAR_TEN_H

#include <QDockWidget>

namespace Ui {
class var_ten;
}

class var_ten : public QDockWidget
{
    Q_OBJECT

public:
    explicit var_ten(QWidget *parent = nullptr);
    ~var_ten();

private slots:
    void on_file_array_one_clicked();

    void on_rand_arr1_clicked();

    void on_file_array_two_clicked();

    void on_rand_arr2_clicked();

    void on_comb_arrs_clicked();

    void on_put_to_main_arr_clicked();

private:
    Ui::var_ten *ui;
    std::vector<int> first_array, second_array, res_array;
};

#endif // VAR_TEN_H
