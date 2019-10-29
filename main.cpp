#include <iostream>

#include "chambre.h"
#include "client.h"
#include "date.h"
#include "hotel.h"
#include "listedechambres.h"
#include "listedeclients.h"
#include "listedereservations.h"
#include "reservation.h"

using namespace std;

int main() {
    /* Partie 1 Question 1
    Date date(28, 2, 2019);
    Date dateBissextile(28, 2, 2020);
    std::cout << "La date est de : " << date.toString() << endl;
    std::cout << "La date bissextile est de : " << dateBissextile.toString() << endl;
    date.jourProchain();
    dateBissextile.jourProchain();
    std::cout << "La date est de : " << date.toString() << endl;
    std::cout << "La date bissextile est de : " << dateBissextile.toString() << endl;
    */

    /* Question 2
    Client client("1", "Chassagne", "Pierre-Nicolas", 0);
    std::cout << "La client est : " << client.toString() << endl;
    client.setNomClient("Polybe");
    client.setPrenomClient("Polybe");
    client.ajouterReservation();
    std::cout << "La client est : " << client.toString() << endl;
    */

    /* Question 3
    Chambre chambre(1,TypeDeChambre::Simple, 10.0);
    std::cout << "La chambre est : " << chambre.toString() << endl;
    */

    /* Question 4
    Chambre chambre1(1,TypeDeChambre::Simple, 10.0);
    std::cout << "La chambre est : " << chambre1.toString() << endl << endl;
    Chambre chambre2(2,TypeDeChambre::Double, 20.0);
    std::cout << "La chambre est : " << chambre2.toString() << endl << endl;
    std::vector<Chambre> listeChambre;
    listeChambre.push_back(chambre1);
    listeChambre.push_back(chambre2);
    Hotel hotel("HOTEL", "Nom", "Ville", listeChambre);
    std::cout << "L'hotel est : " << hotel.toString() << endl;
    */

    /* Question 5
    Date date1(2, 6, 2019);
    Date date2(3, 8, 2021);
    std::cout << date1.nombreDeJoursAvecCetteDate(date2) << endl;

    Chambre chambre1(1,TypeDeChambre::Simple, 10.0);
    std::cout << "La chambre est : " << chambre1.toString() << endl << endl;
    Chambre chambre2(2,TypeDeChambre::Double, 20.0);
    std::cout << "La chambre est : " << chambre2.toString() << endl << endl;

    std::vector<Chambre> listeChambre;
    listeChambre.push_back(chambre1);
    listeChambre.push_back(chambre2);
    Hotel hotel("HOTEL", "Nom", "Ville", listeChambre);
    std::cout << "L'hotel est : " << hotel.toString() << endl;

    Client client("1", "Chassagne", "Pierre-Nicolas", 0);

    Reservation reservation(0, hotel, chambre1, client);
    reservation.setPeriodeDeReservation(date1, date2);;
    std::cout <<  "La reservation est : " << reservation.toString() << endl;
    */

    /* Partie 2 Question 6 */
    ListeDeChambres listeDeChambres;
    for (int i = 0; i < 10; i++) {
        if (i < 3) {
            listeDeChambres.ajouterChambre(Chambre(i, TypeDeChambre::Simple, 100.0));
        }
        else if (i < 8) {
            listeDeChambres.ajouterChambre(Chambre(i, TypeDeChambre::Double, 125.0));
        }
        else {
            listeDeChambres.ajouterChambre(Chambre(i, TypeDeChambre::Suite, 210.0));
        }
    }
    Hotel hotel("HOTEL", "Nom", "Ville", listeDeChambres);
    std::cout << "L'hotel est : " << hotel.toString() << endl;

    ListeDeClients listeDeClients;
    for (int i = 0; i < 10; i++) {
        listeDeClients.ajouterClient(Client("Client" + std::to_string(i), "Client" + std::to_string(i), "Client" + std::to_string(i), 0));
    }
    std::cout << "La liste de clients est : " << listeDeClients.toString() << std::endl;

    /* Question 11 */
    int compteurReservation = 0;
    ListeDeReservations listeDeReservations(hotel);
    while (true) {
        int choixMenu = 0;
        std::cout << "Taper 0 pour afficher toutes les reservations." << std::endl;
        std::cout << "Taper 1 pour afficher une reservations avec l'identifiant de reservation." << std::endl;
        std::cout << "Taper 2 pour afficher toutes les reservations du nom de client." << std::endl;
        std::cout << "Taper 3 pour ajouter une reservations." << std::endl;
        std::cout << "Taper 4 pour supprimer une reservations." << std::endl;
        std::cin >> choixMenu;
        if (choixMenu == 0) {
            std::cout << "La liste de reservations est : " << listeDeReservations.toString() << std::endl;
        }
        else if (choixMenu == 1) {
            int identifiantDeReservation = 0;
            std::cout << "Taper l'identifiant de reseravtion." << std::endl;
            std::cin >> identifiantDeReservation;
            std::cout << "La reservations est : " << listeDeReservations.getReservationAvecIdentifiantDeReservation(identifiantDeReservation).toString() << std::endl;
        }
        else if (choixMenu == 2) {
            std::string identifiantDeClient = "";
            std::cout << "Taper l'identifiant du client." << std::endl;
            std::cin >> identifiantDeClient;
            std::cout << "La liste de reservations est : " << listeDeReservations.getToutesReservationUnClient(listeDeClients.getClientAvecIdentifiantDeClient(identifiantDeClient)).toString() << std::endl;
        }
        else if (choixMenu == 3) {
            Reservation reservation(compteurReservation);
            compteurReservation++;

            bool quitDatesReservation = false;
            while (!quitDatesReservation) {
                int jourDebut;
                int jourFin;
                int moisDebut;
                int moisFin;
                int anneeDebut;
                int anneeFin;
                std::cout << "Entrer la date de debut et la date de fin de la reservation :" << std::endl;
                std::cout << "Jour de debut : ";
                cin >> jourDebut;
                std::cout << "Mois de debut : ";
                cin >> moisDebut;
                std::cout << "Annee de debut : ";
                cin >> anneeDebut;
                std::cout << "Jour de fin : ";
                cin >> jourFin;
                std::cout << "Mois de fin : ";
                cin >> moisFin;
                std::cout << "Annee de fin : ";
                cin >> anneeFin;
                Date dateDebut(jourDebut, moisDebut, anneeDebut);
                Date dateFin(jourFin, moisFin, anneeFin);
                if ((dateDebut.estValide()) && (dateFin.estValide()) && (reservation.setPeriodeDeReservation(dateDebut, dateFin))) {
                    quitDatesReservation = true;
                }
                else {
                    std::cout << "Erreur de saisie : Veuillez resaisir les dates." << std::endl;
                }
            }

            bool quitChambreReservation = false;
            while (!quitChambreReservation) {
                std::cout << "Entrer le type de chambre desirer :" << std::endl;
                int choixTypeDeChambre = 0;
                std::vector<std::string> listeTypesDeChambre = listeDeChambres.getListeTypesDeChambre();
                for (int i = 0; i < listeTypesDeChambre.size(); i++) {
                    std::cout << "Taper " << std::to_string(i) << " pour " << listeTypesDeChambre.at(i) << std::endl;
                }
                cin >> choixTypeDeChambre;
                TypeDeChambre typeDeChambreChoisi = listeDeChambres.getTypeDeChambreAvecString(listeTypesDeChambre.at(choixTypeDeChambre));
                if (listeDeReservations.chambreDeCeTypeEstDisponibleDansHotel(typeDeChambreChoisi, reservation.getDateDebutReservation(), reservation.getDateFinReservation())) {
                    quitChambreReservation = true;
                    reservation.setChambreReservation(listeDeReservations.reservePremiereChambreDeCeTypeDansHotel(typeDeChambreChoisi, reservation.getDateDebutReservation(), reservation.getDateFinReservation()));
                }
                else {
                    std::cout << "Ce type de chambre n'est pas disponible." << std::endl;
                }
            }

            bool quitClientReservation = false;
            while (!quitClientReservation) {
                std::string nomClientReservation = "";
                int choixClient = 0;
                Client clientReservation;
                std::cout << "Entrer le nom du client :" << std::endl;
                cin >> nomClientReservation;
                std::vector<Client> listeClientsSelectionnes = listeDeClients.getTousLesClientsAvecNomDeClient(nomClientReservation);
                if (listeClientsSelectionnes.size() != 0) {
                    for (int i = 0; i < listeClientsSelectionnes.size(); i++) {
                        std::cout << "Taper " << std::to_string(i) << " pour le client" << listeClientsSelectionnes.at(i).toString() << std::endl;
                    }
                    cin >> choixClient;
                    clientReservation = listeClientsSelectionnes.at(choixClient);
                    std::cout << "Le client est : " << clientReservation.toString() << std::endl;
                    reservation.setClientReservation(clientReservation);
                    quitClientReservation = true;
                }
                else {
                    std::cout << "Aucun client ne possede ce nom." << std::endl;
                }
            }
            reservation.calculMontantTotal();
            listeDeReservations.ajouterReservation(reservation);
        }
        else if (choixMenu == 4) {
            int identifiantDeReservation = 0;
            std::cout << "Taper l'identifiant de reservation a supprimer." << std::endl;
            std::cin >> identifiantDeReservation;
            listeDeReservations.supprimerReservation(listeDeReservations.getReservationAvecIdentifiantDeReservation(identifiantDeReservation));
        }
    }
    return 0;
}
