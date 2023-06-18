#ifndef PPO_EXCEL_KOMORKAFLAOT_H
#define PPO_EXCEL_KOMORKAFLAOT_H

#include <iostream>
#include "komorka.h"

using namespace std;

class komorkaflaot : public komorka {
private:
    float wartosc;
public:
    /*
        * Podstawowy konstruktor
        * Wartość domyślna 0.0f
        * @pharm brak
        * @return brak
     */
    komorkaflaot() : wartosc(0.0f) {};

    /*
        * Ustawianie wartości w komorce jeżeli jest stringiem
        * @pharm wartosc - wartość do ustawienia
        * @return brak
     */
    void setWartosc(const string& wartosc);

    /*
        * Ustawianie wartości w komorce jeżeli jest floatem
        * @pharm wartosc - wartość do ustawienia
        * @return brak
     */
    void setWartosc(float wartosc);

    /*
        * Zwracanie wartości jeżeli jest stringiem
        * @pharm brak
        * @return Wartość komórki
     */
    string getWartoscString() const;

    /*
        * Zwracanie wartości jeżeli jest floatem
        * @pharm brak
        * @return Wartość komórki
     */
    float getWartoscFloat() const;

    /*
        * Wyświatlanie komóki
        * @pharm brak
        * @return brak
     */
    void wyswietl() const;
};


#endif //PPO_EXCEL_KOMORKAFLAOT_H
