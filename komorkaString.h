#ifndef PPO_EXCEL_KOMORKASTRING_H
#define PPO_EXCEL_KOMORKASTRING_H

#include <iostream>
#include "komorka.h"

using namespace std;

class komorkaString : public komorka {
private:
    string wartosc;
public:
    /*
        * Podstawowy konstruktor
        * Wartość domyślna ""
        * @pharm brak
        * @return brak
     */
    komorkaString() : wartosc("") {};

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
    void setWartosc(const float wartosc);

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


#endif //PPO_EXCEL_KOMORKASTRING_H
