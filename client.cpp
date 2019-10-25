#include "client.h"

std::string Client::getNomClient() const {
    return this->nomClient;
}

void Client::setNomClient(std::string nomClient) {
    this->nomClient = nomClient;
}

std::string Client::getPrenomClient() const {
    return this->prenomClient;
}

void Client::setPrenomClient(std::string prenomClient) {
    this->prenomClient = prenomClient;
}

int Client::getNombreDeReservation() const {
    return this->nombreDeReservation;
}

void Client::setNombreDeReservation(int nombreDeReservation) {
    this->nombreDeReservation = nombreDeReservation;
}

Client::Client() : identifiantClient(""), nomClient(""), prenomClient(""), nombreDeReservation(0) {

}

Client::Client(std::string identifiantClient, std::string nomClient, std::string prenomClient, int nombreDeReservation)
    : identifiantClient(identifiantClient), nomClient(nomClient), prenomClient(prenomClient), nombreDeReservation(nombreDeReservation) {

}

void Client::ajouterReservation() {
    this->nombreDeReservation++;
}

std::string Client::toString() {
    return this->nomClient + " " + this->prenomClient + " a " + std::to_string(this->nombreDeReservation) +  " reservations.";

}

