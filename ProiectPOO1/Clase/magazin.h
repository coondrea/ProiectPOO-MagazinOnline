#ifndef MAGAZIN_H
#define MAGAZIN_H

#include "produs.h"
#include "utilizator.h"
#include "comanda.h"
#include <vector>
#include <memory>

namespace Online_Store {

class Magazin {
private:
    static Magazin* m_instance;

    std::vector<std::shared_ptr<Produs>> m_catalog;
    std::vector<std::shared_ptr<Utilizator>> m_utilizatori;
    std::vector<Comanda> m_comenzi;

    Magazin(); // constructor privat pt singleton

public:
    static Magazin* GetInstance();

    void AdaugaProdus(const std::shared_ptr<Produs>& produs);
    void AdaugaUtilizator(const std::shared_ptr<Utilizator>& utilizator);
    void AdaugaComanda(const Comanda& comanda);

    void AfiseazaCatalog() const;
    void AfiseazaUtilizatori() const;
    void AfiseazaComenzi() const;
    void CitesteProduseDinFisier(const std::string& fisier);
    void CitesteUtilizatoriDinFisier(const std::string& fisier);
    void CitesteComenziDinFisier(const std::string& fisier);
    void SalveazaProduseInFisier(const std::string& fisier) const;
    void SalveazaUtilizatoriInFisier(const std::string& fisier) const;
    void SalveazaComenziInFisier(const std::string& fisier) const;







    std::shared_ptr<Produs> CautaProdusDupaId(int id) const;
};

} // namespace Online_Store

#endif
