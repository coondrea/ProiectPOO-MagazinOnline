#include <iostream>
#include <memory>
#include "produs_electronic.h"
#include "client.h"
#include "administrator.h"
#include "cos_cumparaturi.h"
#include "comanda.h"
#include "factura.h"
#include "magazin.h"

using namespace Online_Store;

int main() {
    // Inițializare magazin
    Magazin* magazin = Magazin::GetInstance();

    // 🟢 PAS 1: Citim din fișiere EXISTENTE
    magazin->CitesteProduseDinFisier("Fisiere_txt/produse.txt");
    magazin->CitesteUtilizatoriDinFisier("Fisiere_txt/utilizatori.txt");
    magazin->CitesteComenziDinFisier("Fisiere_txt/comenzi.txt");

    std::vector<Factura> facturi;
    CitesteFacturiDinFisier("Fisiere_txt/facturi.txt", facturi);

    // 🟢 PAS 2: Adăugăm manual date NOI
    auto laptop = std::make_shared<ProdusElectronic>(11, "Laptop HP", "Electronice", 3500.0, 10, 24);
    auto telefon = std::make_shared<ProdusElectronic>(12, "Samsung Galaxy", "Electronice", 2800.0, 20, 12);
    magazin->AdaugaProdus(laptop);
    magazin->AdaugaProdus(telefon);

    auto client = std::make_shared<Client>(201, "maria99", "maria@email.com", "Str. Trandafirilor 12");
    auto admin = std::make_shared<Administrator>(101, "admin", "admin@shop.com", "IT");
    magazin->AdaugaUtilizator(client);
    magazin->AdaugaUtilizator(admin);

    // 🟢 PAS 3: Simulăm acțiuni
    magazin->AfiseazaCatalog();

    CosCumparaturi cos;
    cos.AdaugaProdus(laptop);
    cos.AdaugaProdus(telefon);
    cos.AfiseazaCos();

    std::vector<std::shared_ptr<Produs>> produse_comandate = { laptop, telefon };
    Comanda comanda(produse_comandate, "2025-05-28");
    client->AdaugaComanda(comanda.GetId());
    magazin->AdaugaComanda(comanda);

    Factura factura(comanda, 0.1); // 10% discount
    factura.AfiseazaFactura();
    facturi.push_back(factura);

    std::cout << "\n--- Utilizatori ---\n";
    magazin->AfiseazaUtilizatori();

    std::cout << "\n--- Comenzi ---\n";
    magazin->AfiseazaComenzi();

    // 🟢 PAS 4: Salvăm toate datele noi
    magazin->SalveazaProduseInFisier("Fisiere_txt/produse.txt");
    magazin->SalveazaUtilizatoriInFisier("Fisiere_txt/utilizatori.txt");
    magazin->SalveazaComenziInFisier("Fisiere_txt/comenzi.txt");

    for (const auto& f : facturi) {
        SalveazaFacturaInFisier(f, "Fisiere_txt/facturi.txt");
    }

    std::cout << "\n✅ Toate datele au fost salvate cu succes.\n";
    return 0;
}

