#ifndef CARRITO
#define CARRITO
#include <iostream>
#include <math.h>
#include <string>
#include "Almacen.h"
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
using namespace std;

class Carrito{
  private:
    string cliente;
    ProductoCarrito productos[10];
    int size;
  public:
    Carrito(string cliente,int size);
    void agregarProducto(string id,int cantidad);
    int getCantidad(string id);
    string getId(int i);
    double total();
    void verCarrito();
    void editarCarrito(string id,int nuevaCantidad);
    void eliminarProducto(string id);
    void pagar();
    
};
#endif