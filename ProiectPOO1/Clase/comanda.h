#ifndef COMANDA_H
#define COMANDA_H

#include "produs.h"
#include <vector>
#include <memory>
#include <string>

namespace Online_Store {

class Comanda {
private:
    static int m_nr_total_comenzi;
    int m_id;
    std::vector<std::shared_ptr<Produs>> m_produse;
    std::string m_data;
    double m_total;

    void _CalculeazaTotal();

public:
    Comanda();
    Comanda(const std::vector<std::shared_ptr<Produs>>& produse, const std::string& data);
    ~Comanda();

    int GetId() const;
    double GetTotal() const;
    std::string GetData() const;
    void AfiseazaComanda() const;
};

} // namespace Online_Store

#endif
