#include "chambre.h"

TypeDeChambre Chambre::getTypeDeChambre() const {
    return this->typeDeChambre;
}

void Chambre::setTypeDeChambre(TypeDeChambre typeDeChambre) {
    this->typeDeChambre = typeDeChambre;
}

double Chambre::getPrixParNuit() const {
    return this->prixParNuit;
}

void Chambre::setPrixParNuit(double prixParNuit) {
    this->prixParNuit = prixParNuit;
}

bool Chambre::getEstReserve() const {
    return this->estReserve;
}

void Chambre::setEstReserve(bool estReserve) {
    this->estReserve = estReserve;
}

std::string Chambre::getTypeDeChambreToString(TypeDeChambre typeDeChambre) {
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

Chambre::Chambre() : identifiantChambre(0), typeDeChambre(TypeDeChambre::Simple), prixParNuit(0.0), estReserve(false) {

}

Chambre::Chambre(int identifiantChambre, TypeDeChambre typeDeChambre, double prixParNuit)
    : identifiantChambre(identifiantChambre), typeDeChambre(typeDeChambre), prixParNuit(prixParNuit), estReserve(false) {

}

std::vector<std::string> Chambre::getListeTypesDeChambre() {
    std::vector<std::string> listeTypesDeChambre;
    listeTypesDeChambre.push_back(this->getTypeDeChambreToString(TypeDeChambre::Simple));
    listeTypesDeChambre.push_back(this->getTypeDeChambreToString(TypeDeChambre::Double));
    listeTypesDeChambre.push_back(this->getTypeDeChambreToString(TypeDeChambre::Suite));
    return listeTypesDeChambre;
}

TypeDeChambre Chambre::getTypeDeChambreAvecString(std::string typeDeChambre) {
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

std::string Chambre::toString() {
    return "L'id de la chambre est : " + std::to_string(this->identifiantChambre) + ".\n"
            + "Le type de la chambre est : " + this->getTypeDeChambreToString(this->typeDeChambre) + "\n"
            + "Le prix par nuit de la chambre est : " + std::to_string(this->prixParNuit) + "\n"
            + "La chambre est reserve : " + std::to_string(this->estReserve);
}
