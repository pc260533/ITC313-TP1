#ifndef LISTEDERESERVATIONS_H
#define LISTEDERESERVATIONS_H

#include "reservation.h"

#include <vector>
#include <algorithm>



class ListeDeReservations {

private:
    Hotel hotelListeDeReservation;
    std::vector<Reservation> listeReservations;

private:
    bool chambreEstReservePendantUnePeriode(Chambre chambre, Date dateDebut, Date dateFin);

public:
    ListeDeReservations();
    ListeDeReservations(Hotel hotelListeDeReservation);
    Hotel getHotelListeDeReservation() const;
    void setHotelListeDeReservation(Hotel hotel);
    std::vector<Reservation> getListeReservations() const;
    void setListeReservations(std::vector<Reservation> listeReservations);
    void ajouterReservation(Reservation reservation);
    void supprimerReservation(Reservation reservation);
    Reservation getReservationAvecIdentifiantDeReservation(int identifiantDeReservation);
    ListeDeReservations getToutesReservationUnClient(Client client);
    bool chambreDeCeTypeEstDisponibleDansHotel(TypeDeChambre typeDeChambre, Date dateDebut, Date dateFin);
    Chambre reservePremiereChambreDeCeTypeDansHotel(TypeDeChambre typeDeChambre, Date dateDebut, Date dateFin);
    std::string toString();

};

#endif // LISTEDERESERVATIONS_H
