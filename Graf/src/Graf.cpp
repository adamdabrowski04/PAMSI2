#include "../include/Graf.h"

void Graf::DodajWierzcholek(const string &nazwa)
{
    WierzcholkiMap::iterator itr=lista_wierzcholkow_.begin();
    itr=lista_wierzcholkow_.find(nazwa);
    if(itr==lista_wierzcholkow_.end())
    {
        Wierzcholek *wskaz_wierzcholek= new Wierzcholek(nazwa);
        lista_wierzcholkow_[nazwa]=wskaz_wierzcholek;
                    return;
    }
    cout<<"\nWierzcholek juz istnieje!";
}

void Graf::DodajKrawedz(const string& nazwa_z, const string& nazwa_do, int koszt)
{
    Wierzcholek *wskaz_z=(lista_wierzcholkow_.find(nazwa_z)->second);
    Wierzcholek *wskaz_do=(lista_wierzcholkow_.find(nazwa_do)->second);
    pair<int,Wierzcholek *> krawedz = make_pair(koszt,wskaz_do);
    wskaz_z->lista_przylegania_.push_back(krawedz);
    pair<int,Wierzcholek *> krawedz2 = make_pair(koszt,wskaz_z);
    wskaz_do->lista_przylegania_.push_back(krawedz2);
}

void Graf::BFS(const string nazwa_start)
{
    WierzcholkiMap::iterator itr;
    for(itr=lista_wierzcholkow_.begin(); itr==lista_wierzcholkow_.end(); itr++)
    {
        itr->second->czy_bylem_=false;
    }
    itr=lista_wierzcholkow_.find(nazwa_start);
    map<string, int> odleglosci;
    odleglosci[itr->second->nazwa_]=0;
    queue<Wierzcholek*> do_przejscia;
    do_przejscia.push(itr->second);
    while(!do_przejscia.empty())
    {
        Wierzcholek * tu_stoje;
        tu_stoje=do_przejscia.front();
        do_przejscia.pop();
        for(vector<pair<int,Wierzcholek*> >::iterator iter=tu_stoje->lista_przylegania_.begin() ;iter!=tu_stoje->lista_przylegania_.end();iter++ )
        {
            if(iter->second->czy_bylem_==false)
            {
                odleglosci[iter->second->nazwa_]=iter->first+odleglosci[tu_stoje->nazwa_];
                do_przejscia.push(iter->second);
            }
        }
        tu_stoje->czy_bylem_=true;

    }

    for(map<string, int>::iterator iter=odleglosci.begin();iter!=odleglosci.end();iter++)
    cout<<"odleglosc od "<<nazwa_start<<" do "<<iter->first<<" to "<<iter->second<<endl;
}
