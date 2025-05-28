#include "cos_cumparaturi.h"
#include <iostream>

namespace Online_Store {

CosCumparaturi::CosCumparaturi() : m_total(0.0) {}

void CosCumparaturi::_ActualizeazaTotal() {
    m_total = 0.0;
    for (const auto& p : m_produse) {
        m_total += p->GetPret();
    }
}

void CosCumparaturi::AdaugaProdus(const std::shared_ptr<Produs>& produs) {
    m_produse.push_back(produs);
    _ActualizeazaTotal();
}

void CosCumparaturi::StergeProdus(int id_produs) {
    m_produse.erase(
        std::remove_if(m_produse.begin(), m_produse.end(),
                       [id_produs](const std::shared_ptr<Produs>& p) {
                           return p->GetId() == id_produs;
                       }),
        m_produse.end());
    _ActualizeazaTotal();
}

void CosCumparaturi::GolesteCosul() {
    m_produse.clear();
    m_total = 0.0;
}

void CosCumparaturi::AfiseazaCos() const {
    if (m_produse.empty()) {
        std::cout << "Cosul este gol.\n";
        return;
    }

    std::cout << "Produse in cos:\n";
    for (const auto& p : m_produse) {
        std::cout << *p << "\n";
    }
    std::cout << "Total: " << m_total << " lei\n";
}

double CosCumparaturi::GetTotal() const {
    return m_total;
}

int CosCumparaturi::GetNrProduse() const {
    return static_cast<int>(m_produse.size());
}

bool CosCumparaturi::EsteGol() const {
    return m_produse.empty();
}

} // namespace Online_Store
