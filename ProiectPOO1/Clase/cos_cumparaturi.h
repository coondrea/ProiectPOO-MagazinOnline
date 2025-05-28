#ifndef COS_CUMPARATURI_H
#define COS_CUMPARATURI_H

#include "produs.h"
#include <vector>
#include <memory>

namespace Online_Store {

class CosCumparaturi {
private:
    std::vector<std::shared_ptr<Produs>> m_produse;
    double m_total;

    void _ActualizeazaTotal();

public:
    CosCumparaturi();

    void AdaugaProdus(const std::shared_ptr<Produs>& produs);
    void StergeProdus(int id_produs);
    void GolesteCosul();
    void AfiseazaCos() const;
    double GetTotal() const;
    int GetNrProduse() const;
    bool EsteGol() const;
};

} // namespace Online_Store

#endif
