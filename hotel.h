#ifndef HOTEL_H
#define HOTEL_H

#include "chambre.h"

#include <string>
#include <vector>
#include <algorithm>


class Hotel {

private:
    std::string identifiantHotel;
    std::string nomHotel;
    std::string villeHotel;
    std::vector<Chambre> listeChambresHotel;

public:
    Hotel();
    Hotel(std::string identifiantHotel, std::string nomHotel, std::string villeHotel, std::vector<Chambre> listeChambresHotel);
    std::string getNomHotel() const;
    void setNomHotel(const std::string villeHotel);
    std::string getVilleHotel() const;
    void setVilleHotel(const std::string villeHotel);
    std::vector<Chambre> getListeChambresHotel() const;
    void setListeChambresHotel(std::vector<Chambre> listeChambresHotel);
    void ajouterChambre(Chambre chambre);
    void supprimerChambre(Chambre chambre);
    std::string toString();
};

#endif // HOTEL_H
