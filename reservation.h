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
    Chambre chambreReservation;
    Client clientReservation;
    double montantTotal;

public:
    Reservation();
    Reservation(int identifiantReservation);
    Reservation(int identifiantReservation, Chambre chambreReservation, Client clientReservation);
    bool operator == (const Reservation& reservation) const {
        return ((this->identifiantReservation == reservation.getIdentifiantReservatin()) &&
                (this->dateDebutReservation == reservation.getDateDebutReservation()) &&
                (this->dateFinReservation == reservation.getDateFinReservation()) &&
                (this->chambreReservation == reservation.getChambreReservation()) &&
                (this->clientReservation == reservation.getClientReservation()) &&
                (this->montantTotal == reservation.getMontantTotal()));
    }
    bool operator != (const Reservation& reservation) const { return !operator == (reservation); }
    int getIdentifiantReservatin() const;
    Date getDateDebutReservation() const;
    Date getDateFinReservation() const;
    Chambre getChambreReservation() const;
    void setChambreReservation(Chambre chambreReservation);
    Client getClientReservation() const;
    void setClientReservation(Client clientReservation);
    double getMontantTotal() const;
    double calculMontantTotal();
    bool setPeriodeDeReservation(Date dateDebut, Date dateFin);
    std::string toString();

};

#endif // RESERVATION_H
