#ifndef MAGAZIN_H
#define MAGAZIN_H

#include "produs.h"
#include "utilizator.h"
#include "comanda.h"
#include <vector>
#include <memory>

namespace Online_Store {

//Clasa Magazin gestioneaza catalogul de produse, lista de utilizatori si comenzile.Este implementata ca Singleton pentru a asigura o singura instanta in aplicatie.
class Magazin {
private:
    static Magazin* m_instance; // Instanta Singleton

    std::vector<std::shared_ptr<Produs>> m_catalog;      // Lista de produse disponibile
    std::vector<std::shared_ptr<Utilizator>> m_utilizatori; // Lista utilizatori (Clienti/Admini)
    std::vector<Comanda> m_comenzi;                      // Comenzile efectuate

    Magazin(); // Constructor privat (Singleton)

public:
    //Returneaza instanta Singleton a clasei Magazin.
    static Magazin* GetInstance();

    // Adauga un produs in catalog.
    void AdaugaProdus(const std::shared_ptr<Produs>& produs);

    //Adauga un utilizator (client sau admin).
    void AdaugaUtilizator(const std::shared_ptr<Utilizator>& utilizator);

    //Adauga o comanda in lista comenzilor.
    void AdaugaComanda(const Comanda& comanda);

    //Afiseaza toate produsele din catalog.
    void AfiseazaCatalog() const;

    //Afiseaza lista de utilizatori inregistrati.
    void AfiseazaUtilizatori() const;

    //Afiseaza toate comenzile procesate.
    void AfiseazaComenzi() const;

    //Citeste produse din fisier si le incarca in catalog.
    void CitesteProduseDinFisier(const std::string& fisier);

    //Citeste utilizatori (clienti/admini) din fisier.
    void CitesteUtilizatoriDinFisier(const std::string& fisier);

    //Citeste comenzi din fisier si le incarca in sistem.
    void CitesteComenziDinFisier(const std::string& fisier);

    //Salveaza produsele din catalog intr-un fisier.
    void SalveazaProduseInFisier(const std::string& fisier) const;

    //Salveaza utilizatorii inregistrati intr-un fisier.
    void SalveazaUtilizatoriInFisier(const std::string& fisier) const;

    //Salveaza comenzile efectuate intr-un fisier.
    void SalveazaComenziInFisier(const std::string& fisier) const;

    //Cauta si returneaza un produs dupa ID. Returneaza nullptr daca nu exista.
    std::shared_ptr<Produs> CautaProdusDupaId(int id) const;
};

} // namespace Online_Store

#endif

