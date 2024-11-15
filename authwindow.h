#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include "client.h"

class AuthWindow : public QWidget {
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow(); // Ajoutez un destructeur pour nettoyer les objets alloués dynamiquement

private slots:
    void toggleIdVisibility(bool checked);
    void togglePasswordVisibility(bool checked);
    void checkCredentials();
    void showMenu();
    void showInformationMenu();
    void processVirement();
    void showSolde();

private:
    QLineEdit *idLineEdit;
    QLineEdit *passwordLineEdit;
    QCheckBox *showIdCheckBox;
    QCheckBox *showPasswordCheckBox;
    QPushButton *loginButton;
    QLabel *statusLabel;

    QString correctId = "123456789";
    QString correctPassword = "tijanimadi";
    int attempts;
    double solde;

    Client *client;
    Client *client2;
};

#endif

