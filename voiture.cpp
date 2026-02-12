#include "voiture.h"   // Inclusion du header pour avoir la définition de la classe


Voiture::Voiture(const char *m, const char *mod, const char *c, const char *bv, int km, float carburant) { // Constructeur
    marque = new char[strlen(m) + 1];   // Alloue la mémoire pour la chaîne "marque"
    strcpy(marque, m);                  // Copie la valeur passée en paramètre

    modele = new char[strlen(mod) + 1]; // Alloue la mémoire pour la chaîne "modele"
    strcpy(modele, mod);                // Copie la valeur du paramètre

    this->carburant = new char[strlen(c) + 1]; // Alloue la mémoire pour la chaîne "carburant"
    strcpy(this->carburant, c);                // Copie le type de carburant

    boite_vitesse = new char[strlen(bv) + 1];  // Alloue la mémoire pour la boîte de vitesse
    strcpy(boite_vitesse, bv);                 // Copie la valeur

    kilometrage = km;             // Initialise le kilométrage
    niv_carburant = carburant;    // Initialise le niveau de carburant
    moteur = false;               // Par défaut, le moteur est éteint
}


Voiture::~Voiture() { //Destructeur
    delete[] marque;        // Libère la mémoire de "marque"
    delete[] modele;        // Libère la mémoire de "modele"
    delete[] carburant;     // Libère la mémoire de "carburant"
    delete[] boite_vitesse; // Libère la mémoire de "boite_vitesse"
}


void Voiture::Afficher_voiture() { //Methode d'affichage 
    cout << "_______ Voiture _______" << endl;                      // Affiche un titre
    cout << "Marque:" << marque << endl;                           // Affiche la marque
    cout << "Modele:" << modele << endl;                           // Affiche le modèle
    cout << "Type de carburant:" << carburant << endl;             // Affiche le carburant
    cout << "Boite de vitesse:" << boite_vitesse << endl;          // Affiche la boîte de vitesse
    cout << "Kilometrage:" << kilometrage << "Km" << endl;         // Affiche le kilométrage
    cout << "Etat du moteur:" << (moteur ? "Allume" : "Eteint") << endl; // Affiche l'état du moteur
    cout << "Niveau de carburant:" << niv_carburant << "L" << endl;      // Affiche le carburant
    cout << "La distance estimee:" << Estim_distance() << "Km" << endl;  // Affiche la distance estimée
    cout << "_______________________" << endl << endl;             // Séparation visuelle
}

//Méthodes moteur
void Voiture::allumer_moteur() {
    moteur = true;   // Passe l'état du moteur à "allumé"
}

void Voiture::eteindre_moteur() {
    moteur = false;  // Passe l'état du moteur à "éteint"
}

bool Voiture::Etat_moteur() {
    return moteur;   // Retourne true si moteur allumé, false sinon
}

float Voiture::Consom_carburant(float dist) { // Calcul consommation
    return (consom_ref * dist) / 100.0; // Formule consommation = conso_ref * dist / 100
}

int Voiture::Rouler(int distance) { //rouler
    if (!moteur) {  // Vérifie si le moteur est éteint
        cout << "Impossible de rouler : moteur eteint !" << endl; // Message d'erreur
        return kilometrage; // On ne change rien
    }

    float conso = Consom_carburant(distance); // Calcule la consommation pour la distance demandée

    if (niv_carburant >= conso) {             // Si carburant suffisant
        kilometrage += distance;              // On augmente le kilométrage
        niv_carburant -= conso;               // On diminue le carburant consommé
    } else {                                  // Sinon, pas assez de carburant
        cout << "Pas assez de carburant pour parcourir " << distance << "Km !" << endl;
        float dist_possible = Estim_distance(); // Calcule la distance possible
        kilometrage += dist_possible;           // Ajoute seulement la distance possible
        niv_carburant = 0;                      // Réservoir vide
    }

    return kilometrage; // Retourne le nouveau kilométrage
}

float Voiture::Estim_distance() { //Estimation de distance
    return (niv_carburant * 100.0) / consom_ref; // Distance possible = (litres * 100) / consommation
}
