#ifndef FUNC_SORT_H
#define FUNC_SORT_H

#include "qprogressbar.h"
#include <iostream>
#include <vector>
#include <QTextBrowser>

double sort(QString sort_name, std::vector<int> (*sort_type)(std::vector<int>, std::vector<QString>&),
            std::vector<int> array, std::vector<int>& res_array,
            QTextBrowser* log_box, QTextBrowser* res, QProgressBar* bar, bool do_log);

double sort(QString sort_name, std::vector<int> (*sort_type)(std::vector<int>, int, int, std::vector<QString> &),
            std::vector<int> array, std::vector<int>& res_array, QTextBrowser *log_box, QTextBrowser* res, QProgressBar* bar, bool do_log);

std::vector<int> selection_sort(std::vector<int> array, std::vector<QString> &log);

std::vector<int> shell_sort(std::vector<int> array, std::vector<QString>& log);

std::vector<int> quick_sort(std::vector<int> array, int left, int right, std::vector<QString> &log);

std::vector<int> merge_sort(std::vector<int> array, int left, int right , std::vector<QString>& log);

std::vector<int> counting_sort(std::vector<int> array, std::vector<QString> &log);

#endif // FUNC_SORT_H
