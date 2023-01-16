#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Classe_Utilisateur.h"
#include <QDesktopServices>
#include <QUrl>

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
    QMessageBox::warning(this,"Warning entry","Veuillez entrer votre nom et votre mot de passe");
    return;
}
switch (correctEntry(name,pswrd)) {
case 0://erreur lors de l'ouvertur du fichier
    QMessageBox::warning(this,"Critical Error","Une erreur est survenue lors de la vérification, merci de contacter le service client");
    break;
case 1://utilisateur non trouvé
    QMessageBox::warning(this,"Warning entry","Utilisateur non trouvé, réessayez ou inscrivez-vous");
    break;
case 2://utilisateur trouvé mais mauvais mot de passe
    QMessageBox::warning(this,"Warning entry","Mot de passe saisie incorrect. Attention aux majuscules");
    break;
case 3://utilisateur trouvé avec le bon mot de passe
    this->hide();
    Accueil *accueil = new Accueil();
    accueil->show();
    break;
}
}

//bouton créer un compte renvoie sur une page web pour le contrôle de la création d'un compte
void MainWindow::on_btn_CreatCount_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.google.fr"));
}

