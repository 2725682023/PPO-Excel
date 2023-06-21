#ifndef PPO_EXCEL_KOMORKAFLOAT_H
#define PPO_EXCEL_KOMORKAFLOAT_H

#include "komorka.h"

class KomorkaFloat : public Komorka {
public:
    /*
     * Zwraca wartosc komorki w formie float
     * @param brak
     * @return wartosc komorki
     */
    float getFloatWartosc() const;
};

#endif //PPO_EXCEL_KOMORKAFLOAT_H
