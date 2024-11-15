#include <iostream>
#include <cstring>
#include "client.h"
#include "compte.h"

using namespace std;

Client::Client(string CINN, string nomFami,string Preno, string num, double monSolde){ // constructeur
    CIN=CINN;
    nom=nomFami;
    prenom=Preno;
    numero=num;
    solde = monSolde;
}


string Client::getNom(){
    return nom;
}

string Client::getCIN(){
    return CIN;
}

string Client::getNum(){
    return numero;
}

string Client::getPrenom(){
    return prenom;
}

double Client::getSolde(){
    return solde;
}
