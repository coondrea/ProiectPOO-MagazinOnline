#include "cos_cumparaturi.h"
#include <iostream>

namespace Online_Store {

// Constructor implicit - initializeaza totalul pe 0
CosCumparaturi::CosCumparaturi() : m_total(0.0) {}

/* Functie privata care recalculeaza totalul cosului
   pe baza preturilor produselor curente. */
void CosCumparaturi::_ActualizeazaTotal() {
    m_total = 0.0;
    for (const auto& p : m_produse) {
        m_total += p->GetPret();
    }
}

/* Adauga un produs in cos si actualizeaza totalul. */
void CosCumparaturi::AdaugaProdus(const std::shared_ptr<Produs>& produs) {
    m_produse.push_back(produs);
    _ActualizeazaTotal();
}

/* Sterge produsul cu ID-ul specificat din cos, daca exista,
   si actualizeaza totalul. */
void CosCumparaturi::StergeProdus(int id_produs) {
    m_produse.erase(
        std::remove_if(m_produse.begin(), m_produse.end(),
                       [id_produs](const std::shared_ptr<Produs>& p) {
                           return p->GetId() == id_produs;
                       }),
        m_produse.end());
    _ActualizeazaTotal();
}

/* Goleste complet cosul de cumparaturi si reseteaza totalul. */
void CosCumparaturi::GolesteCosul() {
    m_produse.clear();
    m_total = 0.0;
}

/* Afiseaza toate produsele din cos si totalul curent.
   Daca nu exista produse, afiseaza mesaj corespunzator. */
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

// Returneaza valoarea totala a cosului
double CosCumparaturi::GetTotal() const {
    return m_total;
}

// Returneaza numarul de produse din cos
int CosCumparaturi::GetNrProduse() const {
    return static_cast<int>(m_produse.size());
}

// Verifica daca cosul este gol
bool CosCumparaturi::EsteGol() const {
    return m_produse.empty();
}

} // namespace Online_Store

