#include "utilizator.h"

namespace Online_Store {

// Constructor implicit care initializeaza valorile cu default
Utilizator::Utilizator() 
    : m_id(0), m_nume_utilizator("Anonim"), m_email("necunoscut@exemplu.com") {}

// Constructor cu parametri pentru initializarea utilizatorului
Utilizator::Utilizator(int id, const std::string& nume_utilizator, const std::string& email)
    : m_id(id), m_nume_utilizator(nume_utilizator), m_email(email) {}

// Destructor virtual
Utilizator::~Utilizator() {}

// Returneaza ID-ul utilizatorului
int Utilizator::GetId() const {
    return m_id;
}

// Returneaza numele de utilizator
std::string Utilizator::GetNumeUtilizator() const {
    return m_nume_utilizator;
}

// Returneaza adresa de email a utilizatorului
std::string Utilizator::GetEmail() const {
    return m_email;
}

// Seteaza o noua adresa de email pentru utilizator
void Utilizator::SetEmail(const std::string& email) {
    m_email = email;
}

} // namespace Online_Store


