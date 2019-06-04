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
    void refrescar();

private:
    Ui::MainWindow *ui;
    int cont =0;
    int contIncremento;
    QTimer * timer;
};

#endif // MAINWINDOW_H
