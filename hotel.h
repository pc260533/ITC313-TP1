#ifndef HOTEL_H
#define HOTEL_H

#include "chambre.h"
#include "listedechambres.h"

#include <string>



class Hotel {

private:
    std::string identifiantHotel;
    std::string nomHotel;
    std::string villeHotel;
    ListeDeChambres listeDeChambresHotel;

public:
    Hotel();
    Hotel(std::string identifiantHotel, std::string nomHotel, std::string villeHotel, ListeDeChambres listeDeChambresHotel);
    std::string getNomHotel() const;
    void setNomHotel(const std::string villeHotel);
    std::string getVilleHotel() const;
    void setVilleHotel(const std::string villeHotel);
    ListeDeChambres getListeDeChambresHotel() const;
    void setListeDeChambresHotel(ListeDeChambres listeChambresHotel);
    void ajouterChambre(Chambre chambre);
    void supprimerChambre(Chambre chambre);
    std::string toString();
};

#endif // HOTEL_H
