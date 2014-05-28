#ifndef GRAF_H
#define GRAF_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;

struct Wierzcholek
{
    typedef pair<int,Wierzcholek*> ve;
    vector<ve> lista_przylegania_; //koszt krawędzi, docelowy wierzcholek
    string nazwa_;
    bool czy_bylem_;
    Wierzcholek(string nazwa_wierzcholka)
    {
        nazwa_=nazwa_wierzcholka;
    }
};

class Graf
{
    public:
    typedef map<string, Wierzcholek *> WierzcholkiMap;  //klucz, wskaznik na wierzcholek
    WierzcholkiMap lista_wierzcholkow_;
    void DodajWierzcholek(const string&);
    void DodajKrawedz(const string& nazwa_do, const string& nazwa_z, int koszt=1);
    //Breadth First Serch
    void BFS(const string nazwa_start);
};


#endif // GRAF_H
