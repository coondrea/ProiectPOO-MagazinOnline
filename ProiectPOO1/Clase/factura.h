#ifndef FACTURA_H
#define FACTURA_H

#include "comanda.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>

namespace Online_Store {

class Factura {
private:
    static int m_contor_cod;
    std::string m_cod_factura;
    Comanda m_comanda;
    double m_total_cu_tva;
    double m_discount_aplicat;
    double m_tva;

    void _CalculeazaValori();

public:
    Factura(const Comanda& comanda, double discount = 0.0, double tva = 0.19);

    std::string GetCodFactura() const;
    double GetTotalCuTVA() const;
    double GetTVA() const;
    double GetDiscount() const;

    void AfiseazaFactura() const;

    void CitesteFacturiDinFisier(const std::string& fisier, std::vector<Factura>& facturi);
    void SalveazaFacturaInFisier(const Factura& f, const std::string& fisier);

};

} // namespace Online_Store

#endif
