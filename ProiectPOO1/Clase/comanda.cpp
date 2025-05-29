#include "comanda.h"
#include <iostream>

namespace Online_Store {

// Initializare a variabilei statice care contorizeaza comenzile
int Comanda::m_nr_total_comenzi = 0;

// Constructor implicit.Seteaza data ca "N/A", totalul pe 0 si genereaza un ID unic pentru comanda. 
Comanda::Comanda() : m_data("N/A"), m_total(0.0) {
    m_id = ++m_nr_total_comenzi;
}

// Constructor cu parametri.Primeste o lista de produse si data comenzii, seteaza campurile si calculeaza totalul. 
Comanda::Comanda(const std::vector<std::shared_ptr<Produs>>& produse, const std::string& data)
    : m_produse(produse), m_data(data) {
    m_id = ++m_nr_total_comenzi;
    _CalculeazaTotal();
}

// Destructorul comenzii (nu efectueaza actiuni explicite)
Comanda::~Comanda() {}

// Functie privata pentru calculul totalului comenzii pe baza pretului fiecarui produs. 
void Comanda::_CalculeazaTotal() {
    m_total = 0.0;
    for (const auto& p : m_produse) {
        m_total += p->GetPret();
    }
}

// Returneaza ID-ul comenzii
int Comanda::GetId() const {
    return m_id;
}

// Returneaza valoarea totala a comenzii
double Comanda::GetTotal() const {
    return m_total;
}

// Returneaza data comenzii
std::string Comanda::GetData() const {
    return m_data;
}

// Afiseaza detalii despre comanda: ID-ul,data,lista produselor,totalul comenzii
void Comanda::AfiseazaComanda() const {
    std::cout << "Comanda #" << m_id << " din data " << m_data << ":\n";
    for (const auto& p : m_produse) {
        std::cout << *p << "\n";
    }
    std::cout << "Total comanda: " << m_total << " lei\n";
}

} // namespace Online_Store

