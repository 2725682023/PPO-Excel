#include "arkusz.h"

void Arkusz::dodajKolumne() {
    for(int i = 0; i < arkusz.size(); i++){
        arkusz[i].resize(arkusz[i].size() + 1, nullptr);
    }
}

void Arkusz::dodajWiersz() {
    arkusz.resize(arkusz.size() + 1);
}

void Arkusz::usunKolumne(int kolumna) {
    if(kolumna < arkusz[0].size()){
        for(int i = 0; i < arkusz.size(); i++){
            arkusz[i].erase(arkusz[i].begin() + kolumna);
        }
    }
}

void Arkusz::usunWiersz(int wiersz) {
    if(wiersz < arkusz.size()){
        arkusz.erase(arkusz.begin() + wiersz);
    }
}

bool Arkusz::czyLiczba(const std::string& wartosc) const{
    for(int i = 0; i < wartosc.length(); i++){
        if(!isdigit(wartosc[i])){
            return false;
        }
    }
    return true;
}

void Arkusz::wprowadzDane(const std::string& wartosc, int wiersz, int kolumna) {
    if(wiersz >= arkusz.size()){
        arkusz.resize( wiersz + 1);
    }
    if(kolumna >= arkusz[wiersz].size()){
        arkusz[wiersz].resize( kolumna + 1, nullptr);
    }
    if(arkusz[wiersz][kolumna] == nullptr){
        if(czyLiczba(wartosc)){
            arkusz[wiersz][kolumna] = new KomorkaFloat();
        } else {
            arkusz[wiersz][kolumna] = new KomorkaStringa();
        }
    }
    arkusz[wiersz][kolumna]->setWartosc(wartosc);
}

std::string Arkusz::sumujZakres(int wiersz_pocz, int kolumna_pocz, int wiersz_kon, int kolumna_kon) {
    if (wiersz_pocz >= 0 && wiersz_pocz < arkusz.size() && wiersz_kon >= 0 && wiersz_kon < arkusz.size() &&
        kolumna_pocz >= 0 && kolumna_pocz < arkusz[0].size() && kolumna_kon >= 0 && kolumna_kon < arkusz[0].size()) {
        bool isFloat = false;
        bool isString = false;
        float sumaFloat = 0.0f;
        std::string sumaString = "";

        for (int wiersz = wiersz_pocz; wiersz <= wiersz_kon; ++wiersz) {
            for (int kolumna = kolumna_pocz; kolumna <= kolumna_kon; ++kolumna) {
                if (auto komorkaFloat = dynamic_cast<KomorkaFloat*>(arkusz[wiersz][kolumna])) {
                    isFloat = true;
                    sumaFloat += komorkaFloat->getFloatWartosc();
                } else if (auto komorkaStringa = dynamic_cast<KomorkaStringa*>(arkusz[wiersz][kolumna])) {
                    isString = true;
                    sumaString += komorkaStringa->getWartosc();
                } else {
                    std::cout << "Błąd: Wybrany zakres zawiera komórki różnego typu." << std::endl;
                    return "";
                }
            }
        }

        if (isFloat && isString) {
            std::cout << "Błąd: Wybrany zakres zawiera komórki różnego typu." << std::endl;
            return "";
        } else if (isFloat) {
            return std::to_string(sumaFloat);
        } else if (isString) {
            return sumaString;
        }
    } else {
        std::cout << "Błąd: Nieprawidłowe współrzędne zakresu." << std::endl;
    }

    return "";
}

