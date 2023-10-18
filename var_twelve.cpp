#include "var_twelve.h"
#include "func_app.h"
#include "ui_var_twelve.h"

var_twelve::var_twelve(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::var_twelve)
{
    ui->setupUi(this);
}

var_twelve::~var_twelve()
{
    delete ui;
}

void var_twelve::on_array_from_file_clicked()
{
    array = file_arr();
    ui->array_size_box->setValue(array.size());
    ui->array_box->setText(text_array(array));
}


void var_twelve::on_rand_array_button_clicked()
{
    array = rand_array(ui->array_size_box->value());
    ui->array_size_box->setValue(array.size());
    ui->array_box->setText(text_array(array));
}

std::vector<int> var_twelve::quick_sort_decr(int left, int right){
    if (left < right) {
        int pivot = array[left];
        int i = left + 1;
        int j = right;

        while (i <= j) {
            while (i <= j && array[i] >= pivot) i++;
            while (i <= j && array[j] < pivot)  j--;

            if (i < j) std::swap(array[i], array[j]);
        }

        std::swap(array[left], array[j]);

        quick_sort_decr(left, j - 1);
        quick_sort_decr(j + 1, right);
    }
    return array;
}

void var_twelve::on_sort_button_clicked()
{
    ui->array_box->clear();
    int max = 0;
    for (int i = 0; i < array.size(); ++i) {
        if(array[i]>array[max]) max = i;
    }

    array = quick_sort_decr(max+1, array.size()-1);

    QString res;
    for (int j = 0; j < array.size(); j++){
        if (j == max)
            res += "[" + QString::number(array[j]) + "] ";
        else
            res += QString::number(array[j]) + " ";
    }
    ui->array_box->setText(res);
}

