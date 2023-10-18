#ifndef FUNC_APP_H
#define FUNC_APP_H

#include "qspinbox.h"
#include "qstandarditemmodel.h"
#include "qtableview.h"

#include <QString>
#include <QTextBrowser>
#include <iostream>
#include <vector>

QString text_array(std::vector<int> array);
QString text_array(std::vector<int> array, int i);

std::vector<int> rand_array(int lenght);
std::vector<double> rand_arr2(int length, int x);
std::vector<int> rand_array_pos(int length);

std::vector<int> comb_arrays
    (const std::vector<int>& first_array,
     const std::vector<int>& second_array);
std::vector<int> merge_arrays(const std::vector<int>& first_array,
                              const std::vector<int>& second_array);

void pr_arr_step(std::vector<int>& array, QTextBrowser* text_brow, int step);
void pr_arr_step(std::vector<int>& array, int first_index, int last_index, QTextBrowser* text_brow, int step);
void pr_arr(std::vector<int>& array, int first_index, int last_index, QTextBrowser* text_brow);

void log_arr(std::vector<int>& array, int first_index, int last_index, std::vector<QString>& log);
void pr_log(std::vector<QString>& log, QTextBrowser *text_brow);

std::vector<int> file_arr();
std::vector<std::vector<double>> file_arr2();
std::vector<QString> file_arr_str();

void create_table(std::vector<std::vector<double>>, QTableView* table,
                  QStandardItemModel* mode, QSpinBox *n);

bool check_IsCount_Able(std::vector<int> array);

#endif // FUNC_APP_H
