#include "hotel.h"

std::string Hotel::getNomHotel() const {
    return this->nomHotel;
}

void Hotel::setNomHotel(std::string nomHotel) {
    this->nomHotel = nomHotel;
}

std::string Hotel::getVilleHotel() const {
    return this->villeHotel;
}

void Hotel::setVilleHotel(std::string villeHotel) {
    this->villeHotel = villeHotel;
}

ListeDeChambres Hotel::getListeDeChambresHotel() const {
    return this->listeDeChambresHotel;
}

void Hotel::setListeDeChambresHotel(ListeDeChambres listeDeChambresHotel) {
    this->listeDeChambresHotel = listeDeChambresHotel;
}

Hotel::Hotel() : identifiantHotel(""), nomHotel(""), villeHotel(""), listeDeChambresHotel(ListeDeChambres()) {

}

Hotel::Hotel(std::string identifiantHotel, std::string nomHotel, std::string villeHotel, ListeDeChambres listeDeChambresHotel)
    : identifiantHotel(identifiantHotel), nomHotel(nomHotel), villeHotel(villeHotel), listeDeChambresHotel(listeDeChambresHotel) {

}

void Hotel::ajouterChambre(Chambre chambre) {
    this->listeDeChambresHotel.ajouterChambre(chambre);
}

void Hotel::supprimerChambre(Chambre chambre) {
    this->listeDeChambresHotel.supprimerChambre(chambre);
}

std::string Hotel::toString() {
    std::string res =  "L'id de l'hotel est : " + this->identifiantHotel + ".\n" +
            "Le nom de l'hotel est : " + this->nomHotel + "\n" +
            "La ville de l'hotel est : " + this->villeHotel + "\n" +
            "La liste de chambres : " + this->listeDeChambresHotel.toString();
    return res;
}
