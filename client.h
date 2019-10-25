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
