#ifndef COS_CUMPARATURI_H
#define COS_CUMPARATURI_H

#include "produs.h"
#include <vector>
#include <memory>

namespace Online_Store {

/*
 * Clasa CosCumparaturi gestioneaza lista de produse adaugate de un client.
 * Aceasta permite adaugarea, stergerea, afisarea si golirea produselor,
 * precum si obtinerea totalului si a numarului de produse.
 */
class CosCumparaturi {
private:
    std::vector<std::shared_ptr<Produs>> m_produse;  // Produsele adaugate in cos
    double m_total;                                  // Totalul valoric al produselor din cos

    // Functie privata care recalculeaza totalul cosului dupa fiecare modificare
    void _ActualizeazaTotal();

public:
    // Constructor implicit
    CosCumparaturi();

    // Adauga un produs in cos
    void AdaugaProdus(const std::shared_ptr<Produs>& produs);

    // Sterge un produs din cos pe baza ID-ului
    void StergeProdus(int id_produs);

    // Elimina toate produsele din cos
    void GolesteCosul();

    // Afiseaza continutul cosului si totalul
    void AfiseazaCos() const;

    // Returneaza totalul curent al cosului
    double GetTotal() const;

    // Returneaza numarul de produse din cos
    int GetNrProduse() const;

    // Verifica daca cosul este gol
    bool EsteGol() const;
};

} // namespace Online_Store

#endif
