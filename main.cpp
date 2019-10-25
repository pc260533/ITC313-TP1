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
    cout << "La date est de : " << date.toString() << endl;
    cout << "La date bissextile est de : " << dateBissextile.toString() << endl;
    date.jourProchain();
    dateBissextile.jourProchain();
    cout << "La date est de : " << date.toString() << endl;
    cout << "La date bissextile est de : " << dateBissextile.toString() << endl;
    */

    /* Question 2
    Client client("1", "Chassagne", "Pierre-Nicolas", 0);
    cout << "La client est : " << client.toString() << endl;
    client.setNomClient("Polybe");
    client.setPrenomClient("Polybe");
    client.ajouterReservation();
    cout << "La client est : " << client.toString() << endl;
    */

    /* Question 3
    Chambre chambre(1,TypeDeChambre::Simple, 10.0);
    cout << "La chambre est : " << chambre.toString() << endl;
    */

    /* Question 4
    Chambre chambre1(1,TypeDeChambre::Simple, 10.0);
    cout << "La chambre est : " << chambre1.toString() << endl << endl;
    Chambre chambre2(2,TypeDeChambre::Double, 20.0);
    cout << "La chambre est : " << chambre2.toString() << endl << endl;
    std::vector<Chambre> listeChambre;
    listeChambre.push_back(chambre1);
    listeChambre.push_back(chambre2);
    Hotel hotel("HOTEL", "Nom", "Ville", listeChambre);
    cout << "L'hotel est : " << hotel.toString() << endl;
    */
    
    /* Question 5 
    Date date1(2, 6, 2019);
    Date date2(3, 8, 2021);
    cout << date1.nombreDeJoursAvecCetteDate(date2) << endl;
    
    Chambre chambre1(1,TypeDeChambre::Simple, 10.0);
    cout << "La chambre est : " << chambre1.toString() << endl << endl;
    Chambre chambre2(2,TypeDeChambre::Double, 20.0);
    cout << "La chambre est : " << chambre2.toString() << endl << endl;
    
    std::vector<Chambre> listeChambre;
    listeChambre.push_back(chambre1);
    listeChambre.push_back(chambre2);
    Hotel hotel("HOTEL", "Nom", "Ville", listeChambre);
    cout << "L'hotel est : " << hotel.toString() << endl;
    
    Client client("1", "Chassagne", "Pierre-Nicolas", 0);

    Reservation reservation(0, hotel, chambre1, client);
    reservation.setPeriodeDeReservation(date1, date2);;
    cout <<  "La reservation est : " << reservation.toString() << endl;
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
    cout << "L'hotel est : " << hotel.toString() << endl;
    std::vector<Client> listeClients;
    for (int i = 0; i < 10; i++) {
        listeClients.push_back(Client("Client" + std::to_string(i), "Client" + std::to_string(i), "Client" + std::to_string(i), 0));
    }
    for (int i = 0; i < 10; i++) {
        std::cout << listeClients.at(i).toString() << std::endl;
    }

    /* Question 7 */
    std::vector<Reservation> listeReservations;

    for(int i = 0; i < 1; i++) {
        Reservation reservation(i,hotel,hotel.getListeChambresHotel().at(i),listeClients.at(i));
        bool quit = false;
        while (!quit) {
            int jourDebut, jourFin, moisDebut, moisFin, anneeDebut, anneeFin;
            cout << "Jour de debut : ";
            cin >> jourDebut;
            cout << "Mois de debut : ";
            cin >> moisDebut;
            cout << "Annee de debut : ";
            cin >> anneeDebut;
            cout << "Jour de fin : ";
            cin >> jourFin;
            cout << "Mois de fin : ";
            cin >> moisFin;
            cout << "Annee de fin : ";
            cin >> anneeFin;
            Date dateDebut(jourDebut, moisDebut, anneeDebut);
            Date dateFin(jourFin, moisFin, anneeFin);
            if ((dateDebut.estValide()) && (dateFin.estValide()) && (reservation.setPeriodeDeReservation(dateDebut, dateFin))) {
                quit = true;
            }
        }
        listeReservations.push_back(reservation);
    }

    cout << listeReservations.at(0).toString() << std::endl;


    return 0;
}
