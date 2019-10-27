#include <iostream>

#include "chambre.h"
#include "client.h"
#include "date.h"
#include "hotel.h"
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
    std::vector<Chambre> listeChambres;
    for (int i = 0; i < 10; i++) {
        if (i < 3) {
            listeChambres.push_back(Chambre(i, TypeDeChambre::Simple, 100.0));
        }
        else if (i < 8) {
            listeChambres.push_back(Chambre(i, TypeDeChambre::Double, 125.0));
        }
        else {
            listeChambres.push_back(Chambre(i, TypeDeChambre::Suite, 210.0));
        }
    }
    Hotel hotel("HOTEL", "Nom", "Ville", listeChambres);
    std::cout << "L'hotel est : " << hotel.toString() << endl;

    std::vector<Client> listeClients;
    for (int i = 0; i < 10; i++) {
        listeClients.push_back(Client("Client" + std::to_string(i), "Client" + std::to_string(i), "Client" + std::to_string(i), 0));
    }
    for (Client client : listeClients) {
        std::cout << "Le client est : " << client.toString() << std::endl;
    }
    std::cout << std::endl;

    std::vector<Reservation> listeReservations;
    for(int i = 0; i < 1; i++) {
        Reservation reservation;

        /* Question 7 */
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

        /* Question 8 */
        bool quitChambreReservation = false;
        while (!quitChambreReservation) {
            std::cout << "Entrer le type de chambre désirer :" << std::endl;
            int choixTypeDeChambre = 0;
            std::vector<std::string> listeTypesDeChambre = listeChambres.at(0).getListeTypesDeChambre();
            for (int i = 0; i < listeTypesDeChambre.size(); i++) {
                std::cout << "Taper " << std::to_string(i) << " pour " << listeTypesDeChambre.at(i) << std::endl;
            }
            cin >> choixTypeDeChambre;
            TypeDeChambre typeDeChambreChoisi = listeChambres.at(0).getTypeDeChambreAvecString(listeTypesDeChambre.at(choixTypeDeChambre));
            if (hotel.chambreDeCeTypeEstDisponible(typeDeChambreChoisi)) {
                quitChambreReservation = true;
                reservation.setChambreReservation(hotel.reservePremiereChambreDeCeType(typeDeChambreChoisi));
            }
            else {
                std::cout << "Ce type de chambre n'est pas disponible." << std::endl;
            }
        }

        /* Question 9 */
        bool quitClientReservation = false;
        while (!quitClientReservation) {
            std::string nomClientReservation = "";
            std::cout << "Entrer le nom du client :" << std::endl;
            cin >> nomClientReservation;
            std::vector<Client> listeClientsSelectionnes;
            int choixClient = 0;
            Client clientReservation;
            for (Client client : listeClients) {
                if (client.getNomClient() == nomClientReservation) {
                    listeClientsSelectionnes.push_back(client);
                }
            }
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
        /* Question 10 */
        reservation.setHotelReservation(hotel);
        reservation.calculMontantTotal();
        listeReservations.push_back(reservation);
    }

    /* Question 10 */
    for (Reservation reservation : listeReservations) {
        std::cout << "La reservation est : " << listeReservations.at(0).toString() << std::endl;
    }
    return 0;
}
