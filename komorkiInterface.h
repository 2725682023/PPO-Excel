#ifndef PPO_EXCEL_KOMORKIINTERFACE_H
#define PPO_EXCEL_KOMORKIINTERFACE_H

#include <string>

using namespace std;

class KomorkiInterface {
public:
    virtual string getWartosc() const = 0;
    virtual void setWartosc(const string& wartosc) = 0;
    virtual ~KomorkiInterface() {}
};
#endif //PPO_EXCEL_KOMORKIINTERFACE_H
