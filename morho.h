#ifndef MORHO_H
#define MORHO_H

#include <QMainWindow>
#include <math.h>
#include <QFileDialog>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class Morho; }
QT_END_NAMESPACE

class Morho : public QMainWindow
{
    Q_OBJECT

public:
    Morho(QWidget *parent = nullptr);
    ~Morho();

private slots:
    void on_generate_combination_clicked();

    void on_check_path_directory_clicked();

    void on_check_write_file_clicked(bool checked);

    void on_number_sign_valueChanged(int arg1);

    void on_number_realisation_valueChanged(int arg1);

    void on_list_combination_textChanged();

    void on_open_file_directory_clicked();

private:
    Ui::Morho *ui;
};
#endif // MORHO_H
