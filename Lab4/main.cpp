#include <iostream>
#include <string>
#include "./include/oblicz.h"
#include "./include/wykonajEksperyment.h"
using namespace std;

int main()
{
    ofstream plik2;
    string nazwa2="wyniki obliczen2";
    //nazwa2+= to_string(i);
    plik2.open(nazwa2);
    //plik2<<liczydlo.TabWyliczona;

    int LiczbaDanych[]= {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    for(int i=0;i<7;i++)
    {
        wygenerujDaneTestowe(LiczbaDanych[i]);
        wykonajEksperyment A;
        A.test();
        //for(int i=0;i<LICZBAPRZEBIEGOW;i++)
        //cout<<"Czas dla przebiegu nr "<<i+1<<": "<<A.czasyRealizacji[i]<<" ns   "<<"Liczba błędów: "<<A.liczbaBledow[i]<<endl;
        plik2<<"danych "<<LiczbaDanych[i]<<"czas obliczen: "<<A.sredniCzas<<" ns   "<<"ilość błędów: "<<A.sumaBledow<<" Dla "<<LICZBAPRZEBIEGOW<<" przebiegow."<<endl;
    }
    plik2.close();
    return 0;
}
