#ifndef COMANDA_H
#define COMANDA_H

#include "produs.h"
#include <vector>
#include <memory>
#include <string>

namespace Online_Store {

//Clasa Comanda reprezinta o comanda plasata de un client.Fiecare comanda are un ID unic, o lista de produse, o data si un total.
class Comanda {
private:
    static int m_nr_total_comenzi;  // Contor static pentru a genera ID-uri unice
    int m_id;                       // ID-ul unic al comenzii
    std::vector<std::shared_ptr<Produs>> m_produse;  // Lista de produse din comanda
    std::string m_data;            // Data la care a fost plasata comanda
    double m_total;                // Totalul valoric al comenzii

    // Calculeaza totalul comenzii pe baza produselor
    void _CalculeazaTotal();

public:

    Comanda();

    // Constructor cu parametri: lista de produse si data
    Comanda(const std::vector<std::shared_ptr<Produs>>& produse, const std::string& data);

    ~Comanda();

    // Returneaza ID-ul comenzii
    int GetId() const;

    // Returneaza totalul comenzii
    double GetTotal() const;

    // Returneaza data comenzii
    std::string GetData() const;

    // Afiseaza informatiile despre comanda
    void AfiseazaComanda() const;
};

} // namespace Online_Store

#endif

