#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void l1();
    void l2();
    void l3();
private:
    Ui::MainWindow *ui;
    int puntaje = 0;
    bool estaFuncionando = false;
    int nro, nro1, nro2;
    QTimer * t1;
    QTimer * t2;
    QTimer * t3;
    void verificar();
};

#endif // MAINWINDOW_H
