#ifndef PRODUS_ELECTRONIC_H
#define PRODUS_ELECTRONIC_H

#include "produs.h"

namespace Online_Store {

class ProdusElectronic : public Produs {
private:
    int m_garantie_luni;

    void _ValidareGarantie(int luni);

public:
    ProdusElectronic();
    ProdusElectronic(int id, const std::string& nume, const std::string& categorie,
                     double pret, int stoc, int garantie);
    ~ProdusElectronic();

    int GetGarantie() const;
    void SetGarantie(int luni);

    void AfiseazaDetalii() const override;
    std::string GetDescriereDetaliata() const override;
};

} // namespace Online_Store

#endif
