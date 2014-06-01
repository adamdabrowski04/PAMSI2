
#include <iostream>
#include "src/TabblicaAsocjacyjna.cpp"
#include "include/Element.h"
#include "include/wykonajEksperyment.h"


using namespace std;

int main()
{
    wykonajEksperyment aa;
    aa.wyborPojemnika = wykonajEksperyment::WCZYTYWANIE;
    aa.test();
    aa.wyborPojemnika= wykonajEksperyment::WYSZUKIWANIE;
    aa.test();
    return 0;
}
