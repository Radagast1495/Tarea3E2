
#include <iostream>
#include <string>
#include <math.h>
#include<vector>
#include "cache.h"
#include "Dato.h"
using namespace std;
///@brief  Constructor
Cache::Cache(){

}

///@brief Destructor
Cache::~Cache(){


}
//@brief Esta clase de realizar los calculos para los tamanos de los bits de offset, index y tag y ademas inicializa valores
///recibe los valores de los parametros de la linea de comandos para realizar los calculos
void Cache::calculos(int t, int l, int a){
  this->cachesize=t;
  this->linesize=l;
  this->asociativity=a;
  this->overallmissrate=0.0;
  this->readmissrate=0.0;
  this->dirtyEvictions=0;
  this->loadmiss=0;
  this->storemiss=0;
  this->loadhit=0;
  this->storehit=0;
  this->totalmiss=0;
  this->totalhit=0;
  if(this->asociativity<=2){
    this->M=1;
  }
  else{
    this->M=2;
  }
  double temp;
  temp=((double)this->cachesize/(double)this->asociativity);
  temp=log2(temp);
  this->setbits=(int)temp;
  temp=log2((double)this->linesize);
  this->offsetsize=(int)temp;
  this->tagsize=32-(this->offsetsize+this->setbits);


}
///@brief: se encarga de realizar ya las funciones en si del cache y generar todos los datos_leidos
void Cache::leerInstrucciones(){

  int i;
  int dirtyBits=0;
  int j;
  int aso;
  int cachsize;
  int datos_leidos=0;
  bool hit=false;
  bool not_replaced=true;
  aso=this->asociativity;
  cachsize=this->cachesize;
  int set=this->setbits;
  int setbit=pow(2,set);
  vector<vector<Dato*>> cache(aso,vector<Dato*>(setbit));
  for( i=0;i<aso;i++){///Inicializa los valores del vector del cache
    for( j=0;j<(setbit);j++){
      Dato* datoleido=new Dato();
      datoleido->politica=3;
      datoleido->tag=0;
      datoleido->Dbit=0;
      cache[i][j]=datoleido;
    }
  }
  long long int mascara_set=0;
  long long int mascara_tag=0;
  ///Calculamos el valor de las mascaras a utilizar
  for(i=0;i<this->setbits;i++){
    mascara_set=mascara_set+pow(2,this->offsetsize+i);
  }

  for(i=0;i<this->tagsize;i++){
    mascara_tag=mascara_tag+pow(2,this->offsetsize+this->setbits+i);
  }

  string dato;
  string tipo_de_instruccion;
  long long int datoin;
  long long int index;
  long long int tag_temp;
  bool prueba=false;
  while(!cin.eof()){
///lee los datos y separa solo el valor de direccion en dato y el tipo de instruccion
    hit=false;
    not_replaced=true;
    cin>>dato;
    if(cin.eof()){
      break;
    }
    cin>>dato;
    tipo_de_instruccion=dato;
    if(cin.eof()){
      break;
    }
    cin>>dato;
    datos_leidos++;
    if(cin.eof()){
      break;
    }
    datoin=stoi(dato,0,16);
    ///Saca los valores de index y de tag del dato
    index=datoin&mascara_set;
    index=index>>this->offsetsize;
    tag_temp=datoin&mascara_tag;
    ///Revisa si hay algun hit
      for( j=0;(j<aso && !hit); j++){
        if(cache[j][index]->tag==tag_temp){
          hit=true;
          cache[j][index]->politica=0;
          if(tipo_de_instruccion=="1"){
            cache[j][index]->Dbit=1;
          }
        }
      }
      ///Si no encuentra hits revisa si algun tiene un 3 es su RRpv
      while(not_replaced&&!hit){
        for( j=0;(j<aso&& !hit); j++){
          if(cache[j][index]->politica==3){
            if(cache[j][index]->Dbit==1){
              dirtyBits++;
              cache[j][index]->Dbit=0;
            }
            cache[j][index]->tag=tag_temp;
            if(this->M==2){
            cache[j][index]->politica=2;
          }else{
            cache[j][index]->politica=0;
          }
            not_replaced=false;
            break;
          }
        }
        ///Si ninguno tenia 3 le suma 1 a todos y se devuelve
        for( j=0;(j<aso&& not_replaced); j++){
          if(cache[j][index]->politica<3){
              cache[j][index]->politica=cache[j][index]->politica+1;
            }
          }
        }
        ///Obtenemos los datos si hubo hit o miss
        if(hit==true){
          this->totalhit=this->totalhit+1;
          if(tipo_de_instruccion=="0"){
            this->loadhit=  this->loadhit+1;
          }
          else{
            this->storehit=this->storehit+1;
          }
        }
        else{
          this->totalmiss=this->totalmiss+1;
          if(tipo_de_instruccion=="0"){
            this->loadmiss=  this->loadmiss+1;
          }
          else{
            this->storemiss=this->storemiss+1;
          }

        }
        cin>>dato;

        if(cin.eof()){
          break;
        }
      }
      cout<<datos_leidos<<endl;
      this->overallmissrate=((double)this->totalmiss/(double)datos_leidos);
      this->readmissrate=((double)this->loadmiss/(double)this->totalmiss);
      this->dirtyEvictions=dirtyBits;


    }
//imprime todos los valores
void Cache::imprimir(){
  cout<<"Cache parameters:"<<endl;
  cout<<"Cache Size(kB):"<<this->cachesize<<endl;
  cout<<"Cache asociativity:"<<this->asociativity<<endl;
  cout<<"Cache block Size(bytes):"<<this->linesize<<endl;
  cout<<"Simulation Results"<<endl;
  cout<<"Overall miss rate:"<<this->overallmissrate<<endl;
  cout<<"readmissrate:"<<this->readmissrate<<endl;
  cout<<"dirtyEvictions:"<<this->dirtyEvictions<<endl;
  cout<<"Load misses:"<<this->loadmiss<<endl;
  cout<<"store misses:"<<this->storemiss<<endl;
  cout<<"Total misses:"<<this->totalmiss<<endl;
  cout<<"Load hit:"<<this->loadhit<<endl;
  cout<<"store hit:"<<this->storehit<<endl;
  cout<<"Total hit:"<<this->totalhit<<endl;

}
