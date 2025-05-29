#include "factura.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Online_Store {

// Initializarea contorului static pentru generarea codurilor unice de factura. 
int Factura::m_contor_cod = 1000;

// Constructor pentru Factura.Primeste o comanda, procentul de discount si procentul TVA.Genereaza un cod unic si apoi calculeaza valorile finale.
Factura::Factura(const Comanda& comanda, double discount, double tva)
    : m_comanda(comanda), m_discount_aplicat(discount), m_tva(tva) {
    std::stringstream ss;
    ss << "INV" << m_contor_cod++;   // Genereaza cod de forma INV1000, INV1001, ...
    m_cod_factura = ss.str();
    _CalculeazaValori();            // Calculeaza total cu TVA si discount
}

// Functie privata care calculeaza:totalul comenzii,total dupa aplicarea discountului,total cu TVA inclus 
void Factura::_CalculeazaValori() {
    double total = m_comanda.GetTotal();
    double total_discountat = total - (total * m_discount_aplicat);
    m_total_cu_tva = total_discountat + (total_discountat * m_tva);
}

// Returneaza codul unic al facturii
std::string Factura::GetCodFactura() const {
    return m_cod_factura;
}

// Returneaza totalul facturii cu TVA inclus. 
double Factura::GetTotalCuTVA() const {
    return m_total_cu_tva;
}

// Returneaza procentul de TVA utilizat. 
double Factura::GetTVA() const {
    return m_tva;
}

// Returneaza procentul de discount aplicat. 
double Factura::GetDiscount() const {
    return m_discount_aplicat;
}

// Afiseaza detaliile facturii:cod factura,continut comanda,discount si TVA,total final 
void Factura::AfiseazaFactura() const {
    std::cout << "Factura #" << m_cod_factura << "\n";
    m_comanda.AfiseazaComanda();
    std::cout << "Discount aplicat: " << m_discount_aplicat * 100 << "%\n";
    std::cout << "TVA: " << m_tva * 100 << "%\n";
    std::cout << "Total final: " << std::fixed << std::setprecision(2)
              << m_total_cu_tva << " lei\n";
}

// Citeste facturile dintr-un fisier text si le adauga in vectorul facturi.Fiecare linie trebuie sa fie: CodFactura,ComandaID,TVA,Discount,TotalFinal 
void CitesteFacturiDinFisier(const std::string& fisier, std::vector<Factura>& facturi) {
    std::ifstream fin(fisier);
    std::string linie;

    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        std::string cod;
        int comanda_id;
        double tva, discount, total;

        std::getline(ss, cod, ',');
        ss >> comanda_id;  ss.ignore(1);
        ss >> tva;         ss.ignore(1);
        ss >> discount;    ss.ignore(1);
        ss >> total;

        // Se creeaza o factura simulata (comanda reala nu este incarcata aici)
        Factura f(Comanda({}, "1970-01-01"), discount, tva);
        facturi.push_back(f);
    }

    fin.close();
}

// Salveaza o factura in fisierul text, adaugand-o la final (append)
void SalveazaFacturaInFisier(const Factura& f, const std::string& fisier) {
    std::ofstream fout(fisier, std::ios::app);
    fout << f.GetCodFactura() << ","
         << f.GetComanda().GetId() << ","
         << f.GetTVA() << ","
         << f.GetDiscount() << ","
         << f.GetTotalCuTVA() << "\n";
    fout.close();
}

} // namespace Online_Store

