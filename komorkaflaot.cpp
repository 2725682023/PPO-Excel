#include "komorkaflaot.h"

void komorkaflaot::setWartosc(const string& wartosc){
    this->wartosc = stof(wartosc);
}

void komorkaflaot::setWartosc(float wartosc){
    this->wartosc = wartosc;
}

string komorkaflaot::getWartoscString() const{
    return to_string(wartosc);
}

float komorkaflaot::getWartoscFloat() const{
    return wartosc;
}

void komorkaflaot::wyswietl() const{
    cout << wartosc;
}
