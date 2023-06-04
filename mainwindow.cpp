//@author Арсентьева Н. В.
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // Подключаем к кнопкам слоты

    // Подключение сигнала от кнопки calculateButton к слоту calculate объекта MainWindow
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(calculate()));

    // Подключение сигнала от кнопки clearButton к слоту clear объекта MainWindow
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));

    // Соединяем сигнал и слот
    connect(this,&MainWindow::result,this,&MainWindow::slotMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    // Получаем значения с формы
    double price = ui->plainTextEdit_price->toPlainText().toDouble();
    double amount = ui->plainTextEdit_amount->toPlainText().toDouble();

    // Считаем скидку
    double amountPrice = price * (1 - (amount / 100));


    // Оповещаем о готовности результата вычислений
    emit result(amountPrice);

}

void MainWindow::slotMessage(double amountPrice)
{
    ui->textEdit_result->setText(QString::number(amountPrice));
}

void MainWindow::clear()
{
    // Очищаем
    ui->plainTextEdit_price->clear();
    ui->plainTextEdit_amount->clear();
    ui->textEdit_result->clear();
}

