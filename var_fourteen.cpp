#include "var_fourteen.h"
#include "func_app.h"
#include "ui_var_fourteen.h"

#include <algorithm>


var_fourteen::var_fourteen(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::var_fourteen)
{
    ui->setupUi(this);
}

var_fourteen::~var_fourteen()
{
    delete ui;
}

void var_fourteen::on_file_array_clicked()
{
    ui->city_list_box->clear();
    city_list = file_arr_str();
    for (int i = 0; i < city_list.size(); ++i) {
        ui->city_list_box->append(city_list[i]);
    }
}


void var_fourteen::on_sort_button_clicked()
{
    std::vector<QString> sorted_cities;
    for (int i = 0; i < city_list.size(); ++i)
        if(city_list[i].size() <= 8) sorted_cities.push_back(city_list[i]);

    sort(sorted_cities);

    ui->sorted_list->clear();
    for (int i = 0; i < sorted_cities.size(); ++i)
        ui->sorted_list->append(sorted_cities[i]);
}

void var_fourteen::sort(std::vector<QString>& city_list) {
    for (int i = 0; i < city_list.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < city_list.size(); j++) {
            if (city_list[j].compare(city_list[min], Qt::CaseInsensitive) < 0) {
                min = j;
            }
        }

        if (min != i) {
            std::swap(city_list[i], city_list[min]);
        }
    }
}

