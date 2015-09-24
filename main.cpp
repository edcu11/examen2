#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Gato.h"
#include "Evaluador.h"
#include "NodoTrinario.h"

using namespace std;


//Escribe los datos del objeto gato (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios gatos en un solo archivo
int BYTE_SIZE=25;
void escribir(string nombre_archivo, Gato*gato, int posicion)
{
    ofstream out(nombre_archivo.c_str(), ios::in);
    out.seekp((posicion) * BYTE_SIZE);
    //edad, nombre
    out.write((char*)&gato->edad, 4);
    out.write((char*)&gato->sexo,1);
    out.write(gato->nombre.c_str(), 10);
    out.write(gato->raza.c_str(), 10);
    out.close();
}

//Devuelve un gato previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios gatos de un solo archivo
Gato* leer(string nombre_archivo, int posicion)
{
    Gato *g = new Gato(0,' ',"","");

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion * BYTE_SIZE);
    int eda;
    char sex;
    char nomb[10], raz[10];

    in.read((char*)&eda, 4);
    in.read(&sex, 1);
    in.read(nomb, 10);
    in.read(raz, 10);

    g->edad = eda;
    g->sexo = sex;
    g->nombre = nomb;
    g->raza = raz;


    return g;
}

//Devuelve el promedio de la edad de todos los gatos guardados en el archivo con nombre dado
double getPromedioDeEdad(string nombre_archivo)
{
   int cont=0, temp;
   double sumaT = 0;
   ifstream in(nombre_archivo.c_str());
   in.seekg(0, ios::end);
   int tamano = in.tellg()/25;
   for(int i = 0; i<tamano; i++)
   {
       in.seekg(i*25, ios::beg);
       in.read((char*)&temp, 4);
       sumaT+=temp;
       cont++;
   }
   return sumaT/cont;

    return -1;
}

//Devuelve el numero mayor almacenado en mi_set (dado)
int getMayor(set<int> mi_set)
{
    return *mi_set.rbegin();
}

//Mezcla el contenido de a y b (dados) y lo devuelve en un set ordenado alfabeticamente
set<char> mezclarAlfabeticamente(queue<char> a, stack<char> b)
{
    set<char> resultado;
   while(!a.empty())
   {
       resultado.insert(a.front());
       a.pop();
   }
   while(!b.empty())
   {
       resultado.insert(b.top());
       b.pop();
   }
    return resultado;
}

//Devuelve true si buscada (dada) existe en mi_mapa (dado), de lo contrario devuelve false
//Se debe de buscar en las llaves y en los valores almacenados en cada vector del mapa
bool existe(map<string,vector<string> >mi_mapa, string buscada)
{
//    for(map<string,vector<string> >::iterator i = mi_mapa.begin();
//       i!=mi_mapa.end();
//       i++)
//    {
//        if(*i==buscada)
//            return true;
//    }

    return false;
}

//Devuelve el valor mayor almacenado en el arbol con raiz dada
int getMayor(NodoTrinario* raiz)
{
    int num=0;
   if(raiz != NULL)
       num=raiz->valor;

   if(raiz->derecho != NULL){
       int temporal_der = getMayor(raiz->derecho);
       if(num<temporal_der)
           num=temporal_der;
   }

   if(raiz->izquierdo != NULL){
       int temporal_izquierdo = getMayor(raiz->izquierdo);
       if(num<temporal_izquierdo)
           num=temporal_izquierdo;

   }

   if(raiz->medio != NULL){
       int temporal_medio = getMayor(raiz->medio);
       if(num<temporal_medio)
           num=temporal_medio;
   }

   return num;

}

//Busca y reemplaza dado los valores buscado y reemplazo en el arbol con raiz dada
void buscarYReemplazar(NodoTrinario* raiz,int buscado, int reemplazo)
{

   if(raiz != NULL)
       if(raiz->valor==buscado)
           raiz->valor=reemplazo;

   if(raiz->derecho != NULL){
       buscarYReemplazar(raiz->derecho, buscado, reemplazo);
       if(buscado==raiz->derecho->valor)
           raiz->derecho->valor=reemplazo;
   }

   if(raiz->izquierdo != NULL){
        buscarYReemplazar(raiz->izquierdo, buscado, reemplazo);
       if(buscado==raiz->izquierdo->valor)
           raiz->izquierdo->valor=reemplazo;

   }

   if(raiz->medio != NULL){
       buscarYReemplazar(raiz->medio, buscado, reemplazo);
       if(buscado==raiz->medio->valor)
           raiz->medio->valor=reemplazo;
   }
}

char retener3Bits(char byte)
{
    return 0;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

