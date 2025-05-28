#ifndef CLIENT_H
#define CLIENT_H

#include "utilizator.h"
#include <vector>

namespace Online_Store {

class Client : public Utilizator {
private:
    std::string m_adresa_livrare;
    std::vector<int> m_id_comenzi; // ID-uri comenzi (simplificat deocamdată)

public:
    Client();
    Client(int id, const std::string& nume_utilizator, const std::string& email, const std::string& adresa);

    void AdaugaComanda(int id_comanda);
    std::string GetTipUtilizator() const override;
    void AfiseazaProfil() const override;
};

} // namespace Online_Store

#endif
