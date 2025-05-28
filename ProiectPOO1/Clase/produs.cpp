#include "produs.h"
#include <stdexcept>

namespace Online_Store {

// Constructor implicit - initializeaza campurile cu valori default
Produs::Produs() : m_id(0), m_nume("Necunoscut"), m_categorie("General"), m_pret(0.0), m_stoc(0) {}

// Constructor cu parametri - initializeaza produsul cu datele oferite
Produs::Produs(int id, const std::string& nume, const std::string& categorie, double pret, int stoc)
    : m_id(id), m_nume(nume), m_categorie(categorie) {
    _ValidarePret(pret);   // validare pret negativ
    _ValidareStoc(stoc);   // validare stoc negativ
    m_pret = pret;
    m_stoc = stoc;
}

// Destructor
Produs::~Produs() {}

// Verifica daca pretul este valid (>= 0)
void Produs::_ValidarePret(double pret) {
    if (pret < 0)
        throw std::invalid_argument("Pretul nu poate fi negativ!");
}

// Verifica daca stocul este valid (>= 0)
void Produs::_ValidareStoc(int stoc) {
    if (stoc < 0)
        throw std::invalid_argument("Stocul nu poate fi negativ!");
}

// Getteri pentru accesarea campurilor produsului
int Produs::GetId() const { return m_id; }
std::string Produs::GetNume() const { return m_nume; }
std::string Produs::GetCategorie() const { return m_categorie; }
double Produs::GetPret() const { return m_pret; }
int Produs::GetStoc() const { return m_stoc; }

// Setteri pentru modificarea atributelor produsului
void Produs::SetNume(const std::string& nume) { m_nume = nume; }
void Produs::SetCategorie(const std::string& categorie) { m_categorie = categorie; }

void Produs::SetPret(double pret) {
    _ValidarePret(pret);   // validare inainte de setare
    m_pret = pret;
}

void Produs::SetStoc(int stoc) {
    _ValidareStoc(stoc);   // validare inainte de setare
    m_stoc = stoc;
}

// Scade cantitatea data din stocul curent
void Produs::ScadeStoc(int cantitate) {
    if (cantitate > m_stoc)
        throw std::runtime_error("Stoc insuficient!");
    m_stoc -= cantitate;
}

// Mareste stocul cu cantitatea primita
void Produs::MaresteStoc(int cantitate) {
    m_stoc += cantitate;
}

// Afiseaza detalii despre produs
void Produs::AfiseazaDetalii() const {
    std::cout << "Produs: " << m_nume 
              << " | Categorie: " << m_categorie 
              << " | Pret: " << m_pret 
              << " lei | Stoc: " << m_stoc << "\n";
}

// Returneaza o descriere scurta a produsului
std::string Produs::GetDescriereDetaliata() const {
    return "Produs generic: " + m_nume + " | Categorie: " + m_categorie;
}

// Supraincarcare operator << pentru a putea afisa un produs
std::ostream& operator<<(std::ostream& os, const Produs& produs) {
    os << "ID: " << produs.m_id
       << " | Nume: " << produs.m_nume
       << " | Categorie: " << produs.m_categorie
       << " | Pret: " << produs.m_pret
       << " lei | Stoc: " << produs.m_stoc;
    return os;
}

// Supraincarcare operator == pentru compararea produselor dupa ID
bool Produs::operator==(const Produs& other) const {
    return m_id == other.m_id;
}

} // namespace Online_Store

