#include "listedeclients.h"

std::vector<Client> ListeDeClients::getListeClients() const {
    return this->getListeClients();
}

void ListeDeClients::setListeClients(std::vector<Client> listeClients) {
    this->getListeClients() = listeClients;
}

ListeDeClients::ListeDeClients() {

}

void ListeDeClients::ajouterClient(Client client) {
    this->listeClients.push_back(client);
}

void ListeDeClients::supprimerClient(Client client) {
    this->listeClients.erase(std::remove(this->listeClients.begin(), this->listeClients.end(), client));
}

Client ListeDeClients::getClientAvecIdentifiantDeClient(std::string identifiantDeClient) {
    Client res;
    for (Client client : this->listeClients) {
        if (client.getIdentifiantClient() == identifiantDeClient) {
            res = client;
        }
    }
    return res;
}

std::vector<Client> ListeDeClients::getTousLesClientsAvecNomDeClient(std::string nomDeClient) {
    std::vector<Client> listeClientsDeCeNom;
    for (Client client : this->listeClients) {
        if (client.getNomClient() == nomDeClient) {
            listeClientsDeCeNom.push_back(client);
        }
    }
    return listeClientsDeCeNom;
}

std::string ListeDeClients::toString() {
    std::string res = "";
    for (Client client : this->listeClients) {
        res += client.toString() + "\n";
    }
    return res;
}
