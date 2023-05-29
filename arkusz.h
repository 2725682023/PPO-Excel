#ifndef PPO_EXCEL_ARKUSZ_H
#define PPO_EXCEL_ARKUSZ_H

#include <iostream>
#include <vector>
#include "komorkaString.h"
#include "komorkaflaot.h"

using namespace std;

class arkusz {
private:
    vector<vector<komorkaInterface*>> komorki;

    // Sprawdza czy string jest numeryczny
    bool czyLiczba(const string& wartosc) const;

public:
    // Ustawia wartość komórki jeżeli to string
    void setWartosc(int wiersz, int kolumna, const string& wartosc);

    // Ustawia wartość komórki jeżeli to float
    void setWartosc(int wiersz, int kolumna, const float wartosc);

    // Zwracanie wartości jeżeli jest stringiem
    string getWartoscString(int wiersz, int kolumna) const;

    // Zwracanie wartości jeżeli jest floatem
    float getWartoscFloat(int wiersz, int kolumna) const;

    // Wyświatlanie komóki
    void wyswietl() const;

    void usunWiersz(int wiersz);

    void usunKolumne(int kolumna);

    void dodajWiersz();

    void dodajKolune();

    string getRodzajKomorki(int wiersz, int kolumna) const;

    float sum(int wiersz1, int kolumna1, int wiersz2, int kolumna2) const;

    float srednia(int wiersz1, int kolumna1, int wiersz2, int kolumna2) const;

    void zapiszArkusz(string nazwa) const;

    void wczytajArkusz(string nazwa);

    ~arkusz();


};


#endif //PPO_EXCEL_ARKUSZ_H
