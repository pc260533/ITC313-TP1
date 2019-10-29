#ifndef CHAMBRE_H
#define CHAMBRE_H

#include "enumerationTypeDeChambre.h"

#include <string>
#include <vector>



class Chambre {

private:
    int identifiantChambre;
    TypeDeChambre typeDeChambre;
    double prixParNuit;

private:
    std::string getTypeDeChambreToString(TypeDeChambre typeDeChambre);

public:
    Chambre();
    Chambre(int identifiantChambre, TypeDeChambre typeDeChambre, double prixParNuit);
    bool operator == (const Chambre& chambre) const { return ((this->identifiantChambre == chambre.identifiantChambre) && (this->typeDeChambre == chambre.typeDeChambre) && (this->prixParNuit == chambre.prixParNuit)); }
    bool operator != (const Chambre& chambre) const { return !operator == (chambre); }
    TypeDeChambre getTypeDeChambre() const;
    void setTypeDeChambre(TypeDeChambre typeDeChambre);
    double getPrixParNuit() const;
    void setPrixParNuit(double prixParNuit);
    std::string toString();

};

#endif // CHAMBRE_H
