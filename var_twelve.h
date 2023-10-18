#ifndef VAR_TWELVE_H
#define VAR_TWELVE_H

#include <QDockWidget>

namespace Ui {
class var_twelve;
}

class var_twelve : public QDockWidget
{
    Q_OBJECT

public:
    explicit var_twelve(QWidget *parent = nullptr);
    ~var_twelve();

private slots:
    void on_array_from_file_clicked();

    void on_rand_array_button_clicked();

    void on_sort_button_clicked();

    std::vector<int> quick_sort_decr(int left, int right);
private:
    Ui::var_twelve *ui;
    std::vector<int> array;
};

#endif // VAR_TWELVE_H
