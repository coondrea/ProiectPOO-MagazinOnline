#include "produs_electronic.h"
#include <iostream>
#include <stdexcept>

namespace Online_Store {

// Constructor implicit - initializeaza cu garantie 0
ProdusElectronic::ProdusElectronic() : Produs(), m_garantie_luni(0) {}

// Constructor cu parametri - initializeaza toate atributele, inclusiv validare garantie
ProdusElectronic::ProdusElectronic(int id, const std::string& nume, const std::string& categorie,
                                   double pret, int stoc, int garantie)
    : Produs(id, nume, categorie, pret, stoc) {
    _ValidareGarantie(garantie);
    m_garantie_luni = garantie;
}

ProdusElectronic::~ProdusElectronic() {}

// Metoda privata care verifica daca valoarea garantiei este valida
void ProdusElectronic::_ValidareGarantie(int luni) {
    if (luni < 0 || luni > 60)
        throw std::invalid_argument("Garantie invalida (0-60 luni)");
}


int ProdusElectronic::GetGarantie() const {
    return m_garantie_luni;
}


void ProdusElectronic::SetGarantie(int luni) {
    _ValidareGarantie(luni);
    m_garantie_luni = luni;
}

// Afiseaza detalii despre produsul electronic (supraincarcare)
void ProdusElectronic::AfiseazaDetalii() const {
    std::cout << "Produs Electronic: " << m_nume
              << " | Categorie: " << m_categorie
              << " | Pret: " << m_pret << " lei"
              << " | Garantie: " << m_garantie_luni << " luni"
              << " | Stoc: " << m_stoc << "\n";
}

// Returneaza descriere detaliata a produsului (polimorfism)
std::string ProdusElectronic::GetDescriereDetaliata() const {
    return "Electronic: " + m_nume + " cu garantie de " + std::to_string(m_garantie_luni) + " luni.";
}

} // namespace Online_Store

