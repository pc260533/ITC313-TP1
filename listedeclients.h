#ifndef LISTESDECLIENTS_H
#define LISTESDECLIENTS_H

#include "client.h"

#include <vector>
#include <algorithm>



class ListeDeClients {

private:
    std::vector<Client> listeClients;

public:
    ListeDeClients();
    std::vector<Client> getListeClients() const;
    void setListeClients(std::vector<Client> listeClients);
    void ajouterClient(Client client);
    void supprimerClient(Client client);
    Client getClientAvecIdentifiantDeClient(std::string identifiantDeClient);
    std::vector<Client> getTousLesClientsAvecNomDeClient(std::string nomDeClient);
    std::string toString();
};

#endif // LISTESDECLIENTS_H
