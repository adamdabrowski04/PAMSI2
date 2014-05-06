#include "../include/wykonajEksperyment.h"

using namespace std;
wykonajEksperyment::wykonajEksperyment()
{
    //ctor
}

wykonajEksperyment::~wykonajEksperyment()
{
    //dtor
}

void wykonajEksperyment::test()
{

    for(int i=0; i<LICZBAPRZEBIEGOW;i++)
    {
  //liczydlo.TabWyliczona=liczydlo.TabDanych;

//    ofstream plik2;
//    string nazwa2="wejscie";
//    nazwa2+= to_string(i);
//    plik2.open(nazwa2);
//    plik2<<liczydlo.TabWyliczona;
//    plik2.close();

        czasyRealizacji[i]=liczydlo.wykonajObliczenia();

//    ofstream plik;
//    string nazwa="wynik";
//    nazwa+= to_string(i);
//    plik.open(nazwa);
//    plik<<liczydlo.TabWyliczona;
//    plik.close();

        sredniCzas+=static_cast<double>(czasyRealizacji[i]/LICZBAPRZEBIEGOW);
        liczbaBledow[i]=liczydlo.wykonajSprawdzenie();
        sumaBledow+=liczbaBledow[i];
       }


}




void wygenerujDaneTestowe(const int ILOSCDANYCH)
{

    ofstream streamDane, streamSprawdzenie;

    streamDane.open("dane");
    streamSprawdzenie.open("sprawdzenie");

    streamSprawdzenie<<ILOSCDANYCH<<endl;
    for(int i=POCZATEK_NUMERACJI;i<POCZATEK_NUMERACJI+ILOSCDANYCH;i++)
    {
        streamSprawdzenie<<i<<endl;
    }
    /*!
     *
     *Genereuję tablicę danych w której następnie poprestawiam
     *   liczby z użyciem generatora liczb pseudolosowyc
     *
     */
    int *pTab=new int[ILOSCDANYCH];
    for(int i=POCZATEK_NUMERACJI;i<POCZATEK_NUMERACJI+ILOSCDANYCH;i++)
    {
        pTab[i-POCZATEK_NUMERACJI]=i;
    }
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0,ILOSCDANYCH-1);

    for(int i=0;i<ILOSCDANYCH/2;i++)
    {
        int indeks1=distribution(generator);
        int indeks2=distribution(generator);
        int tmp;
        tmp=pTab[indeks1];
        pTab[indeks1]=pTab[indeks2];
        pTab[indeks2]=tmp;
    }

    streamDane<<ILOSCDANYCH<<endl;
    for(int i=0;i<ILOSCDANYCH;i++)
    {
        streamDane<<pTab[i]<<endl;
    }
    delete[](pTab);
    streamDane.close();
    streamSprawdzenie.close();

}