std::string Arkusz::sredniaZakres(int wiersz_pocz, int kolumna_pocz, int wiersz_kon, int kolumna_kon) {
    float sum = 0.0f;
    int ilosc = 0;
    if (wiersz_pocz < arkusz.size() && kolumna_pocz < arkusz[wiersz_pocz].size() && arkusz[wiersz_pocz][kolumna_pocz] != nullptr && wiersz_kon <= arkusz.size() && kolumna_kon <= arkusz[wiersz_kon].size()) {
        for (int i = wiersz_pocz; i <= wiersz_kon; i++) {
            for (int j = kolumna_pocz; j <= kolumna_kon; j++) {
                if(auto komorkaFloat = dynamic_cast<KomorkaFloat *>(arkusz[i][j])){
                    sum += komorkaFloat->getFloatWartosc();
                    ilosc++;
                } else if(dynamic_cast<KomorkaStringa *>(arkusz[i][j])){
                    std::cout << "W zakresie wystepuja komorki typu string" << std::endl;
                    return "";
                }
            }
        }
    } else {
        std::cout << "Nie ma takich komorek, wyszedłes poza arkusz!!!" << std::endl;
    }
    float srednia1 = sum / ilosc;

    return std::to_string(srednia1);
}

void Arkusz::wypiszArkusz() {
    for (const auto& wiersz : arkusz) {
        for (const auto& komorka : wiersz) {
            std::cout << komorka->getWartosc() << "\t";
        }
        std::cout << std::endl;
    }
}

void Arkusz::rozmiarArkusza() {
    std::cout << "Liczba wierszy: " << arkusz.size() << std::endl;
    std::cout << "Liczba kolumn: " << arkusz[0].size() << std::endl;
}

std::string Arkusz::getRodzajKomorki(int wiersz, int kolumna) const{
    if(wiersz < arkusz.size() && kolumna < arkusz[wiersz].size() && arkusz[wiersz][kolumna] != nullptr){
        if( dynamic_cast<KomorkaFloat *>(arkusz[wiersz][kolumna])){
            return "komorkafloat";
        } else if(dynamic_cast<KomorkaStringa *>(arkusz[wiersz][kolumna])){
            return "komorkaString";
        }
    }
    return "komorka";
}

void Arkusz::zapiszArkusz(std:: string nazwa) const{
    std::ofstream file;
    file.open(nazwa);
    if (file.is_open())
    {
        file << arkusz.size() << "," << arkusz[0].size() << std::endl;
        for (int i = 0; i < arkusz.size(); i++)
        {
            for (int j = 0; j < arkusz[i].size(); j++)
            {
                if (arkusz[i][j] != nullptr)
                {
                    file << getRodzajKomorki(i,j) << "," << arkusz[i][j]->getWartosc() << "," << i << "," << j << std::endl;
                }
            }
        }
    }
    file.close();
}

void Arkusz::wczytajArkusz(std::string nazwa){
    std::ifstream plik;
    plik.open(nazwa);
    if (plik.is_open())
    {

        std::string line;
        getline(plik, line);
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        int wiersze = stoi(tokens[0]);
        int kolumny = stoi(tokens[1]);
        arkusz.resize(wiersze);
        for (int i = 0; i < wiersze; i++)
        {
            arkusz[i].resize(kolumny);
        }

        while (getline(plik, line))
        {
            std::stringstream ss(line);
            std::vector<std::string> tokens;
            while (getline(ss, token, ','))
            {
                tokens.push_back(token);
            }
            int wiersz = stoi(tokens[2]);
            int kolumna = stoi(tokens[3]);
            if (tokens[0] == "NumericCell")
            {
                arkusz[wiersz][kolumna] = new KomorkaFloat();
                arkusz[wiersz][kolumna]->setWartosc(tokens[1]);
            }
            else if (tokens[0] == "StringCell")
            {
                arkusz[wiersz][kolumna] = new KomorkaStringa();
                arkusz[wiersz][kolumna]->setWartosc(tokens[1]);
            }
            else if (tokens[0] == "Cell")
            {
                arkusz[wiersz][kolumna] = new KomorkaStringa();
                arkusz[wiersz][kolumna]->setWartosc("");
            }
        }
    }
    plik.close();
}

Arkusz::~Arkusz() {
    for (auto& wiersz : arkusz) {
        for (auto& komorka : wiersz) {
            delete komorka;
        }
    }
}