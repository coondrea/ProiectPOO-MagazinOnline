#ifndef PRODUS_ELECTRONIC_H
#define PRODUS_ELECTRONIC_H

#include "produs.h"

namespace Online_Store {

// Clasa care reprezinta un produs electronic derivat din clasa de baza Produs
class ProdusElectronic : public Produs {
private:
    int m_garantie_luni; // numarul de luni garantie

    
    void _ValidareGarantie(int luni);

public:
    
    ProdusElectronic();
    ProdusElectronic(int id, const std::string& nume, const std::string& categorie,
                     double pret, int stoc, int garantie);
    ~ProdusElectronic();

    // Returneaza numarul de luni garantie
    int GetGarantie() const;

    // Seteaza valoarea garantiei dupa validare
    void SetGarantie(int luni);

    // Afiseaza detaliile complete ale produsului (suprascriere metoda virtuala)
    void AfiseazaDetalii() const override;

    // Returneaza o descriere detaliata a produsului (suprascriere metoda virtuala)
    std::string GetDescriereDetaliata() const override;
};

} // namespace Online_Store

#endif

