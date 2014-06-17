#include "../include/Simpleks.h"
#include<iostream>
using namespace std;
Simpleks::Simpleks()
{

}

Simpleks::~Simpleks()
{
  //dtor
}
void Simpleks::Oblicz(void)
{
  while(czy_jest_dodatnie_c())
  {
    e=indeks_dodatniego_c();
    for(int j=0; j<ROZMIAR_M;j++)
    {
      int i=B[j];
      if(A[i][e]>0)
      {
        delta[i]=wyrazy_wolne[i]/A[i][e];
      }
    }
    l=B[0];
    for(int j=0; j<ROZMIAR_M;j++)
    {
      int i=B[j];
      if(delta[i]<delta[l])
      {
        l=i;
      }
    }

 Pivot(*this);
  }
  for(int i=0; i<ROZMIAR_M+ROZMIAR_N; i++)
  {
    for(int j=0;j<ROZMIAR_M;j++)
    {
      if(i==B[j])
        wyniki[i]=wyrazy_wolne[i];
      else
        wyniki[i]=0;
    }
  }
  for(int i=0; i<ROZMIAR_M+ROZMIAR_N; i++)
  {
    cout<<wyniki[i]<<endl;
  }
}

void Simpleks::Pivot(Simpleks stary)
{
  wyrazy_wolne[e]=stary.wyrazy_wolne[l]/stary.A[l][e];
  for(int i=0;i<ROZMIAR_N;i++)
  {
    int j=stary.N[i];
    if(j!=e)
      {
        A[e][j]=stary.A[l][j]/stary.A[l][e];
      }
  }
  A[e][l]=1/stary.A[l][e];
  for(int g=0; g<ROZMIAR_M;g++)
  {
    int i=stary.B[g];
    if(i!=l)
    {
      wyrazy_wolne[i]=stary.wyrazy_wolne[i]-stary.A[i][e]*wyrazy_wolne[e];
      for(int h=0; h<ROZMIAR_N;h++)
      {
        int j=stary.N[h];
        if(j!=e)
        {
          A[i][j]=stary.A[i][j]-stary.A[i][e]*A[e][j];
        }
      }
      A[i][l]=-1*stary.A[i][e]*A[e][l];

    }
  }
  v=stary.v + stary.c[e]*wyrazy_wolne[e];
  for(int i=0;i<ROZMIAR_N;i++)
  {
    int j=stary.N[i];
    if(j!=e)
    {
      c[j]=stary.c[j]-stary.c[e]*A[e][j];
    }
  }
  c[l]=-1*stary.c[e]*A[e][l];
  for(int i=0; i<ROZMIAR_N; i++)
  {
    if(N[i]==e)
      N[i]=l;
  }

  for(int i=0; i<ROZMIAR_M; i++)
  {
   if(B[i]==l)
     B[i]=e;
  }
}


int Simpleks::indeks_dodatniego_c()
{
  for(int i=0; i<ROZMIAR_N; i++)
  {//cout<<i<<"  "<<endl;
    int j=N[i];
  //  cout<<i<<"  "<<j<<"   "<<c[j]<<endl;
    if(c[j]>=0)
      return N[i];
  }
  return ROZMIAR_M+ROZMIAR_N+100;
}

bool Simpleks::czy_jest_dodatnie_c()
{
  for(int i=0; i<ROZMIAR_N; i++)
  {     int j=N[i];
    cout<<i<<"  "<<j<<"  "<<c[j]<<endl;
    if(c[j] > 0)
    {
    return true;
    }
  }
  return false;
}
