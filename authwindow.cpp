#include "authwindow.h"
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QInputDialog>
#include <client.h>


AuthWindow::AuthWindow(QWidget *parent)
    : QWidget(parent),
      attempts(0),
      solde(1000.0),
      client(new Client("FR1234", "madi", "tijani", "1234", 10000)),
      client2(new Client("FR2345", "madi", "milhane", "1234", 10000))
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    idLineEdit = new QLineEdit(this);
    idLineEdit->setPlaceholderText("Identifiant (9 chiffres)");
    idLineEdit->setMaxLength(9);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Mot de passe");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    showIdCheckBox = new QCheckBox("Afficher l'Identifiant", this);
    showPasswordCheckBox = new QCheckBox("Afficher le Mot de passe", this);

    loginButton = new QPushButton("Connexion", this);
    statusLabel = new QLabel(this);

    QHBoxLayout *idLayout = new QHBoxLayout;
    idLayout->addWidget(idLineEdit);
    idLayout->addWidget(showIdCheckBox);

    QHBoxLayout *passwordLayout = new QHBoxLayout;
    passwordLayout->addWidget(passwordLineEdit);
    passwordLayout->addWidget(showPasswordCheckBox);

    mainLayout->addLayout(idLayout);
    mainLayout->addLayout(passwordLayout);
    mainLayout->addWidget(loginButton);
    mainLayout->addWidget(statusLabel);

    connect(showIdCheckBox, &QCheckBox::toggled, this, &AuthWindow::toggleIdVisibility);
    connect(showPasswordCheckBox, &QCheckBox::toggled, this, &AuthWindow::togglePasswordVisibility);
    connect(loginButton, &QPushButton::clicked, this, &AuthWindow::checkCredentials);
}


AuthWindow::~AuthWindow() {
    delete client;
    delete client2;
}


void AuthWindow::toggleIdVisibility(bool checked) {
    idLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}

void AuthWindow::togglePasswordVisibility(bool checked) {
    passwordLineEdit->setEchoMode(checked ? QLineEdit::Normal : QLineEdit::Password);
}

void AuthWindow::checkCredentials() {
    QString id = idLineEdit->text();
    QString password = passwordLineEdit->text();

    if (id.length() != 9 || id != correctId) {
        statusLabel->setText("Identifiant incorrect.");
        return;
    }

    if (password == correctPassword) {
        statusLabel->setText("Authentification réussie!");
        loginButton->setStyleSheet("background-color: green");
        showMenu();
    } else {
        attempts++;
        statusLabel->setText(QString("Mot de passe incorrect. Tentatives restantes: %1").arg(3 - attempts));
        loginButton->setStyleSheet("background-color: red");

        if (attempts >= 3) {
            close();
        }
    }
}

void AuthWindow::showMenu() {
    QMessageBox menuBox;
    menuBox.setWindowTitle("BANQUE POPULAIRE");
    menuBox.setText("Tijani M.P");
    QPushButton *virementButton = menuBox.addButton(tr("VERSEMENT"), QMessageBox::ActionRole);
    QPushButton *informationButton = menuBox.addButton(tr("INFORMATION"), QMessageBox::ActionRole);
    QPushButton *soldeButton = menuBox.addButton(tr("SOLDE"), QMessageBox::ActionRole);
    QPushButton *quitterButton = menuBox.addButton(tr("QUITTER"), QMessageBox::ActionRole);

    menuBox.exec();

    if (menuBox.clickedButton() == virementButton) {
        processVirement();
    } else if (menuBox.clickedButton() == informationButton) {
        showInformationMenu();
    } else if (menuBox.clickedButton() == soldeButton) {
        showSolde();
    } else if (menuBox.clickedButton() == quitterButton) {
        QMessageBox::information(this, "DECONNEXION", "");
        close();
    }
}

void AuthWindow::showInformationMenu() {
    QMessageBox infoBox;
    infoBox.setWindowTitle("INFORMATION");
    QString information = "Tijani Madi--Peschel\n"
                          "tijanimadi94@gmail.com\n"
                          "0619697988";
    infoBox.setText(information);
    QPushButton *retourButton = infoBox.addButton(tr("RETOUR"), QMessageBox::ActionRole);

    infoBox.exec();

    if (infoBox.clickedButton() == retourButton) {
        showMenu();
    }
}

void AuthWindow::processVirement() {
    bool ok;
    double montant = QInputDialog::getDouble(this, tr("VERSEMENT"),
                                             tr("Montant à virer:"), 0, 0, solde, 2, &ok);
    if (ok) {
        solde += montant;
        QMessageBox::information(this, "VERSEMENT", "Versement de " + QString::number(montant) + " effectué.");
    }
    showMenu();
}

void AuthWindow::showSolde() {
    QMessageBox::information(this, "SOLDE", "Votre solde est de " + QString::number(solde) + " euros.");
    showMenu();
}
