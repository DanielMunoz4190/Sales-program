#ifndef PRODUCTOCARRITO
#define PRODUCTOCARRITO
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class ProductoCarrito{
  private:
     string id;
     string nombre;
     double precio;
     int cantidad;
     
  
  public:
    ProductoCarrito();
    void definirProducto(string id, string nombre, double precio, int cantidad);
    double subtotal();
    double getPrecio();
    int getCantidad();
    string getNombre();
    string getId();
    void setId(string id);
    void setNombre(string nombre);
    void setPrecio(double precio);
    void setCantidad(int cantidad);
    void eliminarProducto();
};

#endif