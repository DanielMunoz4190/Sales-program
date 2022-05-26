#ifndef ALMACEN
#define ALMACEN
#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include "ProductoAlmacen.h"
using namespace std;



class Almacen{
  private:
    ProductoAlmacen productos[20];
    int size;
  public:
    Almacen();
    void verProductos();
    void establecerProductos();
    int getExistencia(string id);
    double consultarPrecio(string id, int cantidad);
    string consultarNombre(string id,int cantidad );
    void modificarExistencia(string id, int cantidad);
    void regresarArticulos(string id,int cantidad);   
};




#endif