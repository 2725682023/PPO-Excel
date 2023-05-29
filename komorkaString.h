#ifndef PPO_EXCEL_KOMORKASTRING_H
#define PPO_EXCEL_KOMORKASTRING_H

#include <iostream>
#include "komorkaInterface.h"

using namespace std;

class komorkaString : public komorkaInterface {
private:
    string wartosc;
public:
    // Podstawowy konstruktor wstawiający pustą komórkę
    komorkaString() : wartosc("") {};

    // Ustawianie wartości jeżeli jest stringiem
    void setWartosc(const string& wartosc);

    // Ustawianie wartości jeżeli jest floatem
    void setWartosc(const float wartosc);

    // Zwracanie wartości jeżeli jest stringiem
    string getWartoscString() const;

    // Zwracanie wartości jeżeli jest floatem
    float getWartoscFloat() const;

    // Wyświatlanie komóki
    void wyswietl() const;




};


#endif //PPO_EXCEL_KOMORKASTRING_H
