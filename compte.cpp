#include <iostream>
#include "compte.h"
#include "client.h"

using namespace std;


Compte::Compte(string CIN, double sold,string ribb, Client c ):client(c){  // constructeur + initialisation des membres avec client(c) cela permet d'utiliser un compte personalisé pour chaque client
    CIN=CIN;
    solde=sold;
    rib=ribb;
}

double Compte::getSolde(){
    return solde;
}

string  Compte::getRib(){
    return rib;
}

float Compte::Credit(){                                          // CREDITER LE COMPTE
    system("CLS");
    cout<<"\n\tCREDITER\n\n";
    cout<<" 1. Deposer une somme\n";
    cout<<" 2. Crediter un autre compte\n";
    cout<<" 3. Retour\n\n Choix : ";
    unsigned int choix;
    cin>>choix;
    if(choix==1){
        system("CLS");
        cout<<"\n\tDEPOSER UNE SOMME\n\n";
        cout<<"\t\n Combien voulez vous deposer ?\n\n ";
        cin>>choix;
        if(choix>=0){
            solde=solde+choix;
            cout<<"\n SOLDE AJOUTER\n\n Votre solde s'eleve a "<<solde<<" €\n";
        }
        else{
            cout<<"\n ERREUR SOLDE NEGATIF";
        }
        choix=0;
        system("pause");
    }
    else if(choix == 2){                                            // A REVOIR PAS FINI IL MANQUE PARAMETRE
        system("CLS");
        cout<<"\n\tCREDITER UN AUTRE COMPTE\n\n";
        cout<<"\t\n Quel compte voulez vous creditez ? ENTREZ LE NOM\n\n ";
        string autre;
        cin>>autre;
        Credit2(autre);

    }
    return 0;
}

float Compte::Credit2(string autre){
        system("CLS");
        cout<<"\t\n Combien voulez vous crediter ?\n\n ";
        unsigned int choix;
        cin>>choix;
        if(choix>=0){
            system("CLS");
            solde=solde+choix;
            cout<<"\n SOLDE AJOUTER\n\n Votre solde s'eleve a "<<solde<<" €\n";
            }
        else{
            system("CLS");
            cout<<"\n ERREUR SOLDE NEGATIF";
            }
        system("pause");

}

float Compte::Debit(){                                        // DEBITER LE COMPTE
    system("CLS");
    cout<<"\n\tDEBITER\n\n";
    cout<<"\t\n Combien voulez vous retirez ?\n\n ";
    int choix;
    cin>>choix;
        if(choix>=0){
            solde=solde-choix;
            cout<<"\n SOLDE RETIRER\n\n Votre solde s'eleve a "<<solde<<" €\n";
        }
        else{
            cout<<"\n ERREUR SOLDE NEGATIF";
        }
        choix=0;
        system("pause");

}

float Compte::Virement(){
    system("CLS");
    cout<<"\t\n Quel compte voulez vous creditez ? ENTREZ LE NOM\n\n ";
    string autre;
    cin>>autre;
    system("CLS");
    cout<<"\t\n Montant du virement : ";
    double choixV;
    cin>>choixV;
        if(choixV>=0){
            system("CLS");
            solde=solde-choixV;
            cout<<"\n VIREMENT EFFECTUE\n\n Votre solde s'eleve a "<<solde<<" €\n\n";
        }
        else{
            cout<<"\n ERREUR SOLDE NEGATIF";
        }
        choixV=0;
    system("pause");

}

void Compte::InfoCompte(){

}

void Compte::MENU()
{
    int cpt=1;
    while (cpt !=0){
        system("CLS");
        cout<<"\n\t--- GESTION DU COMPTE DE "<<client.getNom()<<" "<<client.getPrenom()<<" ---\n\n";
        cout<<" 1. Crediter son compte\n";
        cout<<" 2. Debiter son compte\n";
        cout<<" 3. Virement\n";
        cout<<" 4. Info Compte\n\n";
        cout<<" 5. Quitter \n\n Choix : ";
        int choix;
        cin>>choix;
        switch (choix){
        case 1:
            Credit();
            break;
        case 2:
            Debit();
            break;
        case 3:
            Virement();
            break;
        case 4:
            InfoCompte();;
            break;
        case 5:
            cpt=0;
            break;
        default:
            system("CLS");
            cout<<"\n\tERREUR\n\n";
            choix=0;
            system("pause");
            break;
        }
    }
}
