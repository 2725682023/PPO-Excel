#ifndef PPO_EXCEL_KOMORKAFLAOT_H
#define PPO_EXCEL_KOMORKAFLAOT_H

#include <iostream>
#include "komorkaInterface.h"

using namespace std;

class komorkaflaot : public komorkaInterface {
private:
    float wartosc;
public:
    // Podstawowy konstruktor
    komorkaflaot() : wartosc(0.0f) {};

    // Ustawia wartość komórki jeżeli to string
    void setWartosc(const string& wartosc);

    // Ustawia wartość komórki jeżeli to float
    void setWartosc(float wartosc);

    // Zwracanie wartości jeżeli jest stringiem
    string getWartoscString() const;

    // Zwracanie wartości jeżeli jest floatem
    float getWartoscFloat() const;

    // Wyświatlanie komóki
    void wyswietl() const;
};


#endif //PPO_EXCEL_KOMORKAFLAOT_H
