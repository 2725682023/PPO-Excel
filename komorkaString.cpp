#include "komorkaString.h"

void komorkaString::setWartosc(const string& wartosc){
    this->wartosc = wartosc;
}

void komorkaString::setWartosc(const float wartosc){

}

string komorkaString::getWartoscString() const{
    return wartosc;
}

float komorkaString::getWartoscFloat() const{
    return 0.0f;
}

void komorkaString::wyswietl() const{
    cout << wartosc;
}
