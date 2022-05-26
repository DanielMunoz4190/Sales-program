#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
#include "Almacen.h"
#include "Carrito.h"
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
using namespace std;


void ProductoCarrito::definirProducto(string id, string nombre, double precio, int cantidad)
{
    this->id=id;
    this->nombre=id;
    this->precio=precio;
    this->cantidad=cantidad;
}
int ProductoCarrito::getCantidad()
{       
    return this->cantidad;
}
string ProductoCarrito::getId()
{       
    return this->id;
}
string ProductoCarrito::getNombre()
{       
    return this->nombre;
}
double ProductoCarrito::getPrecio()
{
    return this->precio;
}
double ProductoCarrito::subtotal()
{
    double subtotal;
    subtotal=this->cantidad*this->precio;
    return subtotal;

}
void ProductoCarrito::setId(string id)
{
    this->id=id;
}
void ProductoCarrito::setNombre(string nombre)
{
    this->nombre=nombre;
}
void ProductoCarrito::setPrecio(double precio)
{
    this->precio=precio;
}
void ProductoCarrito::setCantidad(int cantidad)
{
    this->cantidad=cantidad;
}
ProductoCarrito::ProductoCarrito()
{
    this->precio=0.00;
    this->cantidad=0;
    this->id="";
    this->nombre="";
}
void ProductoCarrito::eliminarProducto()
{
    this->precio=0.00;
    this->id="";
    this->cantidad=0;
    this->nombre="";
    
}