#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QTextBrowser>
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class ALLSort; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void set_arr(std::vector<int>);

private slots:
    void on_tack_var10_clicked();

    void on_array_from_file_clicked();

    void on_rand_array_button_clicked();

    void on_selection_sort_clicked();

    void on_check_sort_clicked();

    void on_shell_sort_clicked();

    void on_tack_var11_clicked();

    void on_quick_sort_clicked();

    void on_log_check_clicked();

    void on_tack_var12_clicked();

    void on_merge_sort_clicked();

    void on_tack_var13_clicked();

    void on_random_range_clicked();

    void on_counting_sort_clicked();

    void on_tack_var14_clicked();

private:
    Ui::ALLSort *ui;

    bool do_log = true;
    bool range = true;
    std::vector<int> array, result_array;

};
#endif // MAINWINDOW_H
