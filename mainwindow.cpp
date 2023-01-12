#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_Connexion_clicked()
{
  QString name,pswrd;
  name=ui->lineEdit_Name->text();
  pswrd=ui->lineEdit_MdP->text();
if(name==""||pswrd==""){
    QMessageBox::warning(this,"Warning entry","veuillez entrer votre nom et votre mot de passe");
    return;
}
this->hide();
Accueil *accueil = new Accueil();
accueil->show();
}


void MainWindow::on_btn_CreatCount_clicked()
{

}

