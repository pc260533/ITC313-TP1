#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
#include <vector>


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
    bool estReserve;

private:
    std::string getTypeDeChambreToString(TypeDeChambre typeDeChambre);

public:
    Chambre();
    Chambre(int identifiantChambre, TypeDeChambre typeDeChambre, double prixParNuit);
    TypeDeChambre getTypeDeChambre() const;
    void setTypeDeChambre(TypeDeChambre typeDeChambre);
    double getPrixParNuit() const;
    void setPrixParNuit(double prixParNuit);
    bool getEstReserve() const;
    void setEstReserve(bool estReserve);
    std::vector<std::string> getListeTypesDeChambre();
    TypeDeChambre getTypeDeChambreAvecString(std::string typeDeChambre);
    std::string toString();

};

#endif // CHAMBRE_H
