#include "../include/wykonajEksperyment.h"

using namespace std;
wykonajEksperyment::wykonajEksperyment()
{
    pTabCzasyKolejnychSeriiDanych=new  long double[rozmiarTabIlosciDanych];
    pTabIloscDanych= new unsigned  int[rozmiarTabIlosciDanych];
    for(unsigned int i=0;i<rozmiarTabIlosciDanych;i++)
        pTabIloscDanych[i]=potega(10, i);

}

wykonajEksperyment::~wykonajEksperyment()
{
    //dtor
}

void wykonajEksperyment::test()
{
    ofstream oStrm;
    string nazwaPliku;
        switch(wyborPojemnika)
    {
    case WCZYTYWANIE:
       nazwaPliku="Wczytywanie_";
       break;
    case WYSZUKIWANIE:
         nazwaPliku="Wyszukiwanie_";
        break;
    default:
        cerr<<"Nie istnieje taka funkcja do sprawdzenia"<<endl;
        break;
    }
    nazwaPliku+="IlosciDanych10^";
    nazwaPliku+=to_string(rozmiarTabIlosciDanych);
    nazwaPliku+="_liczbaWywolan_";
    nazwaPliku+=to_string(liczbaWywolan);
    nazwaPliku+=".csv";
    oStrm.open(nazwaPliku);
    for(unsigned int i=0; i<rozmiarTabIlosciDanych;i++)
    {
        pTabCzasyKolejnychSeriiDanych[i]=this->seriaPomiarow(liczbaWywolan, pTabIloscDanych[i] );
        //oStrm.width(10);
        oStrm<<pTabIloscDanych[i]<<" "<<pTabCzasyKolejnychSeriiDanych[i]<<endl;
        cout.width(10);
        cout<<pTabIloscDanych[i]<<"  "<<pTabCzasyKolejnychSeriiDanych[i]<<endl;
    }
    oStrm.close();
}


unsigned int wykonajEksperyment::seriaPomiarow(unsigned int liczbaWywolan, unsigned int iloscDanych)
{
    long double sredniCzas=0;
    for(unsigned int i=0; i<liczbaWywolan; i++)
    {
        sredniCzas+=this->zmierzCzasTrwania(iloscDanych)/liczbaWywolan;
    }
    return sredniCzas;
}

double wykonajEksperyment::zmierzCzasTrwania(unsigned int iloscDanych)
{
    typedef std::chrono::high_resolution_clock high_resolution_clock;
    typedef std::chrono::nanoseconds nanoseconds;
    high_resolution_clock::time_point start, koniec;
    nanoseconds czasTrwaniaObliczen;
    start=high_resolution_clock::now();
    switch(wyborPojemnika)
    {
    case WCZYTYWANIE:
       uruchomKolejka(iloscDanych);
       break;
    case WYSZUKIWANIE:
         uruchomStos(iloscDanych);
        break;
    default:
        cerr<<"Nie istnieje taka funkcja do sprawdzenia"<<endl;
        break;
    }
    koniec=high_resolution_clock::now();
    czasTrwaniaObliczen=std::chrono::duration_cast<nanoseconds>(koniec - start);
    return czasTrwaniaObliczen.count();
}

void wykonajEksperyment::Wczytytwanie(unsigned int iloscDanych)
{
    ifstream StrmWe;
    StrmWe.open("baza_danych.txt")
    string slowo;
        Tablica_Haszujaca<string, int> slownik();
    for(unsigned int i=0; i<iloscDanych;i++)
    {
        StrnWe>>slowo;
        slownik.dodaj(slowo,i);
    }

    StrmWe.close();
}

//void wykonajEksperyment::Wyszukiwanie(unsigned int iloscDanych)
//{
//
//    for(unsigned int i=0; i<iloscDanych;i++)
//    {
//        biurko.PUSH(i);
//    }
//        for(unsigned int j=0; j<iloscDanych;j++)
//    {
//        biurko.POP();
//    }
//
//}

template<class TYP>
TYP potega(TYP liczba, unsigned int wykladnik)
 {
    TYP wynik=1;
    for(unsigned int i=0; i<wykladnik;i++)
    {
        wynik*=liczba;
    }
    return wynik;
 }

//
//void wykonajEksperyment::wygenerujDaneTestowe()
//{
//
//    ofstream streamDane, streamSprawdzenie;
//
//    streamDane.open("dane");
//    streamSprawdzenie.open("sprawdzenie");
//
//    streamDane<<ILOSCDANYCH<<endl;
//    for(int i=POCZATEK_NUMERACJI;i<POCZATEK_NUMERACJI+ILOSCDANYCH;i++)
//    {
//        streamDane<<i<<endl;
//    }
//
//    streamSprawdzenie<<ILOSCDANYCH<<endl;
//    for(int i=POCZATEK_NUMERACJI;i<POCZATEK_NUMERACJI+ILOSCDANYCH;i++)
//    {
//        streamSprawdzenie<<i*2<<endl;
//    }
//
//    streamDane.close();
//    streamSprawdzenie.close();
//
//}
