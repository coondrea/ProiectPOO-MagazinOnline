#include <iostream>
#include "client.h"

namespace Online_Store {

/* Constructor implicit pentru Client.
   Apeleaza constructorul implicit din Utilizator si seteaza adresa de livrare ca "necunoscuta". */
Client::Client()
    : Utilizator(), m_adresa_livrare("necunoscuta") {}

/* Constructor cu parametri pentru Client.
   Initializeaza campurile mostenite si adresa de livrare. */
Client::Client(int id, const std::string& nume_utilizator, const std::string& email, const std::string& adresa)
    : Utilizator(id, nume_utilizator, email), m_adresa_livrare(adresa) {}

/* Adauga ID-ul unei comenzi in lista comenzilor clientului. */
void Client::AdaugaComanda(int id_comanda) {
    m_id_comenzi.push_back(id_comanda);
}

/* Returneaza tipul utilizatorului - in acest caz, "Client". */
std::string Client::GetTipUtilizator() const {
    return "Client";
}

/* Afiseaza profilul clientului: ID, nume, email, adresa de livrare si numarul de comenzi efectuate. */
void Client::AfiseazaProfil() const {
    std::cout << "Profil Client:\n";
    std::cout << "ID: " << m_id << "\nNume: " << m_nume_utilizator
              << "\nEmail: " << m_email
              << "\nAdresa livrare: " << m_adresa_livrare
              << "\nNumar comenzi: " << m_id_comenzi.size() << "\n";
}

} // namespace Online_Store

