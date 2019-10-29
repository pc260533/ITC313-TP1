#include "listedechambres.h"

std::vector<Chambre> ListeDeChambres::getListesChambres() const {
    return this->listesChambres;
}

void ListeDeChambres::setListesChambres(std::vector<Chambre> listesChambres) {
    this->listesChambres = listesChambres;
}

ListeDeChambres::ListeDeChambres() {
    
}

void ListeDeChambres::ajouterChambre(Chambre chambre) {
    this->listesChambres.push_back(chambre);
}

void ListeDeChambres::supprimerChambre(Chambre chambre) {
    this->listesChambres.erase(std::remove(this->listesChambres.begin(), this->listesChambres.end(), chambre));
}

std::string ListeDeChambres::getTypeDeChambreToString(TypeDeChambre typeDeChambre) {
    std::string res = "";
    switch (typeDeChambre) {
        case TypeDeChambre::Simple:
            res = "Simple";
            break;
        case TypeDeChambre::Double:
            res = "Double";
            break;
        case TypeDeChambre::Suite:
            res = "Suite";
            break;
    }
    return res;
}

std::vector<std::string> ListeDeChambres::getListeTypesDeChambre() {
    std::vector<std::string> listeTypesDeChambre;
    listeTypesDeChambre.push_back(this->getTypeDeChambreToString(TypeDeChambre::Simple));
    listeTypesDeChambre.push_back(this->getTypeDeChambreToString(TypeDeChambre::Double));
    listeTypesDeChambre.push_back(this->getTypeDeChambreToString(TypeDeChambre::Suite));
    return listeTypesDeChambre;
}

TypeDeChambre ListeDeChambres::getTypeDeChambreAvecString(std::string typeDeChambre) {
    TypeDeChambre res = TypeDeChambre::Simple;
    if (typeDeChambre == "Simple") {
        res = TypeDeChambre::Simple;
    }
    else if (typeDeChambre == "Double") {
        res = TypeDeChambre::Double;
    }
    else if (typeDeChambre == "Suite") {
        res = TypeDeChambre::Suite;
    }
    return res;
}

std::vector<Chambre> ListeDeChambres::getToutesChambresDeCeType(TypeDeChambre typeDeChambre) {
    std::vector<Chambre> listeChambreDeCeType;
    for (Chambre chambre : this->listesChambres) {
        if (chambre.getTypeDeChambre() == typeDeChambre) {
            listeChambreDeCeType.push_back(chambre);
        }
    }
    return listeChambreDeCeType;
}

std::string ListeDeChambres::toString() {
    std::string res = "";
    for (Chambre chambre : this->listesChambres) {
        res += chambre.toString() + "\n";
    }
    return res;
}
