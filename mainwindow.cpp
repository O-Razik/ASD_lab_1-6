#include "mainwindow.h"
#include "func_app.h"
#include "ui_mainwindow.h"
#include "var_eleven.h"
#include "var_fourteen.h"
#include "var_ten.h"
#include "func_sort.h"
#include "var_thirteen.h"
#include "var_twelve.h"

#include <QFile>
#include <QDir>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ALLSort)
{
    ui->setupUi(this);
    ui->progressBar->setVisible(false);
    ui->counting_sort->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_arr(std::vector<int> other_array){
    array = other_array;
    ui->array_size_box->setValue(array.size());
    ui->array_show->setText(text_array(array));
}

void MainWindow::on_tack_var10_clicked()
{
    // Create an instance of the "var_ten" window
    var_ten *varTen = new var_ten;

    // Show the "var_ten" window
    varTen->show();

    close();
}


void MainWindow::on_array_from_file_clicked()
{
    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);
    ui->progressBar->setVisible(true);
    ui->counting_sort->setDisabled(true);

    ui->step_log->setTextColor(QColorConstants::Black);

    array = file_arr();

    ui->progressBar->setValue(30);
    QApplication::processEvents();

    ui->array_size_box->setValue(array.size());

    ui->progressBar->setValue(60);
    QApplication::processEvents();

    ui->array_show->setText(text_array(array));
    if(check_IsCount_Able(array)) ui->counting_sort->setDisabled(false);

    ui->progressBar->setValue(100);
    QApplication::processEvents();

    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);

}

void MainWindow::on_rand_array_button_clicked()
{
    ui->sort_time->clear();

    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);
    ui->progressBar->setVisible(true);

    ui->step_log->setTextColor(QColorConstants::Black);

    if(range)
    {
        array = rand_array(ui->array_size_box->value());
        ui->counting_sort->setDisabled(true);
    }
    else
    {
        array = rand_array_pos(ui->array_size_box->value());
        ui->counting_sort->setDisabled(false);
    }
    ui->progressBar->setValue(50);
    QApplication::processEvents();

    ui->array_show->setText(text_array(array));

    ui->progressBar->setValue(100);
    QApplication::processEvents();

    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}


void MainWindow::on_selection_sort_clicked()
{
    if(array.empty())
    {
        ui->step_log->setTextColor(QColorConstants::Red);
        ui->step_log->setText("Array is empty! Create array!");
        return;
    }

    ui->step_log->clear();
    ui->sort_time->clear();
    ui->progressBar->setVisible(true);
    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);

    std::vector<int> unsort = array;

    ui->progressBar->setValue(1);
    QApplication::processEvents();

    ui->check_sort->setStyleSheet("background-color: light grey;");
    double timeDouble = 0;

    ui->progressBar->setValue(2);
    QApplication::processEvents();

    timeDouble =
        sort("Selection sort", selection_sort, array, result_array,ui->step_log, ui->sorted_array, ui->progressBar, do_log);
    array = unsort;

    ui->progressBar->setValue(99);
    QApplication::processEvents();

    ui->sort_time->setText(QString::number(timeDouble, 'f', 30) + " s");

    ui->progressBar->setValue(100);
    QApplication::processEvents();
    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}

void MainWindow::on_check_sort_clicked()
{
    if(array.empty())
    {
        ui->step_log->setTextColor(QColorConstants::Red);
        ui->step_log->setText("Array is empty! Create array!");
        return;
    }

    ui->progressBar->setVisible(true);
    if(result_array.empty())
        ui->check_sort->setStyleSheet("background-color: grey;");
    else
    {
        for (int i = 1; i < result_array.size(); i++)
        {
            if(result_array[0]>result_array[i])
            {
                ui->check_sort->setStyleSheet("background-color: red;");
                return;
            }
        }
        ui->check_sort->setStyleSheet("background-color: green;");
    }
    ui->progressBar->setValue(100);
    QApplication::processEvents();
    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}

