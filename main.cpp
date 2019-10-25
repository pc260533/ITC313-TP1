#include <iostream>

#include "chambre.h"
#include "client.h"
#include "date.h"
#include "hotel.h"
#include "reservation.h"

using namespace std;

int main() {
    /* Question 1
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
    
    /* Question 5 */
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
    reservation.setPeriodeDeReservation(date1, date2);
    reservation.getMontantTotal();
    cout <<  "La reservation est : " << reservation.toString() << endl;

    return 0;
}
