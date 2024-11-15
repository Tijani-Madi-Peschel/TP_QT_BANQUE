#include <iostream>

#ifndef COMPTE_H
#include "client.h"
#define COMPTE_H



class Compte{
    private:
    string ID; // ID du compte
    double solde; // Solde du compte
    string rib; // RIB du compte
    Client client; // Client

    public:
    Compte(string  ,double ,string, Client ); // Constructeur

    string  getRib(); // Retourne le RIB
    double getSolde(); // Retourne le Solde
    void MENU(); // MENU
    float Credit(); // Méthode de Credit
    float Credit2(string); // Méthode de Credit 2
    float Debit(); // Méthode de Debit
    float Virement(); // Méthode de Virement
    void InfoCompte(); // MENU INFOCOMPTE
};
#endif
