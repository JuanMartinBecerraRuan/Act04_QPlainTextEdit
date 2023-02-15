#include "mainwindow.h"
#include "ui_mainwindow.h"

list<Neurona> lista;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    //INSERTAR AL INICIO
    int id, posicion_x,posicion_y,red,green,blue;
    double voltaje;
    id=ui->id_spinBox->value();
    voltaje=ui->voltaje_doubleSpinBox->value();
    posicion_x=ui->Pos_x_spinBox_2->value();
    posicion_y=ui->Pos_y_spinBox_2->value();
    red=ui->red_spinBox_4->value();
    green=ui->green_spinBox_5->value();
    blue=ui->spinBox_6->value();
    if(id == 0 or voltaje == 0 or id == NULL or voltaje == NULL){
        QMessageBox::warning(this,"Mensaje","Tiene que existir un voltaje y un id.");
    }else{
        Neurona *nuevo = new Neurona(id,voltaje,posicion_x,posicion_y,red,green,blue);
        lista.push_front(*nuevo);
        ui->id_spinBox->clear();
        ui->voltaje_doubleSpinBox->clear();
        ui->Pos_x_spinBox_2->clear();
        ui->Pos_y_spinBox_2->clear();
        ui->red_spinBox_4->clear();
        ui->green_spinBox_5->clear();
        ui->spinBox_6->clear();
    }
}

void MainWindow::on_pushButton_2_clicked(){
    //INSERTAR AL FINAL
    int id, posicion_x,posicion_y,red,green,blue;
    double voltaje;
    id=ui->id_spinBox->value();
    voltaje=ui->voltaje_doubleSpinBox->value();
    posicion_x=ui->Pos_x_spinBox_2->value();
    posicion_y=ui->Pos_y_spinBox_2->value();
    red=ui->red_spinBox_4->value();
    green=ui->green_spinBox_5->value();
    blue=ui->spinBox_6->value();
    if(id == 0 or voltaje == 0 or id == NULL or voltaje == NULL){
        QMessageBox::warning(this,"Mensaje","Tiene que existir un voltaje y un id.");
    }else{
        Neurona *nuevo = new Neurona(id,voltaje,posicion_x,posicion_y,red,green,blue);
        lista.push_back(*nuevo);
        ui->id_spinBox->clear();
        ui->voltaje_doubleSpinBox->clear();
        ui->Pos_x_spinBox_2->clear();
        ui->Pos_y_spinBox_2->clear();
        ui->red_spinBox_4->clear();
        ui->green_spinBox_5->clear();
        ui->spinBox_6->clear();
    }
}

void MainWindow::on_pushButton_3_clicked(){
    //MOSTRAR
    if(!lista.empty()){
        ui->plainTextEdit->clear();
        list<Neurona>::iterator aux = lista.begin();
        while(aux!=lista.end()){
            ui->plainTextEdit->insertPlainText("ID: "+QString::number(aux->getId())+"\n");
            ui->plainTextEdit->insertPlainText("VOLTAJE: "+QString::number(aux->getVoltaje())+"\n");
            ui->plainTextEdit->insertPlainText("POS_X: "+QString::number(aux->getPosX())+"\n");
            ui->plainTextEdit->insertPlainText("POS_Y: "+QString::number(aux->getPosY())+"\n");
            ui->plainTextEdit->insertPlainText("RED: "+QString::number(aux->getRed())+"\n");
            ui->plainTextEdit->insertPlainText("GREEN: "+QString::number(aux->getGreen())+"\n");
            ui->plainTextEdit->insertPlainText("RED: "+QString::number(aux->getRed())+"\n\n");
            aux++;
        }
    }else{
        ui->plainTextEdit->clear();
        ui->plainTextEdit->insertPlainText("La lista esta vacia...");
    }
}

