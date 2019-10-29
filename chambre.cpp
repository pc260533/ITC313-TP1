#include "chambre.h"

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

Chambre::Chambre() : identifiantChambre(0), typeDeChambre(TypeDeChambre::Simple), prixParNuit(0.0) {

}

Chambre::Chambre(int identifiantChambre, TypeDeChambre typeDeChambre, double prixParNuit)
    : identifiantChambre(identifiantChambre), typeDeChambre(typeDeChambre), prixParNuit(prixParNuit) {

}

std::string Chambre::toString() {
    return "L'id de la chambre est : " + std::to_string(this->identifiantChambre) + ".\n"
            + "Le type de la chambre est : " + this->getTypeDeChambreToString(this->typeDeChambre) + "\n"
            + "Le prix par nuit de la chambre est : " + std::to_string(this->prixParNuit);
}
