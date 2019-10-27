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

std::vector<Chambre> Hotel::getListeChambresHotel() const {
    return this->listeChambresHotel;
}

void Hotel::setListeChambresHotel(std::vector<Chambre> listeChambresHotel) {
    this->listeChambresHotel = listeChambresHotel;
}

Hotel::Hotel() : identifiantHotel(""), nomHotel(""), villeHotel(""), listeChambresHotel(std::vector<Chambre>()) {

}

Hotel::Hotel(std::string identifiantHotel, std::string nomHotel, std::string villeHotel, std::vector<Chambre> listeChambresHotel)
    : identifiantHotel(identifiantHotel), nomHotel(nomHotel), villeHotel(villeHotel), listeChambresHotel(listeChambresHotel) {

}

void Hotel::ajouterChambre(Chambre chambre) {
    this->listeChambresHotel.push_back(chambre);
}

void Hotel::supprimerChambre(Chambre chambre) {
    //this->listeChambresHotel.erase(std::remove(this->listeChambresHotel.begin(), this->listeChambresHotel.end(), chambre), this->listeChambresHotel.end());
}

bool Hotel::chambreDeCeTypeEstDisponible(TypeDeChambre typeDeChambre) {
    bool res = false;
    for (Chambre chambre : this->listeChambresHotel) {
        if ((!chambre.getEstReserve()) && (chambre.getTypeDeChambre() == typeDeChambre)) {
            res = true;
        }
    }
    return res;
}

Chambre Hotel::reservePremiereChambreDeCeType(TypeDeChambre typeDeChambre) {
    Chambre res;
    bool quit = false;
    int i = 0;
    while (!quit) {
        if (i > this->listeChambresHotel.size()) {
            quit = true;
        }
        else {
            if ((!this->listeChambresHotel.at(i).getEstReserve()) && (this->listeChambresHotel.at(i).getTypeDeChambre() == typeDeChambre)) {
                this->listeChambresHotel.at(i).setEstReserve(true);
                res = this->listeChambresHotel.at(i);
                quit = true;
            }
        }
        i++;
    }
    return res;
}

std::string Hotel::toString() {
    std::string res =  "L'id de l'hotel est : " + this->identifiantHotel + ".\n"
            + "Le nom de l'hotel est : " + this->nomHotel + "\n"
            + "La ville de l'hotel est : " + this->villeHotel + "\n"
            + "La liste des chambres :\n";
    for (Chambre chambre : this->listeChambresHotel) {
        res += chambre.toString() + "\n";
    }
    return res;
}
