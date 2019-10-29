#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>
#include <iostream>


class Date {

private:
    int jour;
    int mois;
    int annee;

private:
    std::string getJourToString();
    std::string getMoisToString();
    bool anneeEstBissextile(int annee);
    std::vector<int> getListeJourDesMois();
    Date normalise(Date date);

public:
    Date();
    Date(int jour, int mois, int annee);
    bool operator == (const Date& date) const { return ((this->jour == date.jour) && (this->mois == date.mois) && (this->annee == date.annee)); }
    bool operator != (const Date& date) const { return !operator == (date); }
    int getJour() const;
    void setJour(int jour);
    int getMois() const;
    void setMois(int mois);
    int getAnnee() const;
    void setAnnee(int annee);
    void jourProchain();
    void moisProchain();
    void anneeProchain();
    bool estAvantDate(Date date);
    bool estApresDate(Date date);
    bool estValide();
    int nombreDeJoursAvecCetteDate(Date date);
    bool dateEstComprisEntreDeuxDates(Date dateDebut, Date dateFin, Date date);
    bool estEgale(Date date);
    std::string toString();

};

#endif // DATE_H
