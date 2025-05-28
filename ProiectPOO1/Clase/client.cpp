#include "client.h"
#include <iostream>

namespace Online_Store {

Client::Client()
    : Utilizator(), m_adresa_livrare("necunoscuta") {}

Client::Client(int id, const std::string& nume_utilizator, const std::string& email, const std::string& adresa)
    : Utilizator(id, nume_utilizator, email), m_adresa_livrare(adresa) {}

void Client::AdaugaComanda(int id_comanda) {
    m_id_comenzi.push_back(id_comanda);
}

std::string Client::GetTipUtilizator() const {
    return "Client";
}

void Client::AfiseazaProfil() const {
    std::cout << "Profil Client:\n";
    std::cout << "ID: " << m_id << "\nNume: " << m_nume_utilizator
              << "\nEmail: " << m_email
              << "\nAdresa livrare: " << m_adresa_livrare
              << "\nNumar comenzi: " << m_id_comenzi.size() << "\n";
}

} // namespace Online_Store
