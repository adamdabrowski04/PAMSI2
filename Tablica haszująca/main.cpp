
#include <iostream>
#include "src/TabblicaAsocjacyjna.cpp"
#include "include/Element.h"
#include "include/wykonajEksperyment.h"
#include<string>

using namespace std;

int main()
{

      char a;


     wykonajEksperyment aa;
//      aa.wyborPojemnika=wykonajEksperyment::WCZYTYWANIE;
//      aa.test();
      aa.wyborPojemnika=wykonajEksperyment::WYSZUKIWANIE;
      aa.test();
    cin>> a;
    return 0;

}
