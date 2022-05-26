#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include "Almacen.h"
#include "Carrito.h"
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
#include <sstream>
using namespace std;

Carrito::Carrito(string nombre,int size)
{
    this->cliente=nombre;
    this->size=size;
}
void Carrito :: agregarProducto(string id,int cantidad)
{
    Almacen almacen; 
    double precio=almacen.consultarPrecio(id, cantidad);
    string nombre=almacen.consultarNombre(id, cantidad);
    productos[this->size].setId(id);
    productos[this->size].setNombre(nombre);
    productos[this->size].setPrecio(precio);
    productos[this->size].setCantidad(cantidad);
    this->size=size+1;
}
void Carrito::verCarrito()
{
    int i=0;
    double total=0.00;
    cout<<"Carrito de compras de: "<<this->cliente<<endl;
    cout<<"ID,nombre,precio,cantidad"<<endl;
    for (i=0;i<10;i++)
    {
        if (productos[i].getPrecio()!=0.00)
        {
            cout<<productos[i].getId()<<","<<productos[i].getNombre()<<","<<productos[i].getPrecio()<<","<<productos[i].getCantidad()<<endl;
            total=total+productos[i].subtotal();  
        }        
    }
    cout<<"Tu total es de: "<<total<<endl;
}
void Carrito::editarCarrito(string id,int nuevaCantidad)
{
    int i;
    for (i=0;i<10;i++)
    {
        if (productos[i].getId()==id)
        {  
            productos[i].setCantidad(nuevaCantidad);
        }        
    }
}
int Carrito::getCantidad(string id)
{
    int i;
    for (i=0;i<size;i++)
    {
        if (productos[i].getId()==id)
        {
            return productos[i].getCantidad();
        }

    }
    return 0;
}
void Carrito::eliminarProducto(string id)
{
    int i;
    for (i=0;i<size;i++)
    {
        if (productos[i].getId()==id)
        {
            productos[i].setCantidad(productos[size-1].getCantidad());
            productos[i].setNombre(productos[size-1].getNombre());
            productos[i].setId(productos[size-1].getId());
            productos[i].setPrecio(productos[size-1].getPrecio());
            productos[size-1].setCantidad(0);
            productos[size-1].setPrecio(0.00);
            productos[size-1].setNombre("");
            productos[size-1].setId("");
            this->size=size-1;
        }

    }
}
void Carrito::pagar()
{
    int i;
    double total=0;
    int confirmacion=0;
    for (i=0;i<size;i++)
    {
        total=total+productos[i].subtotal();           
    }
    cout<<"Su total es: "<<total<<endl;  
    for (i=0;i<size;i++)
    {
        productos[i].eliminarProducto();
    } 
    size=0;
    
}
string Carrito::getId(int i)
{
    return productos[i].getId();
}