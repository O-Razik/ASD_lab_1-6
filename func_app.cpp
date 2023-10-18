#include"func_app.h"
#include "qspinbox.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>

void pr_arr_step(std::vector<int>& array, QTextBrowser* text_brow, int step){
    QString Log;
    Log += "    step " + QString::number(step) + ": ";
    for (int j = 0; j < array.size(); j++)
        Log += QString::number(array[j]) + " ";

    text_brow->append(Log + "\n");
}

void pr_arr_step(std::vector<int>& array, int first_index, int last_index, QTextBrowser* text_brow, int step){
    QString Log;
    Log += "    step " + QString::number(step) + ": ";
    for (int j = first_index; j <= last_index; j++)
        Log += QString::number(array[j]) + " ";

    text_brow->append(Log);
}

void pr_arr(std::vector<int>& array, int first_index, int last_index, QTextBrowser* text_brow){
    QString Log = "        ";
    for (int j = first_index; j <= last_index; j++)
        Log += QString::number(array[j]) + " ";

    text_brow->append("        "+Log + "\n");
}

void log_arr(std::vector<int>& array, int first_index, int last_index, std::vector<QString>& log){
    QString Log;

    for (int j = first_index; j <= last_index; j++)
        Log += QString::number(array[j]) + " ";

    log.push_back(Log);
}

void pr_log(std::vector<QString>& log, QTextBrowser* text_brow){
    for (int i = 0; i < log.size(); i++)
        text_brow->append("step "+ QString::number(i+1) + ":  "+log[i] + "\n");
}

QString text_array(std::vector<int> array){
    QString arrayText;
    for (int i = 0; i < array.size(); ++i) {
        arrayText += QString::number(array[i]) + " ";
    }
    return arrayText;
}

QString text_array(std::vector<int> array, int i){
    QString arrayText;
    arrayText += "Array "+QString::number(i)+": ";
    for (int j = 0; j < array.size(); ++j) {
        arrayText += QString::number(array[j]) + " ";
    }
    return arrayText;
}

std::vector<int> rand_array(int length) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> new_array;
    for (int i = 0; i < length; ++i) {
        // random nums between -1000 and 1000
        int random_number = std::rand() % 2001 - 1000;
        new_array.push_back(random_number);
    }

    return new_array;
}

std::vector<int> rand_array_pos(int length) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> new_array;
    for (int i = 0; i < length; ++i) {
        // random nums between 0 and 1000
        int random_number = std::rand() % 1001;
        new_array.push_back(random_number);
    }

    return new_array;
}

std::vector<double> rand_arr2(int length, int x) {
    std::vector<double> new_array;
    for (int i = 0; i < length; ++i) {
        double random_number = static_cast<double>(std::rand() % 31 - 20);
        for (int j = 0; j < x; ++j)
            random_number *= random_number; // Squaring the number
        // Set precision to 6 decimal places
        new_array.push_back(std::round(random_number) / 100);
    }

    return new_array;
}

std::vector<int> comb_arrays(const std::vector<int>& first_array, const std::vector<int>& second_array)
{
    std::vector<int> new_array;

    // Copy even numbers from first_array
    for (int num : first_array) {
        if (num % 2 == 0) {
            new_array.push_back(num);
        }
    }

    // Copy odd numbers from second_array
    for (int num : second_array) {
        if (num % 2 != 0) {
            new_array.push_back(num);
        }
    }

    return new_array;
}


std::vector<int> file_arr() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", QDir::homePath(), "Text Files (*.txt);;All Files (*)");
    std::vector<int> dataArray;

    // Check if the user canceled file selection
    if (filePath.isEmpty()) {
        qDebug() << "File selection canceled.";
        return dataArray;
    }

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ", Qt::SkipEmptyParts); // Split the line by spaces

            for (const QString& part : parts) {
                bool conversionOk = false;
                int value = part.toInt(&conversionOk);

                if (conversionOk) {
                    dataArray.push_back(value);
                } else {
                    // Debugging: Print an error message if conversion fails
                    qDebug() << "Error converting part to integer: " << part;
                }
            }
        }

        file.close();
    } else {
        // Debugging: Print an error message if the file fails to open
        qDebug() << "Failed to open the file for reading: " << file.errorString();
    }

    return dataArray;
}

std::vector<std::vector<double>> file_arr2() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", QDir::homePath(), "Text Files (*.txt);;All Files (*)");
    std::vector<std::vector<double>> dataArray(2);  // Initialize a 2xN vector

    // Check if the user canceled file selection
    if (filePath.isEmpty()) {
        qDebug() << "File selection canceled.";
        return dataArray;
    }

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        int currentRow = 0;  // To keep track of which row we're filling

        while (!in.atEnd() && currentRow < 2) {
            QString line = in.readLine();
            QStringList parts = line.split(" ", Qt::SkipEmptyParts); // Split the line by spaces

            for (const QString& part : parts) {
                bool conversionOk = false;
                int value = part.toInt(&conversionOk);

                if (conversionOk) {
                    dataArray[currentRow].push_back(value);
                } else {
                    // Debugging: Print an error message if conversion fails
                    qDebug() << "Error converting part to integer: " << part;
                }
            }

            currentRow++;
        }

        file.close();
    } else {
        // Debugging: Print an error message if the file fails to open
        qDebug() << "Failed to open the file for reading: " << file.errorString();
    }

    return dataArray;
}

std::vector<QString> file_arr_str() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", QDir::homePath(), "Text Files (*.txt);;All Files (*)");
    std::vector<QString> stringArray;

    // Check if the user canceled file selection
    if (filePath.isEmpty()) {
        qDebug() << "File selection canceled.";
        return stringArray;
    }

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine();
            stringArray.push_back(line);
        }

        file.close();
    } else {
        // Debugging: Print an error message if the file fails to open
        qDebug() << "Failed to open the file for reading: " << file.errorString();
    }

    return stringArray;
}


void create_table(std::vector<std::vector<double>> arr2, QTableView* table, QStandardItemModel* mode, QSpinBox* n){
    if (mode) {
        arr2.clear();
        table->setModel(nullptr);
        delete mode;
        mode = nullptr;
    }

    mode = new QStandardItemModel(2, n->value());
    for (int row = 0; row < mode->rowCount(); ++row) {
        for (int column = 0; column < mode->columnCount(); ++column) {
            QStandardItem *item = new QStandardItem(QString::number(arr2[row][column], 'f', 6));
            mode->setItem(row, column, item);
        }
    }

    table->setModel(mode);
    table->show();

}

std::vector<int> merge_arrays(const std::vector<int>& first_array, const std::vector<int>& second_array)
{
    std::vector<int> new_array;
    for (int num : first_array) new_array.push_back(num);
    for (int num : second_array) new_array.push_back(num);

    return new_array;
}

bool check_IsCount_Able(std::vector<int> array){
    for (int i = 0; i < array.size(); ++i) {
        if(array[i]<0) return false;
    }
    return true;
}
