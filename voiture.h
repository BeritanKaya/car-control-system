#ifndef VOITURE_H       // Empêche l'inclusion multiple du fichier
#define VOITURE_H

#include <iostream>     // Pour cout, endl
#include <cstring>      // Pour strcpy et strlen
using namespace std;    // Pour éviter d'écrire std:: partout

// Déclaration de la classe Voiture
class Voiture {
private:
    char *marque;        // Chaîne de caractères pour la marque (ex: "Audi")
    char *modele;        // Chaîne pour le modèle (ex: "A3")
    char *carburant;     // Chaîne pour le carburant (ex: "Diesel")
    char *boite_vitesse; // Chaîne pour la boîte de vitesse (ex: "Auto")
    bool moteur;         // État du moteur (true = allumé, false = éteint)
    int kilometrage;     // Kilométrage actuel de la voiture
    float niv_carburant; // Niveau de carburant en litres
    const float consom_ref = 4.8; // Consommation en L/100km (fixe)

public:
    // Constructeur avec paramètres
    Voiture(const char *m, const char *mod, const char *c, const char *bv, int km, float carburant);

    // Destructeur pour libérer la mémoire
    ~Voiture();

    // Méthode pour afficher les informations de la voiture
    void Afficher_voiture();

    // Méthodes pour changer l'état du moteur
    void allumer_moteur();   // Allume le moteur
    void eteindre_moteur();  // Éteint le moteur

    // Méthode pour savoir si le moteur est allumé ou non
    bool Etat_moteur();

    // Méthode pour rouler une distance donnée
    int Rouler(int distance);

    // Méthode pour calculer la consommation pour une distance
    float Consom_carburant(float dist);

    // Méthode pour estimer la distance possible avec le carburant restant
    float Estim_distance();
};

#endif // Fin de la protection contre inclusion multiple
