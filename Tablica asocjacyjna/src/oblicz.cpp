#include "../include/oblicz.h"
#include "../include/dane.h"

using namespace std;
oblicz::oblicz()
{
    TabDanych.wczytaj("dane");
    TabSprawdzenie.wczytaj("sprawdzenie");

 }

oblicz::~oblicz()
{


}


double oblicz::wykonajObliczenia()
{
   TabWyliczona=TabSprawdzenie;

    typedef std::chrono::high_resolution_clock high_resolution_clock;
    typedef std::chrono::nanoseconds nanoseconds;
    high_resolution_clock::time_point start, koniec;
    nanoseconds czasTrwaniaObliczen;
    start=high_resolution_clock::now();
            //TabWyliczona.bubbleSort();
            TabWyliczona.quickSort(0, (int)TabWyliczona.liczbaDanych -1 );
            //TabWyliczona.heapSort();
    koniec=high_resolution_clock::now();
    czasTrwaniaObliczen=std::chrono::duration_cast<nanoseconds>(koniec - start);

    return czasTrwaniaObliczen.count();

}

unsigned int oblicz::wykonajSprawdzenie()
{
liczbaBledow=0;
for(unsigned int i=0; i<TabDanych.liczbaDanych;i++)
{
    if(TabWyliczona.pTab[i]!=TabSprawdzenie.pTab[i])  //TabDanych jest tuaj wczytaną tablicą poprawnych rozwiązań
    liczbaBledow++;
}
return liczbaBledow;
}


void oblicz::dodajElementy(dane tab1, dane tab2)
{
    int tmp;
    cout<<"Podaj pierwszy element do dodania\n/>"<<flush;
    cin>>tmp;
    tab1.dodajElement(tmp);
    cout<<"Podaj drugi element do dodania\n/>"<<flush;
    cin>>tmp;
    tab2.dodajElement(tmp);
}

void oblicz::dodajElementy(dane tab1, dane tab2, int element1, int element2)
{
    tab1.dodajElement(element1);
    tab2.dodajElement(element2);
}





