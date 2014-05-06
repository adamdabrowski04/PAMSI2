#ifndef KOLEJKA1_H
#define KOLEJKA1_H

#include "../include/kolejka.h"
#include<iostream>
using namespace std;
template<class TYP>
kolejka<TYP>::kolejka()
{
    rozmiarTablicy=2;
    liczbaDanych=0;
    iloscZdjetych=0;
    pTab=new TYP[rozmiarTablicy];
}
template<class TYP>
kolejka<TYP>::~kolejka()
{
     delete[](pTab);
}


template<class TYP>
void kolejka<TYP>::powiekszTab(typPowiekszania parametr)
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
void kolejka<TYP>::przesunElementy(void)
{
    if(iloscZdjetych>0)
    {
        for(unsigned int i=0;i>liczbaDanych;i++)
        {
            pTab[i]=pTab[i+iloscZdjetych];
        }
        for(unsigned int i=0;i>liczbaDanych;i++)
        {
            pTab[i+iloscZdjetych]=0;
        }
        iloscZdjetych=0;
    }
}

template<class TYP>
void kolejka<TYP>::enqueue(TYP nowy)
{
    if(rozmiarTablicy<=liczbaDanych)
    {
        if(4*iloscZdjetych>rozmiarTablicy)
            this->przesunElementy();
        else
            this->powiekszTab(x2);
    }
    pTab[liczbaDanych+iloscZdjetych]=nowy;
    liczbaDanych++;
}

template<class TYP>
TYP kolejka<TYP>::dequeue()
{
    TYP element;
    element=pTab[liczbaDanych+iloscZdjetych-1];
    liczbaDanych--;
    iloscZdjetych++;
    if(4*liczbaDanych<=rozmiarTablicy&&liczbaDanych>0)
    {
        this->zmniejszTab();
    }
    return element;
}
template<class TYP>
bool kolejka<TYP>::zmniejszTab()
{   if(liczbaDanych*2>rozmiarTablicy)
    {
    cerr<<"!Nie mozna zmniejszyc tablicy poniewaz w mniejszej nie zmieszcza sie dane."<<endl;
    return false;
    }
    this->przesunElementy();
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
void kolejka<TYP>::wypiszTablice()
{
for(unsigned int i=0;i<liczbaDanych; i++)
cout<<pTab[i+iloscZdjetych]<<endl;
}

#endif
