#include <iostream>
#include "arkusz.h"

using namespace std;

void menuglowne() {
    cout << "----------Menu----------" << endl;
    cout << "1. Wyswietl" << endl;
    cout << "2. Dodaj kolumne" << endl;
    cout << "3. Dodaj wiersz" << endl;
    cout << "4. Usun kolumne" << endl;
    cout << "5. Usun wiersz" << endl;
    cout << "6. Ustwa zawartosc komorki" << endl;
    cout << "7. Suma" << endl;
    cout << "8. Srednia" << endl;
    cout << "9. Zapisz arkusz do pliku" << endl;
    cout << "10. Wyjdz" << endl;
    cout << "------------------------" << endl;
}
int main()
{
    arkusz arkusz1;

    int x;
    cout << "Witaj w programie!!!" << endl;
    cout << endl;
    cout << "Czy chcesz wczytac arkusz z pliku? (1 - tak, 0 - nie)" << endl;
    cin >> x;
    switch (x) {
        case 1: {
            string nazwaPliku;
            cout << "Podaj nazwe pliku: " << endl;
            cin >> nazwaPliku;
            arkusz1.wczytajArkusz(nazwaPliku);

            cout << "Wczytany arkusz: " << endl;
            arkusz1.wyswietl();
            break;
        }
        case 0: {
            arkusz1.dodajKolune();
            arkusz1.dodajKolune();
            arkusz1.dodajKolune();
            arkusz1.dodajWiersz();
            arkusz1.dodajWiersz();
            arkusz1.dodajWiersz();

            cout << "Twoj arkusz ma na start 3 kolumny i 3 wiersze bez zadnych danych." << endl;
            break;
        }
        default: {
            cout << "Nie ma takiej opcji" << endl;
            break;
        }
    }
    x = 0;
    while(x == 0){
        menuglowne();
        int wybor;
        cout << endl;
        cout << "Wybierz opcje z powyzszego menu: " << endl;
        cin >> wybor;
        switch (wybor) {
            case 1: {
                arkusz1.wyswietl();
                break;
            }
            case 2: {
                arkusz1.dodajKolune();
                break;
            }
            case 3: {
                arkusz1.dodajWiersz();
                break;
            }
            case 4: {
                int kolumna;
                cout << "Podaj numer kolumny do usuniecia: " << endl;
                cin >> kolumna;
                arkusz1.usunKolumne(kolumna);
                break;
            }
            case 5: {
                int wiersz;
                cout << "Podaj numer wiersza do usuniecia: " << endl;
                cin >> wiersz;
                arkusz1.usunWiersz(wiersz);
                break;
            }
            case 6: {
                int wiersz, kolumna;
                cout << "Podaj numer wiersza: " << endl;
                cin >> wiersz;
                cout << "Podaj numer kolumny: " << endl;
                cin >> kolumna;
                int wybor2;
                cout << "Jaki typ zmiennej chcesz wprowadzic? (1 - double, 2 - string)" << endl;
                cin >> wybor2;
                if (wybor2 == 1){
                    float zmienna;
                    cout << "Podaj zmienna: " << endl;
                    cin >> zmienna;
                    arkusz1.setWartosc(wiersz, kolumna, zmienna);
                } else if (wybor2 == 2){
                    string zmienna;
                    cout << "Podaj zmienna: " << endl;
                    cin >> zmienna;
                    arkusz1.setWartosc(wiersz, kolumna, zmienna);
                } else {
                    cout << "Arkusz nie obsluguje takich typow zmiennych!!!" << endl;
                }
                break;
            }
            case 7: {
                int wiersz1, wiersz2, kolumna1, kolumna2;
                cout << "Podaj startową komorke (kolejnosc: wiersz kolumna): " << endl;
                cin >> wiersz1 >> kolumna1;
                cout << "Podaj koncowa komorke (kolejnosc: wiersz kolumna): " << endl;
                cin >> wiersz2 >> kolumna2;
                cout << "Suma: " << arkusz1.sum(wiersz1, wiersz2, kolumna1, kolumna2) << endl;
                break;
            }
            case 8: {
                int wiersz1, wiersz2, kolumna1, kolumna2;
                cout << "Podaj startową komorke (kolejnosc: wiersz kolumna): " << endl;
                cin >> wiersz1 >> kolumna1;
                cout << "Podaj koncowa komorke (kolejnosc: wiersz kolumna): " << endl;
                cin >> wiersz2 >> kolumna2;
                cout << "Srednia: " << arkusz1.srednia(wiersz1, wiersz2, kolumna1, kolumna2) << endl;
                break;
            }
            case 9: {
                string nazwa;
                cout << "Podaj nazwe pliku: " << endl;
                cin >> nazwa;
                arkusz1.zapiszArkusz(nazwa);
                break;
            }
            case 10: {
                x = 1;
                break;
            }
            default: {
                cout << "Nie ma takiej opcji w menu" << endl;
                break;
            }
        }
    }
    cout << "Dziekuje za skorzystanie z programu!!!" << endl;
    return 0;
}

