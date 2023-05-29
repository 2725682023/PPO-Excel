#include <iostream>
#include "arkusz.h"

using namespace std;

int main()
{
    arkusz arkusz1;
    arkusz1.dodajKolune();
    arkusz1.dodajKolune();
    arkusz1.dodajKolune();
    arkusz1.dodajWiersz();
    arkusz1.dodajWiersz();
    arkusz1.dodajWiersz();
    arkusz1.setWartosc(0,0,1);
    arkusz1.setWartosc(0,1,2);
    arkusz1.setWartosc(0,2,3);
    arkusz1.setWartosc(1,0,2);
    arkusz1.setWartosc(1,1,3);
    arkusz1.setWartosc(1,2,2);
    arkusz1.setWartosc(2,0,"ala");
    arkusz1.setWartosc(2,1,"ma");
    arkusz1.setWartosc(2,2,"kota");

    arkusz1.wyswietl();

    arkusz1.usunKolumne(1);

    arkusz1.wyswietl();

    return 0;
}

