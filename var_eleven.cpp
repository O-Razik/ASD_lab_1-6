#include "var_eleven.h"
#include "func_app.h"
#include "ui_var_eleven.h"
#include <QStandardItemModel>

var_eleven::var_eleven(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::var_eleven)
{
    ui->setupUi(this);
}

var_eleven::~var_eleven()
{
    delete ui;
}

void var_eleven::on_rand_table_clicked()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    table.push_back(rand_arr2(ui->arr_n->value(),3));
    table.push_back(rand_arr2(ui->arr_n->value(),3));

    create_table(table, ui->tableView, model,ui->arr_n);
}



void var_eleven::on_file_array_clicked()
{
    table = file_arr2();
    ui->arr_n->setValue((int)table[0].size());
    create_table(table, ui->tableView, model,ui->arr_n);
}


void var_eleven::on_cube_root_max_clicked()
{
    for (int i = 0; i < 2; ++i) {
        int max = 0;
        for (int j = 1; j < table[i].size(); ++j) {
            if(table[i][max]<table[i][j]) max=j;
        }
        table[i][max] = std::cbrt(table[i][max]);
    }
    create_table(table, ui->tableView, model,ui->arr_n);
}

void var_eleven::on_Shell_sort_Button_clicked()
{
    for (int k = 0; k < 2; ++k){
        for (int i = 0; i < table[k].size()-1; i++) {
            int min = i;
            for (int j = i + 1; j < table[k].size(); j++) {
                if (table[k][j] < table[k][min]) {
                    min = j;
                }
            }
            std::swap(table[k][i],table[k][min]);
        }
    }

    create_table(table, ui->tableView, model,ui->arr_n);
}

