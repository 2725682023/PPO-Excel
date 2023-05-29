#include <fstream>
#include <sstream>
#include "arkusz.h"

bool arkusz::czyLiczba(const string& wartosc) const{
    for(int i = 0; i < wartosc.length(); i++){
        if(!isdigit(wartosc[i])){
            return false;
        }
    }
    return true;
}

void arkusz::setWartosc(int wiersz, int kolumna, const string &wartosc){
    if(wiersz >= komorki.size()){
        komorki.resize( wiersz + 1);
    }
    if(kolumna >= komorki[wiersz].size()){
        komorki[wiersz].resize( kolumna + 1, nullptr);
    }
    if(komorki[wiersz][kolumna] == nullptr){
        if(czyLiczba(wartosc)){
            komorki[wiersz][kolumna] = new komorkaflaot();
        } else {
            komorki[wiersz][kolumna] = new komorkaString();
        }
    }
    komorki[wiersz][kolumna]->setWartosc(wartosc);
}

void arkusz::setWartosc(int wiersz, int kolumna, float wartosc){
    if(wiersz >= komorki.size()){
        komorki.resize( wiersz + 1);
    }
    if(kolumna >= komorki[wiersz].size()){
        komorki[wiersz].resize( kolumna + 1, nullptr);
    }
    if(komorki[wiersz][kolumna] == nullptr){
        komorki[wiersz][kolumna] = new komorkaflaot();
    }
    komorki[wiersz][kolumna]->setWartosc(wartosc);
}

string arkusz::getWartoscString(int wiersz, int kolumna) const{
    if(wiersz < komorki.size() && kolumna < komorki[wiersz].size() && komorki[wiersz][kolumna] != nullptr){
        return komorki[wiersz][kolumna]->getWartoscString();
    }
    return "";
}

float arkusz::getWartoscFloat(int wiersz, int kolumna) const{
    if(wiersz < komorki.size() && kolumna < komorki[wiersz].size() && komorki[wiersz][kolumna] != nullptr){
        return komorki[wiersz][kolumna]->getWartoscFloat();
    }
    return 0.0f;
}

void arkusz::wyswietl() const{
    for(int i = 0; i < komorki.size(); i++){
        for(int j = 0; j < komorki[i].size(); j++){
            cout << getWartoscString(i , j) << "\t\t";
        }
        cout << "\n\n";
    }
}

void arkusz::usunWiersz(int wiersz){
    if(wiersz < komorki.size()){
        komorki.erase(komorki.begin() + wiersz);
    }
}

void arkusz::usunKolumne(int kolumna){
    if(kolumna < komorki[0].size()){
        for(int i = 0; i < komorki.size(); i++){
            komorki[i].erase(komorki[i].begin() + kolumna);
        }
    }
}

void arkusz::dodajWiersz(){
    komorki.resize(komorki.size() + 1);
}

void arkusz::dodajKolune(){
    for(int i = 0; i < komorki.size(); i++){
        komorki[i].resize(komorki[i].size() + 1, nullptr);
    }
}

string arkusz::getRodzajKomorki(int wiersz, int kolumna) const{
    if(wiersz < komorki.size() && kolumna < komorki[wiersz].size() && komorki[wiersz][kolumna] != nullptr){
        if( dynamic_cast<komorkaflaot *>(komorki[wiersz][kolumna])){
            return "komorkafloat";
        } else if(dynamic_cast<komorkaString *>(komorki[wiersz][kolumna])){
            return "komorkaString";
        }
    }
    return "komorka";
}

float arkusz::sum(int wiersz1, int kolumna1, int wiersz2, int kolumna2) const{
    float sum = 0.0f;
    for (int i = wiersz1; i <= wiersz2; i++)
    {
        for (int j = kolumna1; j <= kolumna2; j++)
        {
            if (wiersz1 < komorki.size() && kolumna1 < komorki[wiersz1].size() && komorki[wiersz1][kolumna1] != nullptr)
            {
                if (dynamic_cast<komorkaflaot *>(komorki[wiersz1][kolumna1]))
                {
                    sum += komorki[wiersz1][kolumna1]->getWartoscFloat();
                }
                else if (dynamic_cast<komorkaString *>(komorki[wiersz1][kolumna1]))
                {
                    return 0.0f;
                }
            }
        }
    }
    return sum;
}

float arkusz::srednia(int wiersz1, int kolumna1, int wiersz2, int kolumna2) const{
    float sum = 0.0f;
    int count = 0;
    for (int i = wiersz1; i <= wiersz2; i++)
    {
        for (int j = kolumna1; j <= kolumna2; j++)
        {
            if (wiersz1 < komorki.size() && kolumna1 < komorki[wiersz1].size() && komorki[wiersz1][kolumna1] != nullptr)
            {
                if (dynamic_cast<komorkaflaot *>(komorki[wiersz1][kolumna1]))
                {
                    sum += komorki[wiersz1][kolumna1]->getWartoscFloat();
                    count++;
                }
                else if (dynamic_cast<komorkaString *>(komorki[wiersz1][kolumna1]))
                {
                    return 0.0f;
                }
            }
        }
    }
    return sum/count;
}
void arkusz::zapiszArkusz(string nazwa) const{
    ofstream file;
    file.open(nazwa);
    if (file.is_open())
    {
        file << komorki.size() << "," << komorki[0].size() << std::endl;
        for (int i = 0; i < komorki.size(); i++)
        {
            for (int j = 0; j < komorki[i].size(); j++)
            {
                if (komorki[i][j] != nullptr)
                {
                    file << getRodzajKomorki(i,j) << "," << komorki[i][j]->getWartoscString() << "," << i << "," << j << endl;
                }
            }
        }
    }
    file.close();
}

void arkusz::wczytajArkusz(string nazwa){
    ifstream file;
    file.open(nazwa);
    if (file.is_open())
    {

        string line;
        getline(file, line);
        stringstream ss(line);
        string token;
        vector<string> tokens;
        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }
        int wiersze = stoi(tokens[0]);
        int kolumny = stoi(tokens[1]);
        komorki.resize(wiersze);
        for (int i = 0; i < wiersze; i++)
        {
            komorki[i].resize(kolumny);
        }

        while (getline(file, line))
        {
            stringstream ss(line);
            vector<string> tokens;
            while (getline(ss, token, ','))
            {
                tokens.push_back(token);
            }
            int wiersz = stoi(tokens[2]);
            int kolumna = stoi(tokens[3]);
            if (tokens[0] == "NumericCell")
            {
                komorki[wiersz][kolumna] = new komorkaflaot();
                komorki[wiersz][kolumna]->setWartosc(stof(tokens[1]));
            }
            else if (tokens[0] == "StringCell")
            {
                komorki[wiersz][kolumna] = new komorkaString();
                komorki[wiersz][kolumna]->setWartosc(tokens[1]);
            }
            else if (tokens[0] == "Cell")
            {
                komorki[wiersz][kolumna] = new komorkaString();
                komorki[wiersz][kolumna]->setWartosc("");
            }
        }


    }
    file.close();
}

arkusz::~arkusz() {
    for (auto &wiersz : komorki)
    {
        for (auto &komorka : wiersz)
        {
            delete komorka;
        }
    }
}