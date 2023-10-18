#include "var_ten.h"
#include "func_app.h"
#include "mainwindow.h"
#include "ui_var_ten.h"

var_ten::var_ten(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::var_ten)
{
    ui->setupUi(this);
}

var_ten::~var_ten()
{
    delete ui;
}

void var_ten::on_file_array_one_clicked()
{
    first_array = file_arr();
    ui->arr1_size->setValue(first_array.size());
    ui->array_one->setText(text_array(first_array));
}


void var_ten::on_rand_arr1_clicked()
{
    first_array = rand_array(ui->arr1_size->value());
    ui->arr1_size->setValue(first_array.size());
    ui->array_one->setText(text_array(first_array));
}


void var_ten::on_file_array_two_clicked()
{
    second_array = file_arr();
    ui->arr2_size->setValue(second_array.size());
    ui->array_two->setText(text_array(second_array));
}


void var_ten::on_rand_arr2_clicked()
{
    second_array = rand_array(ui->arr2_size->value());
    ui->arr2_size->setValue(second_array.size());
    ui->array_two->setText(text_array(second_array));
}


void var_ten::on_comb_arrs_clicked()
{
    res_array = comb_arrays(first_array, second_array);
    ui->array_result_box->setText(text_array(res_array));

}


void var_ten::on_put_to_main_arr_clicked()
{
    MainWindow *new_window = new MainWindow;
    new_window->set_arr(res_array);
    new_window->show();
    close();
}

