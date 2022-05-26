#ifndef PRODUCTOALMACEN
#define PRODUCTOALMACEN
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class ProductoAlmacen{
  private:
     string id;
     string nombre;
     double precio;
     int existencia;
  
  public:
    ProductoAlmacen();
    ProductoAlmacen(string id, string nombre, double precio, int existencia);
    double getPrecio();
    int getExistencia();
    string getNombre();
    string getId();
    void setId(string id);
    void setNombre(string nombre);
    void setPrecio(double precio);
    void setExistencia(int existencia);    
};

#endif