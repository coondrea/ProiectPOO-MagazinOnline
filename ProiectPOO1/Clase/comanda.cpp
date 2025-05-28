#include "comanda.h"
#include <iostream>

namespace Online_Store {

int Comanda::m_nr_total_comenzi = 0;

Comanda::Comanda() : m_data("N/A"), m_total(0.0) {
    m_id = ++m_nr_total_comenzi;
}

Comanda::Comanda(const std::vector<std::shared_ptr<Produs>>& produse, const std::string& data)
    : m_produse(produse), m_data(data) {
    m_id = ++m_nr_total_comenzi;
    _CalculeazaTotal();
}

Comanda::~Comanda() {}

void Comanda::_CalculeazaTotal() {
    m_total = 0.0;
    for (const auto& p : m_produse) {
        m_total += p->GetPret();
    }
}

int Comanda::GetId() const {
    return m_id;
}

double Comanda::GetTotal() const {
    return m_total;
}

std::string Comanda::GetData() const {
    return m_data;
}

void Comanda::AfiseazaComanda() const {
    std::cout << "Comanda #" << m_id << " din data " << m_data << ":\n";
    for (const auto& p : m_produse) {
        std::cout << *p << "\n";
    }
    std::cout << "Total comanda: " << m_total << " lei\n";
}

} // namespace Online_Store
