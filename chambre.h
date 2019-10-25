#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>


enum TypeDeChambre {
    Simple,
    Double,
    Suite
};

class Chambre {

private:
    int identifiantChambre;
    TypeDeChambre typeDeChambre;
    double prixParNuit;

private:
    std::string getTypeDeChambreToString();

public:
    Chambre();
    Chambre(int identifiantChambre, TypeDeChambre typeDeChambre, double prixParNuit);
    TypeDeChambre getTypeDeChambre() const;
    void setTypeDeChambre(TypeDeChambre typeDeChambre);
    double getPrixParNuit() const;
    void setPrixParNuit(double prixParNuit);
    std::string toString();
};

#endif // CHAMBRE_H
