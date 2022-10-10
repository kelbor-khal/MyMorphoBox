#include "morho.h"
#include "ui_morho.h"

Morho::Morho(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Morho)
{
    ui->setupUi(this);
}

Morho::~Morho()
{
    delete ui;
}

// генерация комбинаций
void Morho::on_generate_combination_clicked()
{
    bool status_cmp_no_origin=false;
    // выгрузка данных
    int number_realisation_data = ui->number_realisation->value();
    int value_combination = ui->nymber_show_combination->value();

    // создание массива
    QString tranzit;
    QString array_combo [value_combination];
    // очистка текстового поля
    ui->list_combination->clear();
    // создание файла для записи
    std::string name_file = "/morphologBox.txt";
    std::string path_to_file = (ui->path_directory->text()).toUtf8().constData()+name_file;
    // генерация
    for(int i =0; i<value_combination; i++) {
        for(int j=0; j<number_realisation_data;j++) {
            char base_symbol = '@'+1+j;
            tranzit += base_symbol + QString::number(rand()%number_realisation_data+1)+ ',';
        }
        // генерация строки
        for(int j=0; j<value_combination; j++)
            if (tranzit == array_combo[j])
                status_cmp_no_origin=true;
        // проверка на повторение
        if(status_cmp_no_origin) {
            status_cmp_no_origin = false;
            i-=1;
        }
        else {
            QString number_combo;
            number_combo += '['+QString::number(i)+"] ";
            ui->list_combination->setTextColor( QColor( "red" ) );
            ui->list_combination->insertPlainText(number_combo);
            ui->list_combination->setTextColor( QColor( "blue" ) );
            ui->list_combination->insertPlainText(tranzit);
            ui->list_combination->insertPlainText("\n");(ui->path_directory->text()).toUtf8().constData();
            array_combo[i]=tranzit;
        }
        tranzit.clear();
        }
    if(ui->check_write_file->isChecked()) {
        std::ofstream outputFile (path_to_file);
        if(outputFile.is_open()){
           outputFile << "Combination MorphBox\n";
           for(int i=0;i<value_combination;i++)
                outputFile <<'['<<i<<"] "<<array_combo[i].toUtf8().constData()
                                         <<std::endl;
        }
        outputFile.close();
    }
}
// поиск директории для файла с комбинациями
void Morho::on_check_path_directory_clicked()
{

}
// проверка на запись в файл
void Morho::on_check_write_file_clicked(bool checked)
{
    if(checked) {
        ui->path_directory -> setDisabled(0);
        ui->open_file_directory->setDisabled(0);
    }
    else {
        ui->path_directory -> setDisabled(1);
        ui->open_file_directory->setDisabled(1);
    }
}
// изменение количества признаков
void Morho::on_number_sign_valueChanged(int arg1)
{
    int value_realistion = ui->number_realisation->value();
    ui->number_combination->setText(QString::number(pow(value_realistion,arg1)));
    ui->nymber_show_combination->setValue(pow(value_realistion,arg1));
}
// изменение количества реализаций
void Morho::on_number_realisation_valueChanged(int arg1)
{
    int value_sign = ui->number_sign->value();
    ui->number_combination->setText(QString::number(pow(arg1,value_sign)));
    ui->nymber_show_combination->setValue(pow(arg1,value_sign));
}
// сдвиг курсора на новое сообщение
void Morho::on_list_combination_textChanged()
{
    QTextCursor cursor = ui->list_combination->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->list_combination->setTextCursor(cursor);
}
// выбор директории хранения файла
void Morho::on_open_file_directory_clicked()
{
    QString str;
    str=QFileDialog::getExistingDirectory(this,tr("Open Directory"),"/home");
    ui->path_directory->setText(str);
}
