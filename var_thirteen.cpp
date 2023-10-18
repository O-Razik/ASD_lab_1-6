#include "var_thirteen.h"
#include "func_app.h"
#include "ui_var_thirteen.h"

var_thirteen::var_thirteen(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::var_thirteen)
{
    ui->setupUi(this);
}

var_thirteen::~var_thirteen()
{
    delete ui;
}

void var_thirteen::on_array_from_file_clicked()
{
    array = file_arr();
    ui->array_size_box->setValue(array.size());
    ui->array_box->setText(text_array(array));
}

std::vector<int> var_thirteen::rand_array_100(int length) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> new_array;
    for (int i = 0; i < length; ++i) {
        // random nums between -100 and 100
        int random_number = std::rand() % 201 - 100;
        new_array.push_back(random_number);
    }

    return new_array;
}

void var_thirteen::on_rand_array_button_clicked()
{
    array = rand_array_100(ui->array_size_box->value());
    ui->array_size_box->setValue(array.size());
    ui->array_box->setText(text_array(array));
}


void var_thirteen::on_change_button_clicked()
{
    ui->array_box->clear();

    std::vector<int> new_array;
    for (int i = 0; i < array.size(); ++i) {
        if(array[i]/3) new_array.push_back(array[i]*array[i]);
    }
    array = new_array;

    QString res;
    for (int j = 0; j < array.size(); j++)
        res += QString::number(array[j]) + " ";
    ui->array_box->setText(res);
    ui->array_size_box->setValue(array.size());
}


void var_thirteen::on_sort_button_clicked()
{
    ui->array_box->clear();

    array = merge_sort_decr(0, array.size()-1);

    QString res;
    for (int j = 0; j < array.size(); j++)
        res += QString::number(array[j]) + " ";
    ui->array_box->setText(res);
}

std::vector<int> var_thirteen::merge_sort_decr(int left, int right)
{
    if (left >= right)
    {
        std::vector<int> single_element_array = {array[left]}; // Base case: return a single-element array
        return single_element_array;
    }

    int middle = left + (right - left) / 2; // Calculate the middle index correctly

    std::vector<int> left_half = merge_sort_decr(left, middle);
    std::vector<int> right_half = merge_sort_decr(middle + 1, right);

    std::vector<int> merge_array;
    int i = 0, j = 0;

    while (i < left_half.size() && j < right_half.size())
    {
        if (left_half[i] > right_half[j])
        {
            merge_array.push_back(left_half[i]);
            i++;
        }
        else
        {
            merge_array.push_back(right_half[j]);
            j++;
        }
    }

    // Append any remaining elements from left_half and right_half
    while (i < left_half.size())
    {
        merge_array.push_back(left_half[i]);
        i++;
    }

    while (j < right_half.size())
    {
        merge_array.push_back(right_half[j]);
        j++;
    }

    return merge_array;
}
