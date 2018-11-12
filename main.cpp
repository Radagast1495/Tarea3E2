using namespace std;
#include <iostream>
#include<cstdio>
#include "cache.h"

int main(int argc, char const *argv[]) {\

int t=stoi(argv[1],0,10);
int l=stoi(argv[2],0,10);
int a=stoi(argv[3],0,10);


 Cache* c=new Cache();
  c->calculos(t,l,a);
  c->leerInstrucciones();
  c->imprimir();


  delete c;
  cout<<"fin"<<endl;


  return 0;
}
