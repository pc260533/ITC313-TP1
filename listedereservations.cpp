#include "listedereservations.h"
#include "iostream"

bool ListeDeReservations::chambreEstReservePendantUnePeriode(Chambre chambre, Date dateDebut, Date dateFin) {
    bool res = false;
    for (Reservation reservation : this->listeReservations) {
        if ((reservation.getChambreReservation() == chambre) &&
                ((dateDebut.dateEstComprisEntreDeuxDates(reservation.getDateDebutReservation(), reservation.getDateFinReservation(), dateDebut)) ||
                (dateDebut.dateEstComprisEntreDeuxDates(reservation.getDateDebutReservation(), reservation.getDateFinReservation(), dateDebut)) ||
                (dateDebut.estEgale(reservation.getDateDebutReservation())) ||
                (dateFin.estEgale(reservation.getDateFinReservation()))))  {
            res = true;
        }
    }
    return res;
}

Client ListeDeReservations::ClientDeLaChambreQuiEstReservePendantUnePeriode(Chambre chambre, Date dateDebut, Date dateFin) {
    Client client;
    for (Reservation &reservation : this->listeReservations) {
        if ((reservation.getChambreReservation() == chambre) &&
                ((dateDebut.dateEstComprisEntreDeuxDates(reservation.getDateDebutReservation(), reservation.getDateFinReservation(), dateDebut)) ||
                (dateDebut.dateEstComprisEntreDeuxDates(reservation.getDateDebutReservation(), reservation.getDateFinReservation(), dateDebut)) ||
                (dateDebut.estEgale(reservation.getDateDebutReservation())) ||
                (dateFin.estEgale(reservation.getDateFinReservation()))))  {
            client = reservation.getClientReservation();
        }
    }
    return client;
}

Hotel ListeDeReservations::getHotelListeDeReservation() const {
    return this->hotelListeDeReservation;
}

void ListeDeReservations::setHotelListeDeReservation(Hotel hotelListeDeReservation) {
    this->hotelListeDeReservation = hotelListeDeReservation;
}

std::vector<Reservation> ListeDeReservations::getListeReservations() const {
    return this->listeReservations;
}

void ListeDeReservations::setListeReservations(std::vector<Reservation> listeReservations) {
    this->listeReservations = listeReservations;
}

ListeDeReservations::ListeDeReservations() : hotelListeDeReservation(Hotel()) {

}

ListeDeReservations::ListeDeReservations(Hotel hotelListeDeReservation) : hotelListeDeReservation(hotelListeDeReservation) {

}

void ListeDeReservations::ajouterReservation(Reservation reservation) {
    this->listeReservations.push_back(reservation);
}

void ListeDeReservations::supprimerReservation(Reservation reservation) {
    this->listeReservations.erase(std::remove(this->listeReservations.begin(), this->listeReservations.end(), reservation));
}

void ListeDeReservations::modifierDateDeDebutReservation(Reservation *reservation, Date dateDebut) {
    if ((dateDebut.estValide()) && (dateDebut.estAvantDate(reservation->getDateFinReservation())) && (this->chambreEstDisponible(*reservation, dateDebut, reservation->getDateFinReservation()))) {
        reservation->setPeriodeDeReservation(dateDebut, reservation->getDateFinReservation());
    }
}

bool ListeDeReservations::reservationExiste(int identifiantDeReservation) {
    bool res = false;
    for (Reservation reservation : this->listeReservations) {
        if (reservation.getIdentifiantReservatin() == identifiantDeReservation) {
            res = true;
        }
    }
    return res;
}

Reservation ListeDeReservations::getReservationAvecIdentifiantDeReservation(int identifiantDeReservation) {
    Reservation res;
    for (Reservation reservation : this->listeReservations) {
        if (reservation.getIdentifiantReservatin() == identifiantDeReservation) {
            res = reservation;
        }
    }
    return res;
}

Reservation* ListeDeReservations::getReservationModifiableAvecIdentifiantDeReservation(int identifiantDeReservation) {
    Reservation* res = nullptr;
    for (Reservation &reservation : this->listeReservations) {
        if (reservation.getIdentifiantReservatin() == identifiantDeReservation) {
            res = &reservation;
        }
    }
    return res;
}

ListeDeReservations ListeDeReservations::getToutesReservationUnClient(Client client) {
    ListeDeReservations listeDeReservation;
    for (Reservation reservation : this->listeReservations) {
        if (reservation.getClientReservation().getIdentifiantClient() == client.getIdentifiantClient()) {
            listeDeReservation.ajouterReservation(reservation);
        }
    }
    return listeDeReservation;
}

bool ListeDeReservations::chambreEstDisponible(Reservation reservation, Date dateDebut, Date dateFin) {
    bool res = true;
    if (this->chambreEstReservePendantUnePeriode(reservation.getChambreReservation(), dateDebut, dateFin)) {
        Client client = this->ClientDeLaChambreQuiEstReservePendantUnePeriode(reservation.getChambreReservation(), dateDebut, dateFin);
        if (reservation.getClientReservation() != client) {
            res = false;
        }
    }
    return res;
}


bool ListeDeReservations::chambreDeCeTypeEstDisponibleDansHotel(TypeDeChambre typeDeChambre, Date dateDebut, Date dateFin) {
    std::vector<Chambre> listeDesChambresDeCeType = this->hotelListeDeReservation.getListeDeChambresHotel().getToutesChambresDeCeType(typeDeChambre);
    bool res = false;
    for (Chambre chambre : listeDesChambresDeCeType) {
        if (!this->chambreEstReservePendantUnePeriode(chambre, dateDebut, dateFin)) {
            res = true;
        }
    }
    return res;
}

Chambre ListeDeReservations::reservePremiereChambreDeCeTypeDansHotel(TypeDeChambre typeDeChambre, Date dateDebut, Date dateFin) {
    std::vector<Chambre> listeDesChambresDeCeType = this->hotelListeDeReservation.getListeDeChambresHotel().getToutesChambresDeCeType(typeDeChambre);
    Chambre res;
    bool quit = false;
    int i = 0;
    while (!quit) {
        if (i > listeDesChambresDeCeType.size()) {
            quit = true;
        }
        else {
            if (!this->chambreEstReservePendantUnePeriode(listeDesChambresDeCeType.at(i), dateDebut, dateFin)) {
                res = listeDesChambresDeCeType.at(i);
                quit = true;
            }
        }
        i++;
    }
    return res;
}

std::string ListeDeReservations::toString() {
    std::string res = "";
    for (Reservation reservation : this->listeReservations) {
        res += reservation.toString() + "\n";
    }
    return res;
}
