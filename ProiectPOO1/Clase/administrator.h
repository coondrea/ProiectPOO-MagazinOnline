#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "utilizator.h"

namespace Online_Store {

/*
 * Clasa Administrator mosteneste clasa Utilizator
 * si adauga un atribut suplimentar: departamentul.
 * Este folosita pentru a simula rolul de administrator in cadrul magazinului online.
 */
class Administrator : public Utilizator {
private:
    std::string m_departament;  // Numele departamentului in care activeaza administratorul

public:
    // Constructor implicit
    Administrator();

    // Constructor cu parametri pentru initializarea completa a unui administrator
    Administrator(int id, const std::string& nume_utilizator, const std::string& email, const std::string& departament);

    // Suprascrie metoda virtuala din clasa Utilizator pentru a returna "Administrator"
    std::string GetTipUtilizator() const override;

    // Afiseaza informatiile complete despre administrator
    void AfiseazaProfil() const override;

    // Functii placeholder pentru adaugarea si stergerea produselor din magazin
    void AdaugaProdus();     // Stub - se va implementa cand avem clasa Magazin
    void StergeProdus();     // Stub
};

} // namespace Online_Store

#endif
