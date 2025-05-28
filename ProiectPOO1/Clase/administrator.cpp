#include "administrator.h"
#include <iostream>

namespace Online_Store {

Administrator::Administrator()
    : Utilizator(), m_departament("General") {}

Administrator::Administrator(int id, const std::string& nume_utilizator,
                             const std::string& email, const std::string& departament)
    : Utilizator(id, nume_utilizator, email), m_departament(departament) {}

std::string Administrator::GetTipUtilizator() const {
    return "Administrator";
}

void Administrator::AfiseazaProfil() const {
    std::cout << "Profil Administrator:\n";
    std::cout << "ID: " << m_id << "\nNume: " << m_nume_utilizator
              << "\nEmail: " << m_email
              << "\nDepartament: " << m_departament << "\n";
}

void Administrator::AdaugaProdus() {
    std::cout << "Stub: adaugare produs\n";
}

void Administrator::StergeProdus() {
    std::cout << "Stub: stergere produs\n";
}

} // namespace Online_Store
