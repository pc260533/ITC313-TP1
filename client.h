#ifndef CLIENT_H
#define CLIENT_H

#include <string>


class Client {

private:
    std::string identifiantClient;
    std::string nomClient;
    std::string prenomClient;
    int nombreDeReservation;

public:
    Client();
    Client(std::string identifiantClient, std::string nomClient, std::string prenomClient, int nombreDeReservation);
    bool operator == (const Client& client) const { return ((this->identifiantClient == client.getIdentifiantClient()) && (this->nomClient == client.getNomClient()) && (this->prenomClient == client.getPrenomClient()) && (this->nombreDeReservation == client.getNombreDeReservation())); }
    bool operator != (const Client& client) const { return !operator == (client); }
    std::string getIdentifiantClient() const;
    std::string getNomClient() const;
    void setNomClient(std::string nomClient);
    std::string getPrenomClient() const;
    void setPrenomClient(std::string prenomClient);
    int getNombreDeReservation() const;
    void setNombreDeReservation(int nombreDeReservation);
    void ajouterReservation();
    std::string toString();
};

#endif // CLIENT_H
