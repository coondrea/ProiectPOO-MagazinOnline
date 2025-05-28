#include "factura.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Online_Store {

int Factura::m_contor_cod = 1000;

Factura::Factura(const Comanda& comanda, double discount, double tva)
    : m_comanda(comanda), m_discount_aplicat(discount), m_tva(tva) {
    std::stringstream ss;
    ss << "INV" << m_contor_cod++;
    m_cod_factura = ss.str();
    _CalculeazaValori();
}

void Factura::_CalculeazaValori() {
    double total = m_comanda.GetTotal();
    double total_discountat = total - (total * m_discount_aplicat);
    m_total_cu_tva = total_discountat + (total_discountat * m_tva);
}

std::string Factura::GetCodFactura() const {
    return m_cod_factura;
}

double Factura::GetTotalCuTVA() const {
    return m_total_cu_tva;
}

double Factura::GetTVA() const {
    return m_tva;
}

double Factura::GetDiscount() const {
    return m_discount_aplicat;
}

void Factura::AfiseazaFactura() const {
    std::cout << "Factura #" << m_cod_factura << "\n";
    m_comanda.AfiseazaComanda();
    std::cout << "Discount aplicat: " << m_discount_aplicat * 100 << "%\n";
    std::cout << "TVA: " << m_tva * 100 << "%\n";
    std::cout << "Total final: " << std::fixed << std::setprecision(2) << m_total_cu_tva << " lei\n";
}
void CitesteFacturiDinFisier(const std::string& fisier, std::vector<Factura>& facturi) {
    std::ifstream fin(fisier);
    std::string linie;

    while (std::getline(fin, linie)) {
        std::stringstream ss(linie);
        std::string cod;
        int comanda_id;
        double tva, discount, total;

        std::getline(ss, cod, ',');
        ss >> comanda_id;
        ss.ignore(1);
        ss >> tva;
        ss.ignore(1);
        ss >> discount;
        ss.ignore(1);
        ss >> total;

        // Comanda simulată, datele exacte lipsesc din fișier
        Factura f(Comanda({}, "2025-01-01"), discount, tva);
        facturi.push_back(f);
    }

    fin.close();
}

void SalveazaFacturaInFisier(const Factura& f, const std::string& fisier) {
    std::ofstream fout(fisier, std::ios::app); // adăugăm, nu suprascriem
    fout << f.GetCodFactura() << ","
         << f.GetComanda().GetId() << ","
         << f.GetTVA() << ","
         << f.GetDiscount() << ","
         << f.GetTotalCuTVA() << "\n";
    fout.close();
}

} // namespace Online_Store
