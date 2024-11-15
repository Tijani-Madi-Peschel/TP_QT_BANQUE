#include <iostream>


#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

class Client{
    private:
    string CIN; // ID du client
    string nom; // Nom du client
    string prenom; // Prenom du client
    string numero; // Numero du client
    double solde;
    public:

    Client(string ,string ,string ,string, double );
    string getCIN(); // Retourne l'ID DU CLIENT
    string getNom(); // Retourne le Nom du client
    string getPrenom(); // Retourne le Prenom du client
    string getNum(); // Retourne le Numero du client
    double getSolde(); // Modifie le numero du client
};

#endif

