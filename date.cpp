#include "date.h"

std::string Date::getMoisToString() {
    std::vector<std::string> listeMoisDeLAnnee({"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"});
    return listeMoisDeLAnnee.at(this->mois - 1);
}

bool Date::anneeEstBissextile(int annee) {
    return (((annee % 4 == 0) && (annee % 100 != 0)) || (annee % 400 == 0));
}

std::vector<int> Date::getListeJourDesMois() {
    return std::vector<int>({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
}

Date Date::normalise(Date date) {
    std::vector<int> listeJourMois({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    if (((date.getAnnee() % 4 == 0) && (date.getAnnee() % 100 != 0)) || (date.getAnnee() % 400 == 0)) {
        listeJourMois.at(1) = 29;
    }
    if (date.getJour() > listeJourMois.at(date.getMois() - 1)) {
        date.setMois(date.getMois()+1);
        date.setJour(1);
    }
    if (date.getMois() > 12) {
        date.setAnnee(date.getAnnee()+1);
        date.setMois(1);
    }
    return date;
}

int Date::getJour() const {
    return this->jour;
}

void Date::setJour(int jour) {
    this->jour = jour;
}

int Date::getMois() const {
    return this->mois;
}

void Date::setMois(int mois) {
    this->mois = mois;
}

int Date::getAnnee() const {
    return this->annee;
}

void Date::setAnnee(int annee) {
    this->annee = annee;
}

Date::Date() : jour(1), mois(1), annee(2019) {

}

Date::Date(int jour, int mois, int annee) : jour(jour), mois(mois), annee(annee)  {

}

void Date::jourProchain() {
    std::vector<int> listeJourDesMois({31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31});
    if (((this->annee % 4 == 0) && (this->annee % 100 != 0)) || (this->annee % 400 == 0)) {
        listeJourDesMois.at(1) = 29;
    }
    this->jour++;
    if (this->jour > listeJourDesMois.at(this->mois - 1)) {
        this->mois++;
        this->jour = 1;
    }
    if (this->mois > 12) {
        this->annee++;
        this->mois = 1;
    }
}

void Date::moisProchain() {
    if (this->mois == 12) {
        this->mois = 1;
    }
    else {
        this->mois++;
    }
}

void Date::anneeProchain() {
    this->annee++;
}

bool Date::estAvantDate(Date date) {
    bool res = false;
    if (this->mois < date.mois) {
        res = true;
    }
    if ((this->mois == date.mois) && (this->jour < date.jour)) {
        res = true;
    }
    return res;
}

bool Date::estApresDate(Date date) {
    bool res = false;
    if (this->mois > date.mois) {
        res = true;
    }
    if ((this->mois == date.mois) && (this->jour > date.jour)) {
        res = true;
    }
    return res;
}

bool Date::estEgale(Date date) {
    return ((this->getMois() == date.getMois()) && (this->getAnnee() == date.getAnnee()) && (this->getJour() == date.getJour()));
}

bool Date::estValide() {
    Date date(this->getJour(), this->getMois(), this->getAnnee());
    return this->estEgale(this->normalise(date));
}

int Date::nombreDeJoursAvecCetteDate(Date date) {
    int res = 0;
    if (this->estAvantDate(date)) {
        if (this->annee < date.annee) {
            for (int i = this->annee; i < date.annee; i++) {
                res += 365;
                if (this->anneeEstBissextile(i)) {
                    res++;
                }
            }
            //std::cout << "annee" << std::to_string(res) << std::endl;
            return res += this->nombreDeJoursAvecCetteDate(Date(date.jour, date.mois, this->annee));
        }
        if (this->mois < date.mois) {
            for (int i = this->mois; i < date.mois; i++) {
                res += this->getListeJourDesMois().at(i - 1);
                if ((this->anneeEstBissextile(date.annee)) && (i == 1)) {
                    res++;
                }
            }
            //std::cout << "mois inf" << std::to_string(res) << std::endl;
            return res += this->nombreDeJoursAvecCetteDate(Date(date.jour, this->mois, this->annee));
        }
        else if (this->mois > date.mois) {
            for (int i = this->mois; i < date.mois; i++) {
                res -= this->getListeJourDesMois().at(i - 1);
                if ((this->anneeEstBissextile(date.annee)) && (i == 1)) {
                    res--;
                }
            }
            //std::cout << "mois sup" << std::to_string(res) << std::endl;
            return res += this->nombreDeJoursAvecCetteDate(Date(date.jour, this->mois, this->annee));
        }
        if (this->jour < date.jour) {
            res += date.jour - this->jour;
            //std::cout << "jour inf" << std::to_string(res) << std::endl;
            return res += this->nombreDeJoursAvecCetteDate(Date(this->jour, this->mois, this->annee));
        }
        else if (this->jour > date.jour) {
            res -= this->jour - date.jour;
            //std::cout << "jour supp" << std::to_string(res) << std::endl;
            return res += this->nombreDeJoursAvecCetteDate(Date(this->jour, this->mois, this->annee));
        }
    }
    return res;
}

bool Date::dateEstComprisEntreDeuxDates(Date dateDebut, Date dateFin, Date date) {
    bool res = false;
    if (date.estApresDate(dateDebut)) {
        if (dateDebut.nombreDeJoursAvecCetteDate(date) < dateDebut.nombreDeJoursAvecCetteDate(dateFin)) {
            res = true;
        }
    }
    return res;
}

std::string Date::toString() {
    return std::to_string(this->jour) + " " + this->getMoisToString() + " " + std::to_string(this->annee);
}

