#ifndef CLIENT_H
#define CLIENT_H

#include "utilizator.h"
#include <vector>

namespace Online_Store {

//Clasa Client mosteneste clasa Utilizator si adauga functionalitati specifice unui client: adresa de livrare si o lista de comenzi (identificate prin ID-uri).
 
class Client : public Utilizator {
private:
    std::string m_adresa_livrare;        // Adresa de livrare asociata clientului
    std::vector<int> m_id_comenzi;       // Lista de ID-uri ale comenzilor plasate

public:
    
    Client();

    // Constructor cu parametri pentru initializarea tuturor atributelor clientului
    Client(int id, const std::string& nume_utilizator, const std::string& email, const std::string& adresa);

    // Adauga ID-ul unei comenzi la lista comenzilor clientului
    void AdaugaComanda(int id_comanda);

    // Returneaza tipul utilizatorului - "Client"
    std::string GetTipUtilizator() const override;

    // Afiseaza toate informatiile despre client
    void AfiseazaProfil() const override;
};

} // namespace Online_Store

#endif
