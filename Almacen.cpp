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
   
Almacen::Almacen()
{
    ifstream lector("Productos.txt");
    string linea;
    string campo;
    int cont=0; 
    int i=0;
    int index=0;
    while (!lector.eof())
    {
        getline(lector,linea);
        i=i+1;
        stringstream ss(linea);
        cont=0;        
        while(getline(ss,campo,','))
        {   
           
           if (cont==0)
           {
               string id="";
               id=campo;
               productos[index].setId(id);  
           }
           if (cont==1)
           {
               string nombre="";
               nombre=campo;
               productos[index].setNombre(nombre);
           }
           if (cont==2)
           
           {
               double precio=0.00;
               precio=stod(campo);
               productos[index].setPrecio(precio);            
           }
           if (cont==3)
           {
               int existencia=0;
               existencia=stoi(campo);
               productos[index].setExistencia(existencia);                            
           }
           cont=cont+1;
           
        }
        index=index+1;
    }
    lector.close(); 
    this->size=index;
}
int Almacen::getExistencia(string id)
{
    int i;
    for (i=0;i<20;i++)
    {
        if (productos[i].getId()==id)
        {
            return productos[i].getExistencia();
        }

    }
    return 0;
}

double Almacen::consultarPrecio(string id, int cantidad)
{
    int i=0;
     for (i=0;i<20;i++)
    {
        if(productos[i].getId()==id)
        {
            return productos[i].getPrecio();
        }
    }
    return 0;
}
string Almacen::consultarNombre(string id, int cantidad)
{
    int i=0;
     for (i=0;i<20;i++)
    {
        if(productos[i].getId()==id)
        {
            return productos[i].getNombre();
        }
    }
    return "No esta registrado";
}
void Almacen::modificarExistencia(string id,int cantidad)
{
    int i=0;
     for (i=0;i<20;i++)
    {
        if(productos[i].getId()==id)
        {
            int existenciaAnterior=productos[i].getExistencia();
            productos[i].setExistencia(existenciaAnterior-cantidad);
        }
    }
}
void Almacen::regresarArticulos(string id,int cantidad)
{
    int i=0;
     for (i=0;i<20;i++)
    {
        if(productos[i].getId()==id)
        {
            int existenciaAnterior=productos[i].getExistencia();
            productos[i].setExistencia(existenciaAnterior+cantidad);
        }
    }
}
void Almacen :: verProductos()
{
    int i;
    cout<<"ID,nombre,precio,existencia"<<endl;
    for (i=0;i<size;i++)
    {
        cout<<productos[i].getId()<<","<<productos[i].getNombre()<<","<<productos[i].getPrecio()<<","<<productos[i].getExistencia()<<endl;
    }
}   