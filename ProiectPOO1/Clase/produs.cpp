#include "produs.h"
#include <stdexcept>

namespace Online_Store {

Produs::Produs() : m_id(0), m_nume("Necunoscut"), m_categorie("General"), m_pret(0.0), m_stoc(0) {}

Produs::Produs(int id, const std::string& nume, const std::string& categorie, double pret, int stoc)
    : m_id(id), m_nume(nume), m_categorie(categorie) {
    _ValidarePret(pret);
    _ValidareStoc(stoc);
    m_pret = pret;
    m_stoc = stoc;
}

Produs::~Produs() {}

void Produs::_ValidarePret(double pret) {
    if (pret < 0)
        throw std::invalid_argument("Pretul nu poate fi negativ!");
}

void Produs::_ValidareStoc(int stoc) {
    if (stoc < 0)
        throw std::invalid_argument("Stocul nu poate fi negativ!");
}

int Produs::GetId() const { return m_id; }
std::string Produs::GetNume() const { return m_nume; }
std::string Produs::GetCategorie() const { return m_categorie; }
double Produs::GetPret() const { return m_pret; }
int Produs::GetStoc() const { return m_stoc; }

void Produs::SetNume(const std::string& nume) { m_nume = nume; }
void Produs::SetCategorie(const std::string& categorie) { m_categorie = categorie; }

void Produs::SetPret(double pret) {
    _ValidarePret(pret);
    m_pret = pret;
}

void Produs::SetStoc(int stoc) {
    _ValidareStoc(stoc);
    m_stoc = stoc;
}

void Produs::ScadeStoc(int cantitate) {
    if (cantitate > m_stoc)
        throw std::runtime_error("Stoc insuficient!");
    m_stoc -= cantitate;
}

void Produs::MaresteStoc(int cantitate) {
    m_stoc += cantitate;
}

void Produs::AfiseazaDetalii() const {
    std::cout << "Produs: " << m_nume 
              << " | Categorie: " << m_categorie 
              << " | Pret: " << m_pret 
              << " lei | Stoc: " << m_stoc << "\n";
}

std::string Produs::GetDescriereDetaliata() const {
    return "Produs generic: " + m_nume + " | Categorie: " + m_categorie;
}

std::ostream& operator<<(std::ostream& os, const Produs& produs) {
    os << "ID: " << produs.m_id
       << " | Nume: " << produs.m_nume
       << " | Categorie: " << produs.m_categorie
       << " | Pret: " << produs.m_pret
       << " lei | Stoc: " << produs.m_stoc;
    return os;
}

bool Produs::operator==(const Produs& other) const {
    return m_id == other.m_id;
}

} // namespace Online_Store
