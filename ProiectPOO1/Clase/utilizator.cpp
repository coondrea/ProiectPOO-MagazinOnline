#include "utilizator.h"

namespace Online_Store {

Utilizator::Utilizator() : m_id(0), m_nume_utilizator("Anonim"), m_email("necunoscut@exemplu.com") {}

Utilizator::Utilizator(int id, const std::string& nume_utilizator, const std::string& email)
    : m_id(id), m_nume_utilizator(nume_utilizator), m_email(email) {}

Utilizator::~Utilizator() {}

int Utilizator::GetId() const {
    return m_id;
}

std::string Utilizator::GetNumeUtilizator() const {
    return m_nume_utilizator;
}

std::string Utilizator::GetEmail() const {
    return m_email;
}

void Utilizator::SetEmail(const std::string& email) {
    m_email = email;
}

} // namespace Online_Store

