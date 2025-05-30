#include "magazin.h"
#include <iostream>

namespace Online_Store {

// Initializam pointerul static la nullptr
Magazin* Magazin::m_instance = nullptr;

// Constructor privat
Magazin::Magazin() {}

// Metoda statica pentru accesarea singleton-ului
Magazin* Magazin::GetInstance() {
    if (!m_instance)
        m_instance = new Magazin();  // Creeaza instanta daca nu exista
    return m_instance;
}

// Adauga un produs in catalog
void Magazin::AdaugaProdus(const std::shared_ptr<Produs>& produs) {
    m_catalog.push_back(produs);
}

// Adauga un utilizator in sistem
void Magazin::AdaugaUtilizator(const std::shared_ptr<Utilizator>& utilizator) {
    m_utilizatori.push_back(utilizator);
}

// Adauga o comanda
void Magazin::AdaugaComanda(const Comanda& comanda) {
    m_comenzi.push_back(comanda);
}

// Afiseaza toate produsele din catalog
void Magazin::AfiseazaCatalog() const {
    std::cout << "Catalog produse:\n";
    for (const auto& p : m_catalog) {
        std::cout << *p << "\n";
    }
}

// Afiseaza lista de utilizatori
void Magazin::AfiseazaUtilizatori() const {
    std::cout << "Utilizatori inregistrati:\n";
    for (const auto& u : m_utilizatori) {
        std::cout << u->GetTipUtilizator() << " - " << u->GetNumeUtilizator() << "\n";
    }
}

// Afiseaza toate comenzile inregistrate
void Magazin::AfiseazaComenzi() const {
    std::cout << "Comenzi inregistrate:\n";
    for (const auto& c : m_comenzi) {
        c.AfiseazaComanda();
    }
}

// Cauta un produs dupa ID si returneaza un pointer shared
std::shared_ptr<Produs> Magazin::CautaProdusDupaId(int id) const {
    for (const auto& p : m_catalog) {
        if (p->GetId() == id)
            return p;
    }
    return nullptr;
}

// Citeste produse din fisier si le adauga in catalog
void Magazin::CitesteProduseDinFisier(const std::string& fisier) {
    std::ifstream fin(fisier);
    std::string linie;

    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        int id, stoc, garantie;
        std::string nume, categorie;
        double pret;
        char delim;

        std::getline(ss, linie, '\n');
        std::stringstream ls(linie);
        std::getline(ls, linie, '\r'); // curata newline Windows
        std::stringstream cleanss(linie);
        cleanss >> id >> delim;
        std::getline(cleanss, nume, ',');
        std::getline(cleanss, categorie, ',');
        cleanss >> pret >> delim >> stoc >> delim >> garantie;

        auto produs = std::make_shared<ProdusElectronic>(id, nume, categorie, pret, stoc, garantie);
        m_catalog.push_back(produs);
    }

    fin.close();
}

// Citeste utilizatori din fisier
void Magazin::CitesteUtilizatoriDinFisier(const std::string& fisier) {
    std::ifstream fin(fisier);
    std::string linie;

    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        int id;
        std::string tip, nume, email, extras;

        std::getline(ss, linie, '\r'); // curata newline Windows
        std::stringstream parse(linie);

        std::string token;
        std::getline(parse, token, ','); id = std::stoi(token);
        std::getline(parse, tip, ',');
        std::getline(parse, nume, ',');
        std::getline(parse, email, ',');
        std::getline(parse, extras, ',');

        if (tip == "Client") {
            m_utilizatori.push_back(std::make_shared<Client>(id, nume, email, extras));
        } else if (tip == "Administrator") {
            m_utilizatori.push_back(std::make_shared<Administrator>(id, nume, email, extras));
        }
    }

    fin.close();
}

// Citeste comenzi din fisier
void Magazin::CitesteComenziDinFisier(const std::string& fisier) {
    std::ifstream fin(fisier);
    std::string linie;

    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        int id;
        std::string data;
        double total;

        std::getline(ss, linie, '\r');
        std::stringstream parse(linie);

        std::string token;
        std::getline(parse, token, ','); id = std::stoi(token);
        std::getline(parse, data, ',');
        parse >> total;

        // Produse nu sunt disponibile, simulam cu vector gol
        Comanda comanda({}, data);
        m_comenzi.push_back(comanda);
    }

    fin.close();
}

// Salveaza produsele din catalog in fisier
void Magazin::SalveazaProduseInFisier(const std::string& fisier) const {
    std::ofstream fout(fisier);
    for (const auto& p : m_catalog) {
        auto pe = std::dynamic_pointer_cast<ProdusElectronic>(p);
        fout << p->GetId() << "," << p->GetNume() << "," << p->GetCategorie()
             << "," << p->GetPret() << "," << p->GetStoc();
        if (pe) fout << "," << pe->GetGarantie();
        else fout << ",0";
        fout << "\n";
    }
    fout.close();
}

// Salveaza utilizatorii in fisier
void Magazin::SalveazaUtilizatoriInFisier(const std::string& fisier) const {
    std::ofstream fout(fisier);
    for (const auto& u : m_utilizatori) {
        fout << u->GetId() << "," << u->GetTipUtilizator() << ","
             << u->GetNumeUtilizator() << "," << u->GetEmail();

        if (u->GetTipUtilizator() == "Client") {
            auto c = std::dynamic_pointer_cast<Client>(u);
            fout << "," << "Adresa simulata";
        } else if (u->GetTipUtilizator() == "Administrator") {
            auto a = std::dynamic_pointer_cast<Administrator>(u);
            fout << "," << "Departament simulativ";
        }
        fout << "\n";
    }
    fout.close();
}

// Salveaza comenzile in fisier
void Magazin::SalveazaComenziInFisier(const std::string& fisier) const {
    std::ofstream fout(fisier);
    for (const auto& c : m_comenzi) {
        fout << c.GetId() << "," << c.GetData() << "," << c.GetTotal() << "\n";
    }
    fout.close();
}

} // namespace Online_Store

