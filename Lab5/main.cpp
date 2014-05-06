
#include <iostream>
#include "include/TabblicaAsocjacyjna.h"
#include "include/Element.h"


using namespace std;

int main()
{
Tablica_Asocjacyjna<int> tab;
tab.Dodaj(12,12);
    cout << "Hello world!" << tab.Pobierz(12)<<endl;
    return 0;
}
