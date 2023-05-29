#ifndef PPO_EXCEL_KOMORKAINTERFACE_H
#define PPO_EXCEL_KOMORKAINTERFACE_H

#include <iostream>

using namespace std;

class komorkaInterface {
public:
    virtual void setWartosc(const string& wartosc) = 0;
    virtual void setWartosc(const float wartosc) = 0;
    virtual string getWartoscString() const = 0;
    virtual float getWartoscFloat() const = 0;
    virtual void wyswietl() const = 0;
};


#endif //PPO_EXCEL_KOMORKAINTERFACE_H
