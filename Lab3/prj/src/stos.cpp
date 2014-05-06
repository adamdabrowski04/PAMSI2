#include "../include/stos.h"
#ifndef DANE1_H
#define DANE1_H

using namespace std;

template<class TYP>
stos<TYP>::stos()
{
    rozmiarTablicy=2;
    liczbaDanych=0;
    pTab=new TYP[rozmiarTablicy];
}

template<class TYP>
stos<TYP>::~stos()
{
    delete[](pTab);
}

template<class TYP>
void stos<TYP>::PUSH( TYP nowyElement)
{
    if(rozmiarTablicy<=liczbaDanych)
    {
        this->powiekszTab(x2);
    }
    pTab[liczbaDanych++]=nowyElement;

}


template<class TYP>
TYP stos<TYP>::POP()
{
    TYP zdjetyElement;

    zdjetyElement=pTab[liczbaDanych-1];
    liczbaDanych--;
     if((4*liczbaDanych) <=rozmiarTablicy && liczbaDanych>0)
    {
        this->zmniejszTab();
    }
    return zdjetyElement;
}


template<class TYP>
void stos<TYP>::powiekszTab(typPowiekszania parametr)
{
    const unsigned int dodatek=1;
    if(parametr==o1)
        rozmiarTablicy=rozmiarTablicy+dodatek;
    else
        rozmiarTablicy*=2;
    TYP *pTmp=new TYP[rozmiarTablicy];
    for(unsigned int i=0; i<liczbaDanych;i++)
    {
        pTmp[i]=pTab[i];
    }
    delete[]pTab;
    pTab=pTmp;

}


template<class TYP>
bool stos<TYP>::zmniejszTab()
{   if(liczbaDanych*2>rozmiarTablicy)
    {
    cerr<<"!Nie mozna zmniejszyc tablicy poniewaz w mniejszej nie zmieszcza sie dane."<<endl;
    return false;
    }
    rozmiarTablicy=rozmiarTablicy/2;
    TYP *pTmp=new TYP[rozmiarTablicy];
    for(unsigned int i=0; i<liczbaDanych;i++)
    {
        pTmp[i]=pTab[i];
    }
    delete[]pTab;
    pTab=pTmp;
    return true;
 }

template<class TYP>
unsigned int stos<TYP>::size()
{
    return liczbaDanych;
}

template<class TYP>
void stos<TYP>::wypiszTablice()
{
for(unsigned int i=0;i<liczbaDanych; i++)
cout<<pTab[i]<<endl;
}


#endif // DANE_H


