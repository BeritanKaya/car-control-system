#include "voiture.h"  // Inclusion de la classe Voiture

int main() {
    // Création d'une voiture avec paramètres :
    // Marque = Audi, Modèle = A3, Carburant = Diesel, Boîte = Auto, Km = 100000, Carburant = 30L
    Voiture ma_voiture("Audi", "A3", "Diesel", "Auto", 100000, 30);

    ma_voiture.Afficher_voiture(); //  Affiche la voiture (moteur éteint)

    ma_voiture.allumer_moteur();   //  Allume le moteur
    ma_voiture.Afficher_voiture(); // Affiche de nouveau (moteur allumé)

    ma_voiture.Rouler(300);        //  Fait rouler 300 km (réduit le carburant)
    ma_voiture.Afficher_voiture(); // Affiche après roulage

    ma_voiture.eteindre_moteur();  // Éteint le moteur

    return 0; // Fin du programme
}
