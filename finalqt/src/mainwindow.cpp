#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "person.h"
#include "child.h"
#include "kindergarten.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setTabText(1, "Create Manager");
    ui->tabWidget->setTabText(2, "Add Personell");
    ui->radioMale->setChecked(true);
    ui->tabWidget->setCurrentIndex(0);
    ui->errorLabel->setStyleSheet("QLabel { color:red;}");
    ui->errorLabelT->setStyleSheet("QLabel { color:red;}");
    ui->errorLabelC->setStyleSheet("QLabel { color:red;}");
    ui->errorLabelD->setStyleSheet("QLabel { color:red;}");
    ui->errorLabelB->setStyleSheet("QLabel { color:red;}");
    ui->lineNationalCode->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineNationalCode));
    ui->lineNationalCodeT->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineNationalCodeT));
    ui->lineNationalCodeC->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineNationalCodeC));
    ui->lineISBN->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineISBN));
    person manager("Omid", "Omidi", 25, 0, 1234567890);
    kind = new kindergarten(25, 35, manager, "Tehran", "Azadi", "Valiasr", 75);


    ui->lblAddress->setText(QString::fromStdString(kind->getAddress()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PbnCreateManager_clicked()
{
    if(ui->lineFname->text().isEmpty() || ui->lineLname->text().isEmpty() || ui->lineNationalCode->text().isEmpty() || ui->lineSecCode->text().isEmpty()){

        ui->errorLabel->setText("Form Inputs Should not be Empty!");
    }else {

        if(ui->lineSecCode->text() == "270773448"){

            bool gender = ui->radioMale->isChecked() ? false : true;
            ulli national_code = ui->lineNationalCode->text().toULongLong();
            person manager(ui->lineFname->text().toStdString(), ui->lineLname->text().toStdString(), ui->sbxAge->value(),  gender, national_code);
            qDebug() << QString::fromStdString(manager.getFname());
            qDebug() << QString::fromStdString(manager.getGender());
            qDebug() << manager.getNationalCode();


            kind->setManager(manager);
            ui->errorLabel->setText("<font color='green'>Manager Added Successfuly!</font>");

            qDebug() << QString::fromStdString(kind->getManager());

        }else {

            ui->errorLabel->setText("Wrong Security Code!");
        }
    }
}

void MainWindow::on_PbnCreateTeacher_clicked()
{

    if(ui->lineTFname->text().isEmpty() || ui->LineTLname->text().isEmpty() || ui->lineNationalCodeT->text().isEmpty()){

        ui->errorLabelT->setText("Form Inputs Should not be Empty!");
    }else {

            bool gender = ui->radioMaleT->isChecked() ? false : true;
            ulli national_code = ui->lineNationalCodeT->text().toULongLong();
            teacher t1(ui->lineTFname->text().toStdString(), ui->LineTLname->text().toStdString(), ui->sbxAgeT->value(),  gender, national_code, ui->sbxSalary->value(), ui->sbxWH->value());
            qDebug() << QString::fromStdString(t1.getFname());
            qDebug() << QString::fromStdString(t1.getGender());
            qDebug() << t1.getNationalCode();

            kind->addTeacher(t1);
            ui->errorLabelT->setText("<font color='green'>Personnel Added Successfuly!</font>");

    }
}

void MainWindow::on_PbnCreateChild_clicked()
{
    if(ui->lineCFname->text().isEmpty() || ui->lineCLname->text().isEmpty() || ui->lineNationalCodeC->text().isEmpty() || ui->lineFatherName->text().isEmpty()){

        ui->errorLabelC->setText("Form Inputs Should not be Empty!");
    }else {

            bool gender = ui->radioMaleC->isChecked() ? false : true;
            ulli national_code = ui->lineNationalCodeC->text().toULongLong();
            child::Problem problem = static_cast<child::Problem>(ui->cbxProblem->currentIndex());
            child ch1(ui->lineCFname->text().toStdString(), ui->lineCLname->text().toStdString(), ui->sbxAgeC->value(),  gender, national_code, ui->lineFatherName->text().toStdString(), problem);
            qDebug() << QString::fromStdString(ch1.getFname());
            qDebug() << QString::fromStdString(ch1.getGender());
            qDebug() << QString::fromStdString(ch1.getProblem());

            kind->addChild(ch1);
            ui->errorLabelC->setText("<font color='green'>Child Added Successfuly!</font>");

    }
}

void MainWindow::on_PbnBuyDevice_clicked()
{
    if(ui->lineDevName->text().isEmpty()){

        ui->errorLabelD->setText("Form Inputs Should not be Empty!");
    }else {

            device::Color color = static_cast<device::Color>(ui->cbxColor->currentIndex());
            device::Gender material = static_cast<device::Gender>(ui->cbxMaterial->currentIndex());
            device d(ui->sbxId->value(), ui->sbxPrice->value(), ui->lineDevName->text().toStdString(), color, material, ui->sbxWeight->value(), ui->sbxLength->value(), ui->sbxWidth->value());

            kind->addDevice(d);

            qDebug() << d.getId();
            ui->errorLabelD->setText("<font color='green'>Device Added Successfully</font>");

    }
}

void MainWindow::on_PbnRemoveChild_clicked()
{
    try {

        kind->removeChild(ui->lineRmChild->text().toULongLong());
        ui->errorLabelC->setText("<font color='green'>Child Removed Successfully!</font>");
    } catch (const std::exception &e) {
        ui->errorLabelC->setText("Couldn't Remove Child");
        qDebug() << QString::fromStdString(e.what());

    }
}

void MainWindow::on_PbnRmTeacher_clicked()
{
    try {

        kind->removeTeacher(ui->lineRmT->text().toULongLong());
        ui->errorLabelT->setText("<font color='green'>Teacher Removed Successfully!</font>");
    } catch (const std::exception &e) {
        ui->errorLabelT->setText("Couldn't Remove Teacher");
        qDebug() << QString::fromStdString(e.what());

    }
}

void MainWindow::on_PbnRmDevice_clicked()
{
    try {

        kind->removeDevice(ui->sbxRmDevice->value());
        ui->errorLabelD->setText("<font color='green'>Device Removed Successfully!</font>");
    } catch (const std::exception &e) {
        ui->errorLabelD->setText("Couldn't Remove Device");
        qDebug() << QString::fromStdString(e.what());

    }
}

void MainWindow::on_PbnBuyBook_clicked()
{

    if(ui->lineBookName->text().isEmpty() || ui->lineISBN->text().isEmpty() || ui->linePublisher->text().isEmpty() || ui->linePublisher->text().isEmpty()){

        ui->errorLabelD->setText("Form Inputs Should not be Empty!");
    }else {

            device::Color color = static_cast<device::Color>(ui->cbxColorB->currentIndex());
            device::Gender material = device::Gender::Paper;
            book b(ui->sbxIdB->value(), ui->sbxPriceB->value(), ui->lineBookName->text().toStdString(), color, material, ui->sbxWeightB->value(), ui->sbxLengthB->value(), ui->sbxWidthB->value(), ui->lineAuthor->text().toStdString(),ui->sbxPages->value(), ui->lineISBN->text().toULongLong(), ui->linePublisher->text().toStdString());

            kind->addBook(b);

            qDebug() << b.getId();
            ui->errorLabelB->setText("<font color='green'>Book Added Successfully</font>");

    }
}

void MainWindow::on_PbnRmBook_clicked()
{
    try {

        kind->removeBook(ui->sbxRmBook->value());
        ui->errorLabelB->setText("<font color='green'>Book Removed Successfully!</font>");
    } catch (const std::exception &e) {
        ui->errorLabelB->setText("Couldn't Remove Book");
        qDebug() << QString::fromStdString(e.what());

    }
}
