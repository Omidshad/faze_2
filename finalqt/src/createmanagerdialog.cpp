#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "person.h"
#include "kindergarten.h"

#include <QDebug>

createmanagerdialog::createmanagerdialog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->radioMale->setChecked(true);
    ui->errorLabel->setStyleSheet("QLabel { color:red;}");
    ui->lineNationalCode->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineNationalCode));
}

createmanagerdialog::~createmanagerdialog()
{
    delete ui;
}


void MainWindow::on_PbnCreateManager_clicked()
{
    if(ui->lineFname->text().isEmpty() || ui->lineFname->text().isEmpty() || ui->lineNationalCode->text().isEmpty() || ui->lineSecCode->text().isEmpty()){

        ui->errorLabel->setText("Form Inputs Should not be Empty!");
    }else {

        if(ui->lineSecCode->text() == "270773448"){

            bool gender = ui->radioMale->isChecked() ? false : true;
            ulli national_code = ui->lineNationalCode->text().toULongLong();
            person manager(ui->lineFname->text().toStdString(), ui->lineLname->text().toStdString(), ui->sbxAge->value(),  gender, national_code);
            qDebug() << QString::fromStdString(manager.getFname());
            qDebug() << QString::fromStdString(manager.getGender());
            qDebug() << manager.getNationalCode();

            kindergarten Kind(25, 35, manager, "Tehran", "Azadi", "Valiasr", 75);
            Kind.setManager(manager);

            qDebug() << QString::fromStdString(Kind.getManager());

        }else {

            ui->errorLabel->setText("Wrong Security Code!");
        }
    }
}