void MainWindow::on_shell_sort_clicked()
{
    if(array.empty())
    {
        ui->step_log->setTextColor(QColorConstants::Red);
        ui->step_log->setText("Array is empty! Create array!");
        return;
    }

    ui->step_log->clear();
    ui->sort_time->clear();
    ui->progressBar->setVisible(true);
    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);

    std::vector<int> unsort = array;
    ui->check_sort->setStyleSheet("background-color: light grey;");
    double timeDouble = 0;

    ui->progressBar->setValue(1);
    QApplication::processEvents();

    timeDouble =
        sort("Shell sort", shell_sort, array, result_array,
             ui->step_log, ui->sorted_array, ui->progressBar, do_log);
        array = unsort;

    ui->progressBar->setValue(99);
    QApplication::processEvents();

    ui->sort_time->setText(QString::number(timeDouble, 'f', 30) + " s");
    //ui->shell_sort->setDisabled(true);

    ui->progressBar->setValue(100);
    QApplication::processEvents();
    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}


void MainWindow::on_tack_var11_clicked()
{
    var_eleven *varElev = new var_eleven;
    varElev->show();
}


void MainWindow::on_quick_sort_clicked()
{
    if(array.empty())
    {
        ui->step_log->setTextColor(QColorConstants::Red);
        ui->step_log->setText("Array is empty! Create array!");
        return;
    }

    ui->step_log->clear();
    ui->sort_time->clear();
    ui->progressBar->setVisible(true);
    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);

    std::vector<int> unsort = array;
    ui->check_sort->setStyleSheet("background-color: light grey;");
    double timeDouble = 0;

    ui->progressBar->setValue(1);
    QApplication::processEvents();

    timeDouble =
        sort("Quick sort",quick_sort,array, result_array,
             ui->step_log, ui->sorted_array, ui->progressBar, do_log);
    array = unsort;
    ui->sort_time->setText(QString::number(timeDouble, 'f', 30) + " s");
    //ui->shell_sort->setDisabled(true);

    ui->progressBar->setValue(100);
    QApplication::processEvents();
    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}


void MainWindow::on_log_check_clicked()
{
    do_log = !do_log;
}


void MainWindow::on_tack_var12_clicked()
{
    var_twelve *varTwl = new var_twelve;
    varTwl->show();
}


void MainWindow::on_merge_sort_clicked()
{
    if(array.empty())
    {
        ui->step_log->setTextColor(QColorConstants::Red);
        ui->step_log->setText("Array is empty! Create array!");
        return;
    }

    ui->step_log->clear();
    ui->sort_time->clear();
    ui->progressBar->setVisible(true);
    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);

    std::vector<int> unsort = array;
    ui->check_sort->setStyleSheet("background-color: light grey;");
    double timeDouble = 0;

    ui->progressBar->setValue(1);
    QApplication::processEvents();

    timeDouble =
        sort("Merge sort",merge_sort,array, result_array,
             ui->step_log, ui->sorted_array, ui->progressBar, do_log);
    array = unsort;
    ui->sort_time->setText(QString::number(timeDouble, 'f', 30) + " s");
    //ui->shell_sort->setDisabled(true);

    ui->progressBar->setValue(100);
    QApplication::processEvents();
    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}


void MainWindow::on_tack_var13_clicked()
{
    var_thirteen *varThrt = new var_thirteen;
    varThrt->show();
}


void MainWindow::on_random_range_clicked()
{
    range ? ui->random_range->setText("+") : ui->random_range->setText("±");
    range = !range;
}


void MainWindow::on_counting_sort_clicked()
{
    if(array.empty())
    {
        ui->step_log->setTextColor(QColorConstants::Red);
        ui->step_log->setText("Array is empty! Create array!");
        return;
    }

    ui->step_log->clear();
    ui->sort_time->clear();
    ui->progressBar->setVisible(true);
    ui->sort_time->setVisible(false);
    ui->time_label->setVisible(false);

    ui->check_sort->setStyleSheet("background-color: light grey;");
    double timeDouble = 0;

    ui->progressBar->setValue(1);
    QApplication::processEvents();

    timeDouble =
        sort("Counting sort",counting_sort,array, result_array,
             ui->step_log, ui->sorted_array, ui->progressBar, do_log);
    ui->sort_time->setText(QString::number(timeDouble, 'f', 30) + " s");
    //ui->shell_sort->setDisabled(true);

    ui->progressBar->setValue(100);
    QApplication::processEvents();
    ui->sort_time->setVisible(true);
    ui->time_label->setVisible(true);
    ui->progressBar->setVisible(false);
}


void MainWindow::on_tack_var14_clicked()
{
    var_fourteen *varFrtn = new var_fourteen;
    varFrtn->show();
}

