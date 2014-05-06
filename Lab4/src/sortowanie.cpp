#include "../include/dane.h"


void dane::bubbleSort()
{
    for(unsigned int i=0;i<liczbaDanych;i++)
    {
        for(unsigned int j=0;j<liczbaDanych-1;j++)
        {
        if(pTab[j]>pTab[j+1])
            this->zamienElementy(j,j+1);
        }
    }

}

void dane::quickSort(int p, int r)
{
    if(p<r)
    {
        int q=this->partition(p,r);
        this->quickSort(p, q-1);
        this->quickSort(q+1, r);
    }
}

int dane::partition(int p, int r)
{
    int x=pTab[r];
    int i =p-1;
    for(int j=p; j<r;j++)
    {
        if(pTab[j]<=x)
            {
                i=i+1;
                this->zamienElementy(static_cast<int>(i),static_cast<int>(j) );
            }
    }
    this->zamienElementy(static_cast<int>(i)+1,static_cast<int>(r));
    return i+1;
}

unsigned int dane::parent(unsigned int i)
{
    return i/2;
}

unsigned int dane::left(unsigned int i)
{
    return 2*i;
}

unsigned int dane::right(unsigned int i)
{
    return 2*i+1;
}

void dane::maxHeapify(unsigned int i)
{
    unsigned int l, r, largest;
    l=left(i);
    r=right(i);
    if(l<(liczbaDanych-1)&&pTab[l]>pTab[i])
        largest = l;
    else
        largest = i;
    if(r<(liczbaDanych-1)&&pTab[r]>pTab[largest])
        largest = r;
    if(largest!=i)
    {
        this->zamienElementy(i,largest);
        this->maxHeapify(largest);
    }
}

void dane::buildMaxHeap(void)
{
    for(int i=static_cast<int>( (liczbaDanych-1)/2);i>=0;i--)
        this->maxHeapify(static_cast<unsigned int>(i) );
}

void dane::heapSort(void)
{   unsigned int tmp=liczbaDanych;
    this->buildMaxHeap();
    for(unsigned int i=liczbaDanych-1;i>0;i--)
    {
        this->zamienElementy(0,i);
        liczbaDanych-=1;
        this->maxHeapify(0);
    }
    liczbaDanych=tmp;
}
