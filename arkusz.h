#ifndef PPO_EXCEL_ARKUSZ_H
#define PPO_EXCEL_ARKUSZ_H

#include <iostream>
#include <vector>
#include "komorkaString.h"
#include "komorkaflaot.h"

using namespace std;

class arkusz {
private:
    vector<vector<komorka*>> komorki;

    /*
        * Sprawdza czy string jest liczbą
        * @pharm wartosc - string do sprawdzenia
        * @return true jeżeli jest liczbą, false jeżeli nie jest
     */
    bool czyLiczba(const string& wartosc) const;

public:
    /*
        * Ustawia wartość komórki jeżeli to string
        * @pharm wiersz - wiersz
        * @pharm komumna - kolumna
        * @pharm wartosc - wartość do ustawienia
        * @return brak
     */
    void setWartosc(int wiersz, int kolumna, const string& wartosc);

    /*
        * Ustawia wartość komórki jeżeli to string
        * @pharm wiersz - wiersz
        * @pharm komumna - kolumna
        * @pharm wartosc - wartość do ustawienia
        * @return brak
     */
    void setWartosc(int wiersz, int kolumna, const float wartosc);

    /*
        * Zwracanie wartości jeżeli jest stringiem
        * @pharm wiersz - wiersz
        * @pharm komumna - kolumna
        * @return wartość komórki
     */
    string getWartoscString(int wiersz, int kolumna) const;

    /*
        * Zwracanie wartości jeżeli jest floatem
        * @pharm wiersz - wiersz
        * @pharm komumna - kolumna
        * @return wartość komórki
     */
    float getWartoscFloat(int wiersz, int kolumna) const;

    /*
        * Wyświatlanie wszystkie komóki
        * @pharm brak
        * @return brak
     */
    void wyswietl() const;

    /*
        * Usuwa wybrany wiersz
        * @pharm wiersz - wiersz
        * @return brak
     */
    void usunWiersz(int wiersz);

    /*
        * Usuwa wybraną komumnę
        * @pharm kolumna - kolumna
        * @return brak
     */
    void usunKolumne(int kolumna);

    /*
        * Dodaje wiersz
        * @pharm brak
        * @return brak
     */
    void dodajWiersz();

    /*
        * Dodaje komumnę
        * @pharm brak
        * @return brak
     */
    void dodajKolune();

    /*
        * Zwraca rodzaj komórki
        * @pharm wiersz - wiersz
        * @pharm kolumna - kolumna
        * @return rodzaj komórki
     */
    string getRodzajKomorki(int wiersz, int kolumna) const;

    /*
        * Zwraca sumę komórek
        * @pharm wiersz1 - wiersz początkowy
        * @pharm kolumna1 - kolumna początkowa
        * @pharm wiersz2 - wiersz końcowy
        * @pharm kolumna2 - kolumna końcowa
        * @return suma komórek
     */
    float sum(int wiersz1, int kolumna1, int wiersz2, int kolumna2) const;

    /*
        * Zwraca średnią komórek
        * @pharm wiersz1 - wiersz początkowy
        * @pharm kolumna1 - kolumna początkowa
        * @pharm wiersz2 - wiersz końcowy
        * @pharm kolumna2 - kolumna końcowa
        * @return średnia komórek
     */
    float srednia(int wiersz1, int kolumna1, int wiersz2, int kolumna2) const;

    /*
        * Zapisuje arkusz do pliku
        * @pharm nazwa - nazwa pliku
        * @return none
     */
    void zapiszArkusz(string nazwa) const;

    /*
        * Wczytuje arkusz z pliku
        * @pharm nazwa - nazwa pliku
        * @return none
     */
    void wczytajArkusz(string nazwa);

    /*
        * Destruktor
     */
    ~arkusz();


};


#endif //PPO_EXCEL_ARKUSZ_H
