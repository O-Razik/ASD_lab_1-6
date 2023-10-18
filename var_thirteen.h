#ifndef VAR_THIRTEEN_H
#define VAR_THIRTEEN_H

#include <QDockWidget>

namespace Ui {
class var_thirteen;
}

class var_thirteen : public QDockWidget
{
    Q_OBJECT

public:
    explicit var_thirteen(QWidget *parent = nullptr);
    ~var_thirteen();

private slots:
    void on_array_from_file_clicked();

    void on_rand_array_button_clicked();

    void on_change_button_clicked();

    void on_sort_button_clicked();

    std::vector<int> merge_sort_decr(int left, int right);
    std::vector<int> rand_array_100(int length);

private:
    Ui::var_thirteen *ui;
    std::vector<int> array;
};

#endif // VAR_THIRTEEN_H
