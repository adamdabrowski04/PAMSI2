#include "../include/wykonajEksperyment.h"

using namespace std;
wykonajEksperyment::wykonajEksperyment()
{
    pTabCzasyKolejnychSeriiDanych=new unsigned int[rozmiarTabIlosciDanych];
    pTabIloscDanych= new unsigned int[rozmiarTabIlosciDanych];
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
    case KOLEJKA:
       nazwaPliku="Kolejka_";
       break;
    case STOS:
         nazwaPliku="Stos_";
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
        oStrm<<pTabIloscDanych[i]<<"&"<<pTabCzasyKolejnychSeriiDanych[i]<<endl;
        cout.width(10);
        cout<<pTabIloscDanych[i]<<"  "<<pTabCzasyKolejnychSeriiDanych[i]<<endl;
    }
    oStrm.close();
}


unsigned int wykonajEksperyment::seriaPomiarow(unsigned int liczbaWywolan, unsigned int iloscDanych)
{
    unsigned int sredniCzas=0;
    for(unsigned int i=0; i<liczbaWywolan; i++)
    {
        sredniCzas+=this->zmierzCzasTrwania(iloscDanych);
    }
    sredniCzas=sredniCzas/liczbaWywolan;
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
    case KOLEJKA:
       uruchomKolejka(iloscDanych);
       break;
    case STOS:
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

void wykonajEksperyment::uruchomKolejka(unsigned int iloscDanych)
{

        kolejka<int> rurka;
    for(unsigned int i=0; i<iloscDanych;i++)
    {
        rurka.enqueue(i);
    }
        for(unsigned int j=0; j<iloscDanych;j++)
    {
        rurka.dequeue();
    }

}

void wykonajEksperyment::uruchomStos(unsigned int iloscDanych)
{
    stos<int> biurko;  //obiekt zawierajacy dane i przeprowadzajacy test
    for(unsigned int i=0; i<iloscDanych;i++)
    {
        biurko.PUSH(i);
    }
        for(unsigned int j=0; j<iloscDanych;j++)
    {
        biurko.POP();
    }

}

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
