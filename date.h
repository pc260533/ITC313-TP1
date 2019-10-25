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

public:
    Date();
    Date(int jour, int mois, int annee);
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
    int nombreDeJoursAvecCetteDate(Date date);
    std::string toString();

};

#endif // DATE_H
