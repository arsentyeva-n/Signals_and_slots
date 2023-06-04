//@author Арсентьева Н. В.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


//Слот это функция, которая вызывается в ответ на определенный сигнал
signals:
    void result(double amountPrice); //Сигнал для вывода цены со скидкой


private slots:
    void calculate(); //Слоты-обработчики нажатий кнопок
    void clear();

    void slotMessage(double amountPrice); //Слот,  вывод на форму
};
#endif // MAINWINDOW_H
