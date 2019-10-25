#ifndef RESERVATION_H
#define RESERVATION_H

#include "client.h"
#include "date.h"
#include "hotel.h"

#include <string>


class Reservation {

private:
    int identifiantReservation;
    Date dateDebutReservation;
    Date dateFinReservation;
    Hotel hotelReservation;
    Chambre chambreReservation;
    Client clientReservation;
    double montantTotal;

public:
    Reservation();
    Reservation(int identifiantReservation, Hotel hotelReservation, Chambre chambreReservation, Client clientReservation);
    Date getDateDebutReservation() const;
    Date getDateFinReservation() const;
    Hotel getHotelReservation() const;
    void setHotelReservation(Hotel hotelReservation);
    Chambre getChambreReservation() const;
    void setChambreReservation(Chambre chambreReservation);
    Client getClientReservation() const;
    void setClientReservation(Client clientReservation);
    bool setPeriodeDeReservation(Date dateDebut, Date dateFin);
    double getMontantTotal();
    std::string toString();

};

#endif // RESERVATION_H
