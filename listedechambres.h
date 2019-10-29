#ifndef LISTEDECHAMBRES_H
#define LISTEDECHAMBRES_H

#include "chambre.h"

#include <vector>
#include <algorithm>



class ListeDeChambres {

private:
    std::vector<Chambre> listesChambres;

public:
    ListeDeChambres();
    std::vector<Chambre> getListesChambres() const;
    void setListesChambres(std::vector<Chambre> listeChambres);
    void ajouterChambre(Chambre chambre);
    void supprimerChambre(Chambre chambre);
    std::vector<std::string> getListeTypesDeChambre();
    std::string getTypeDeChambreToString(TypeDeChambre typeDeChambre);
    TypeDeChambre getTypeDeChambreAvecString(std::string typeDeChambre);
    std::vector<Chambre> getToutesChambresDeCeType(TypeDeChambre typeDeChambre);
    std::string toString();

};

#endif // LISTEDECHAMBRES_H
