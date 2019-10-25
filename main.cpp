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
    std::vector<Chambre> listeChambre;
    for (int i = 0; i < 10; i++) {
        if (i < 3) {
            listeChambre.push_back(Chambre(i, TypeDeChambre::Simple, 100.0));
        }
        else if (i < 8) {
            listeChambre.push_back(Chambre(i, TypeDeChambre::Double, 125.0));
        }
        else {
            listeChambre.push_back(Chambre(i, TypeDeChambre::Suite, 210.0));
        }
    }
    Hotel hotel("HOTEL", "Nom", "Ville", listeChambre);
    cout << "L'hotel est : " << hotel.toString() << endl;
    std::vector<Client> listeClient;
    for (int i = 0; i < 10; i++) {
        listeClient.push_back(Client("Client" + std::to_string(i), "Client" + std::to_string(i), "Client" + std::to_string(i), 0));
    }
    for (int i = 0; i < 10; i++) {
        std::cout << listeClient.at(i).toString() << std::endl;
    }
    return 0;

    /* Question 7 */
    
}
