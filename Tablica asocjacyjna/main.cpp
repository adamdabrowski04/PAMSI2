
#include <iostream>
#include "src/TabblicaAsocjacyjna.cpp"
#include "include/Element.h"


using namespace std;

int main()
{
Tablica_Asocjacyjna<int, int> tab;
tab.Dodaj(12,112);
    cout << "Hello world!" << tab.Pobierz(12)<<endl;
    return 0;
}
