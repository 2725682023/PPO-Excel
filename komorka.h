#ifndef PPO_EXCEL_KOMORKA_H
#define PPO_EXCEL_KOMORKA_H

#include "komorkiInterface.h"

class Komorka : public KomorkiInterface {
protected:
    std::string wartosc;
public:
    /*
     * Zwraca wartosc komorki w formie stringa
     * @param brak
     * @return wartosc komorki
     */
    std::string getWartosc() const override;

    /*
     * Ustawia wartosc komorki
     * @param wartosc
     * @return brak
     */
    void setWartosc(const std::string& wartosc) override;
};


#endif //PPO_EXCEL_KOMORKA_H
