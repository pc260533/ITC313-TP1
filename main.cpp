#include <iostream>

#include "chambre.h"
#include "client.h"
 #include "date.h"
#include "hotel.h"

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
    return 0;
}
