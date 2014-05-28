
#include <iostream>
#include "src/TabblicaAsocjacyjna.cpp"
#include "include/Element.h"
#include<string>

using namespace std;

int main()
{
Tablica_Haszujaca<string, string> tab(10);
tab.Dodaj(string("aba"), string("pies")  );
    cout << "Hello world!" << tab.Pobierz(string("aba"))<<endl;
      char a;
    cin>> a;
    return 0;

}
