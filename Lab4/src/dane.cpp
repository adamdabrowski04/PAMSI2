#include "../include/dane.h"


using namespace std;

dane::dane()
{
    rozmiarTablicy=10;
    liczbaDanych=0;
    pTab=new int[rozmiarTablicy];
}

dane::~dane()
{
    delete[](pTab);
}

void dane::dodajElement( int nowyElement)
{
    if(rozmiarTablicy>liczbaDanych)
    {
        pTab[liczbaDanych++]=nowyElement;
    }
    else
    {
        this->powiekszTab();
        pTab[liczbaDanych++]=nowyElement;
    }
}

void dane::powiekszTab()
{
        rozmiarTablicy*=2;
        int *pTmp=new int[rozmiarTablicy];
        for(unsigned int i=0; i<liczbaDanych;i++)
        {
            pTmp[i]=pTab[i];
        }
        delete[]pTab;
        pTab=pTmp;
}

bool dane::zamienElementy( unsigned int i, unsigned int j)
{
 if(i>liczbaDanych||j>liczbaDanych) return false;
 else
 {
    int tmp;
    tmp=pTab[i];
    pTab[i]=pTab[j];
    pTab[j]=tmp;
    return true;
 }
}


void dane::odwrocTablice()
{
    for(unsigned int i=0; i<liczbaDanych/2; i++)
    {
        this->zamienElementy( i, liczbaDanych-1-i);
    }
}

ostream& operator<<(ostream & strmWy, dane& a)
{
for(unsigned int i=0;i<a.liczbaDanych; i++)
strmWy<<a.pTab[i]<<endl;
return strmWy;
}

void dane::wczytaj(char *nazwaPliku)
{
    ifstream plik;

    plik.open( nazwaPliku );
    unsigned int liczbaDanychDoWczytania;
    plik>>liczbaDanychDoWczytania;
    int tmp;
    for(unsigned int j=0;j<liczbaDanychDoWczytania;j++)
        {
        plik>>tmp;
        this->dodajElement(tmp);
        }
    plik.close();
    this->liczbaDanych=liczbaDanychDoWczytania;
}




bool dane::operator==(dane tab2)const
{
    if((liczbaDanych!=tab2.liczbaDanych))
    {
        cerr<<"Liczba danych jest różna-porównywanie nie ma sensu."<<endl;
        return false;
    }
    else
    {
        for(unsigned int i=0; i<liczbaDanych;i++)
        {
            if(pTab[i]!=tab2.pTab[i])
            return false;
        }
        return true;
    }
}

dane& dane::operator=(dane&tab)
{   liczbaDanych=0;
    for(unsigned int i=0;i<tab.liczbaDanych;i++)
    {
        this->dodajElement(tab.pTab[i]);
    }
      return *this;
}

