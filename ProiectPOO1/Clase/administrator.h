#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "utilizator.h"

namespace Online_Store {

class Administrator : public Utilizator {
private:
    std::string m_departament;

public:
    Administrator();
    Administrator(int id, const std::string& nume_utilizator, const std::string& email, const std::string& departament);

    std::string GetTipUtilizator() const override;
    void AfiseazaProfil() const override;

    void AdaugaProdus();     // Stub - se va implementa când avem clasa Magazin
    void StergeProdus();     // Stub
};

} // namespace Online_Store

#endif
