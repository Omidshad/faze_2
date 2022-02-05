#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class createmanagerdialog : public createmanagerdialog
{
    Q_OBJECT

public:
    createmanagerdialog(QWidget *parent = nullptr);
    ~createmanagerdialog();

private slots:

    void on_PbnCreateManager_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
