#ifndef FACTURA_H
#define FACTURA_H

#include "comanda.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

namespace Online_Store {

/*
 * Clasa Factura reprezinta o factura generata pe baza unei comenzi.
 * Aceasta contine informatii despre TVA, discount, cod unic si totalul final.
 */
class Factura {
private:
    static int m_contor_cod;      // Contor static pentru coduri unice
    std::string m_cod_factura;    // Codul unic al facturii
    Comanda m_comanda;            // Comanda asociata facturii
    double m_total_cu_tva;        // Totalul comenzii dupa discount si TVA
    double m_discount_aplicat;    // Procentul de discount aplicat
    double m_tva;                 // Procentul de TVA

    // Functie privata care calculeaza totalul final
    void _CalculeazaValori();

public:
    // Constructor cu parametri: comanda, discount optional, TVA optional
    Factura(const Comanda& comanda, double discount = 0.0, double tva = 0.19);

    // Gettere pentru informatii despre factura
    std::string GetCodFactura() const;
    double GetTotalCuTVA() const;
    double GetTVA() const;
    double GetDiscount() const;

    // Afiseaza continutul facturii
    void AfiseazaFactura() const;

    // Returneaza comanda asociata
    const Comanda& GetComanda() const { return m_comanda; }
};

/*
 * Citeste toate facturile dintr-un fisier text si le adauga intr-un vector.
 */
void CitesteFacturiDinFisier(const std::string& fisier, std::vector<Factura>& facturi);

/*
 * Salveaza o factura in fisierul specificat (append).
 */
void SalveazaFacturaInFisier(const Factura& f, const std::string& fisier);

} // namespace Online_Store

#endif

