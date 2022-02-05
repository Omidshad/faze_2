#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kindergarten.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_PbnCreateManager_clicked();
    void on_PbnCreateTeacher_clicked();

    void on_PbnCreateChild_clicked();

    void on_PbnBuyDevice_clicked();

    void on_PbnRemoveChild_clicked();

    void on_PbnRmTeacher_clicked();

    void on_PbnRmDevice_clicked();

    void on_PbnBuyBook_clicked();

    void on_PbnRmBook_clicked();

private:
    Ui::MainWindow *ui;
    kindergarten *kind;
};
#endif // MAINWINDOW_H
