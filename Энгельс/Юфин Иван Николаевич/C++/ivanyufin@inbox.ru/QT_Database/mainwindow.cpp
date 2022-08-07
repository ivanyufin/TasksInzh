#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./testDB.db");
    if(db.open())
    {
        ui->label->setText("Успешно подключено к базе данных");
    }
    else
    {
        ui->label->setText("Ошибка подключения к базе данных");
    }

    query = new QSqlQuery(db);
    if(db.tables().indexOf("TelephoneBook") == -1)
    {
        query->exec("CREATE TABLE TelephoneBook(Фамилия TEXT, Имя TEXT, Отчество TEXT, Телефон BIGINT);");
    }

    model = new QSqlTableModel(this, db);
    Refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    AddRow();
}


void MainWindow::on_pushButton_2_clicked()
{
    DeleteRow();
    Refresh();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::Refresh()
{
    model->setTable("TelephoneBook");
    model->select();
    ui->tableView->setModel(model);

}

void MainWindow::AddRow()
{
    model->insertRow(model->rowCount());
}

void MainWindow::DeleteRow()
{
    model->removeRow(row);
    ui->tableView->hideRow(row);
}

void MainWindow::on_pushButton_3_clicked()
{
    Refresh();
}

