#ifndef VAR_FOURTEEN_H
#define VAR_FOURTEEN_H

#include <QDockWidget>

namespace Ui {
class var_fourteen;
}

class var_fourteen : public QDockWidget
{
    Q_OBJECT

public:
    explicit var_fourteen(QWidget *parent = nullptr);
    ~var_fourteen();

private slots:
    void on_file_array_clicked();

    void on_sort_button_clicked();

    void sort(std::vector<QString>& city_list);

private:
    Ui::var_fourteen *ui;
    std::vector<QString> city_list;
};

#endif // VAR_FOURTEEN_H
