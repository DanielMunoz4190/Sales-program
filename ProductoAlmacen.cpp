#include <iostream>
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
#include "Almacen.h"
#include <cmath>
#include <sstream>
using namespace std;

int ProductoAlmacen::getExistencia()
{       
    return this->existencia;
}
string ProductoAlmacen::getId()
{       
    return this->id;
}
string ProductoAlmacen::getNombre()
{       
    return this->nombre;
}
double ProductoAlmacen::getPrecio()
{
    return this->precio;
}
void ProductoAlmacen::setId(string id)
{
    this->id=id;
}
void ProductoAlmacen::setNombre(string nombre)
{
    this->nombre=nombre;
}
void ProductoAlmacen::setPrecio(double precio)
{
    this->precio=precio;
}
void ProductoAlmacen::setExistencia(int existencia)
{
    this->existencia=existencia;
}
ProductoAlmacen::ProductoAlmacen(string id, string nombre, double precio, int existencia)
{
    this->id=id;
    this->nombre=nombre;
    this->precio=precio;
    this->existencia=existencia;
}
ProductoAlmacen::ProductoAlmacen()
{
    this->id="";
    this->nombre="";
    this->precio=0.00;
    this->existencia=0;
}