#include "administrator.h"
#include <iostream>

namespace Online_Store {

// Constructor implicit pentru Administrator. Initializeaza cu valori default mostenite din Utilizator si departamentul ca "General". 
Administrator::Administrator()
    : Utilizator(), m_departament("General") {}

// Constructor cu parametri pentru Administrator.Primeste id, nume de utilizator, email si departamentul asociat. 
Administrator::Administrator(int id, const std::string& nume_utilizator,
                             const std::string& email, const std::string& departament)
    : Utilizator(id, nume_utilizator, email), m_departament(departament) {}

// Returneaza tipul utilizatorului sub forma de string. Este utilizat pentru identificarea rolului. 
std::string Administrator::GetTipUtilizator() const {
    return "Administrator";
}

// Afiseaza informatiile detaliate ale unui administrator. 
void Administrator::AfiseazaProfil() const {
    std::cout << "Profil Administrator:\n";
    std::cout << "ID: " << m_id << "\nNume: " << m_nume_utilizator
              << "\nEmail: " << m_email
              << "\nDepartament: " << m_departament << "\n";
}

// Functie placeholder pentru adaugarea unui produs.Poate fi extinsa pentru a interactiona cu catalogul magazinului. 
void Administrator::AdaugaProdus() {
    std::cout << "Stub: adaugare produs\n";
}

// Functie placeholder pentru stergerea unui produs. La fel ca AdaugaProdus, poate fi extinsa pentru a opera asupra produselor existente. 
void Administrator::StergeProdus() {
    std::cout << "Stub: stergere produs\n";
}

} // namespace Online_Store
