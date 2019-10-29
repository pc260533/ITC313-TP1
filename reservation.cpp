#include "reservation.h"

double Reservation::calculMontantTotal() {
    this->montantTotal = this->chambreReservation.getPrixParNuit() * this->dateDebutReservation.nombreDeJoursAvecCetteDate(this->dateFinReservation);
    return this->montantTotal;
}

int Reservation::getIdentifiantReservatin() const {
    return this->identifiantReservation;
}

Date Reservation::getDateDebutReservation() const {
    return this->dateDebutReservation;
}

Date Reservation::getDateFinReservation() const {
    return this->dateFinReservation;
}

Chambre Reservation::getChambreReservation() const {
    return this->chambreReservation;
}

void Reservation::setChambreReservation(Chambre chambreReservation) {
    this->chambreReservation = chambreReservation;
}

Client Reservation::getClientReservation() const {
    return this->clientReservation;
}

void Reservation::setClientReservation(Client clientReservation) {
    this->clientReservation = clientReservation;
}

double Reservation::getMontantTotal() const {
    return this->montantTotal;
}

Reservation::Reservation()
    : identifiantReservation(0), dateDebutReservation(Date()), dateFinReservation(Date()), chambreReservation(Chambre()), clientReservation(Client()), montantTotal(0.0) {

}

Reservation::Reservation(int identifiantReservation)
    : identifiantReservation(identifiantReservation), dateDebutReservation(Date()), dateFinReservation(Date()), chambreReservation(Chambre()), clientReservation(Client()), montantTotal(0.0) {

}

Reservation::Reservation(int identifiantReservation, Chambre chambreReservation, Client clientReservation)
    : identifiantReservation(identifiantReservation), dateDebutReservation(Date()), dateFinReservation(Date()), chambreReservation(chambreReservation), clientReservation(clientReservation), montantTotal(0.0) {
    this->clientReservation.ajouterReservation();
}

bool Reservation::setPeriodeDeReservation(Date dateDebut, Date dateFin) {
    bool res = false;
    if (dateDebut.estAvantDate(dateFin)) {
        res = true;
        this->dateDebutReservation = dateDebut;
        this->dateFinReservation = dateFin;
    }
    this->calculMontantTotal();
    return res;
}

std::string Reservation::toString() {
    std::string res =  "L'id de la reservation est : " + std::to_string(this->identifiantReservation) + "\n"
            + "La date de début de la reservation est : " + this->dateDebutReservation.toString() + "\n"
            + "La date de fin de la reservation est : " + this->dateFinReservation.toString() + "\n"
            + "La chambre de la reservation est : " + this->chambreReservation.toString() + "\n"
            + "La client de la reservation est : " + this->clientReservation.toString() + "\n"
            + "Le montant total de la reservation est : " + std::to_string(this->montantTotal);
    return res;
}

