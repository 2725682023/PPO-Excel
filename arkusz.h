#ifndef PPO_EXCEL_ARKUSZ_H
#define PPO_EXCEL_ARKUSZ_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "komorka.h"
#include "komorkaFloat.h"
#include "komorkaStringa.h"

class Arkusz {
private:
    std::vector<std::vector<Komorka*>> arkusz;

public:
    /*
        * Konstruktor domyślny
        * @param brak
        * @return brak
     */
    Arkusz() {}

    /*
        * Dodaje komumnę na koniec arkusza
        * @param brak
        * @return brak
     */
    void dodajKolumne();

    /*
        * Dodaje wiersz na dole arkusza
        * @param brak
        * @return brak
     */
    void dodajWiersz();

    /*
        * Usuwa wybraną komumnę
        * @param kolumna - kolumna do usunięcia
        * @return brak
     */
    void usunKolumne(int kolumna);

    /*
        * Usuwa wybrany wiersz
        * @param wiersz - wiersz do usunięcia
        * @return brak
     */
    void usunWiersz(int wiersz);

    /*
        * Sprawdza czy string jest liczbą
        * @param wartosc - string do sprawdzenia
        * @return true jeżeli jest liczbą, false jeżeli nie jest
     */
    bool czyLiczba(const std::string& wartosc) const;

    /*
        * Ustawia wartość komórki na podstawie podanych parametrów
        * @param wartosc - wartość do ustawienia
        * @param wiersz - wiersz
        * @param komumna - kolumna
        * @return brak
     */
    void wprowadzDane(const std::string& wartosc, int wiersz, int kolumna);

    /*
        * Zwraca sumę komórek jeżeli są liczbami, jeżeli są stringami zwraca je połączone, jeżeli są różne zwraca "Błąd"
        * @param wiersz_pocz - wiersz początkowy
        * @param kolumna_pocz - kolumna początkowa
        * @param wiersz_kon - wiersz końcowy
        * @param kolumna_kon - kolumna końcowa
        * @return suma komórek
     */
    std::string sumujZakres(int wiersz_pocz, int kolumna_pocz, int wiersz_kon, int kolumna_kon);

    /*
        * Zwraca średnią komórek jeżeli są liczbami
        * @param wiersz_pocz - wiersz początkowy
        * @param kolumna_pocz - kolumna początkowa
        * @param wiersz_kon - wiersz końcowy
        * @param kolumna_kon - kolumna końcowa
        * @return średnia komórek
     */
    std::string sredniaZakres(int wiersz_pocz, int kolumna_pocz, int wiersz_kon, int kolumna_kon);

    /*
        * Wyświatlanie wszystkich komórek arkusza
        * @param brak
        * @return brak
     */
    void wypiszArkusz();

    /*
        * Wypisuje rozmiar arkusza - funkcja pomocnicza
        * @param brak
        * @return brak
     */
    void rozmiarArkusza();

    /*
        * Zwraca rodzaj komórki
        * @param wiersz - wiersz
        * @param kolumna - kolumna
        * @return rodzaj komórki
     */
    std::string getRodzajKomorki(int wiersz, int kolumna) const;

    /*
        * Zapisuje arkusz do pliku
        * @param nazwa - nazwa pliku
        * @return none
     */
    void zapiszArkusz(std:: string nazwa) const;

    /*
        * Wczytuje arkusz z pliku
        * @param nazwa - nazwa pliku
        * @return none
     */
    void wczytajArkusz(std::string nazwa);

    /*
        * Destruktor
     */
    ~Arkusz();
};

#endif //PPO_EXCEL_ARKUSZ_H
