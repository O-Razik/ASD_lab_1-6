#include "func_sort.h"
#include "func_app.h"
#include "qapplication.h"
#include "qdatetime.h"
#include "qprogressbar.h"

#include <QTextBrowser>
#include <QElapsedTimer>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

double sort(QString sort_name, std::vector<int> (*sort_type)(std::vector<int>, std::vector<QString> &),
            std::vector<int> array,
            std::vector<int>& res_array, QTextBrowser* log_box,
            QTextBrowser* res, QProgressBar* bar, bool do_log)
{
    std::vector<QString> log;
    bar->setValue(5);
    QApplication::processEvents();
    log_box->append(sort_name+":\n");

    bar->setValue(8);
    QApplication::processEvents();

    QTime start_time = QTime::currentTime(), end_time;
    QElapsedTimer timer;
    timer.start();
    log_box->append(" Start time: " + start_time.toString() + "\n");

    bar->setValue(10);
    QApplication::processEvents();

    bar->setValue(11);
    QApplication::processEvents();

    res_array = sort_type(array,log);

    bar->setValue(90);
    QApplication::processEvents();

    double time = static_cast<double>(timer.elapsed()) / 1000.0; // Time in seconds
    end_time = QTime::currentTime();

    if(do_log) pr_log(log,log_box);
    log_box->append(" End time: " + end_time.toString() + "\n");
    bar->setValue(95);
    QApplication::processEvents();

    res->setText("Sorted array: \n" + text_array(res_array));
    return time;

}

double sort(QString sort_name, std::vector<int> (*sort_type)(std::vector<int>, int, int, std::vector<QString>&),
             std::vector<int> array,
             std::vector<int>& res_array, QTextBrowser* log_box,
             QTextBrowser* res, QProgressBar* bar, bool do_log)
{
    std::vector<QString> log;
    bar->setValue(5);
    QApplication::processEvents();
    log_box->append(sort_name+":\n");

    bar->setValue(8);
    QApplication::processEvents();
    QTime start_time = QTime::currentTime(), end_time;
    QElapsedTimer timer;
    timer.start();
    log_box->append(" Start time: " + start_time.toString() + "\n");
    bar->setValue(10);
    QApplication::processEvents();

    res_array = sort_type(array, 0, array.size()-1, log);
    bar->setValue(80);
    QApplication::processEvents();

    double time = static_cast<double>(timer.elapsed()) / 1000.0; // Time in seconds
    end_time = QTime::currentTime();

    if(do_log) pr_log(log,log_box);
    log_box->append(" End time: " + end_time.toString() + "\n");
    bar->setValue(95);
    QApplication::processEvents();

    res->setText("Sorted array: \n" + text_array(res_array));
    return time;

}

std::vector<int> selection_sort(std::vector<int> array, std::vector<QString>& log)
{
    for (int i = 0; i < array.size()-1; i++) {
        int min = i, swap = array[i];
        for (int j = i + 1; j < array.size(); j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        array[i] = array[min];
        array[min] = swap;

        log_arr(array,0, array.size()-1,log);
    }

    return array;
}

std::vector<int> shell_sort(std::vector<int> array, std::vector<QString> &log)
{
    for (int h = array.size()/2; h >= 1; h/=2) {
        for (int i = h; i < array.size(); ++i) {
            for (int j = i; j >= h && array[j - h] > array[j]; j-=h) {
                std::swap(array[j-h], array[j]);
            }
            log_arr(array,0, array.size()-1,log);
        }
    }

    return array;
}

std::vector<int> quick_sort(std::vector<int> array, int left, int right , std::vector<QString>& log)
{


    if (left < right)
    {
        int pivot = array[left];
        int i = left + 1;
        int j = right;

        log_arr(array,left, right, log);

        while (i <= j)
        {
            while (i <= j && array[i] <= pivot) i++;
            while (i <= j && array[j] > pivot)  j--;

            if (i < j) std::swap(array[i], array[j]);
        }

        std::swap(array[left], array[j]);

        array = quick_sort(array, left, j - 1, log);

        array = quick_sort(array, j + 1, right, log);

        log_arr(array,left, right, log);
    }
    return array;
}

std::vector<int> merge_sort(std::vector<int> array, int left, int right, std::vector<QString> &log)
{

    log_arr(array,left, right, log);

    if (left >= right)
    {
        std::vector<int> single_element_array = {array[left]}; // Base case: return a single-element array
        return single_element_array;
    }

    int middle = left + (right - left) / 2; // Calculate the middle index correctly

    std::vector<int> left_half = merge_sort(array, left, middle, log);

    std::vector<int> right_half = merge_sort(array, middle + 1, right, log);

    std::vector<int> merge_array;
    int i = 0, j = 0;

    while (i < left_half.size() && j < right_half.size())
    {
        if (left_half[i] < right_half[j])
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

    log_arr(merge_array,0, merge_array.size()-1, log);

    return merge_array;
}

std::vector<int> counting_sort(std::vector<int> array, std::vector<QString>& log) {
    log_arr(array, 0, array.size() - 1, log);

    int max = array[0];
    for (int i = 0; i < array.size(); ++i)
        if (max < array[i]) max = array[i];

    std::vector<int> index_array(max + 1, 0);

    for (int i = 0; i < array.size(); ++i)
        index_array[array[i]]++;

    log_arr(index_array, 0, index_array.size() - 1, log);

    std::vector<int> sorted_arr;
    for (int i = 0; i <= max; ++i) {
        for (int j = 0; j < index_array[i]; ++j)
            sorted_arr.push_back(i);
    }

    log_arr(sorted_arr, 0, sorted_arr.size() - 1, log);

    return sorted_arr;
}
