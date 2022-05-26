#include <iostream>
#include "Almacen.h"
#include "Carrito.h"
#include "ProductoAlmacen.h"
#include "ProductoCarrito.h"
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

int main() 
{
    Almacen almacen1;
    int tamanoCarrito=0;
    string cliente;
    cout<<"Ingresa el nombre del cliente"<<endl;
    cin>>cliente;
    cout<<endl;
    Carrito carrito1(cliente,tamanoCarrito);
    int opcion;    
    while (opcion!=6)
    {
    cout<<"1)Ver productos"<<endl;
    cout<<"2)Comprar"<<endl;
    cout<<"3)Ver carrito"<<endl;
    cout<<"4)Editar"<<endl;
    cout<<"5)Pagar"<<endl;
    cout<<"6)Salir"<<endl;
    cout<<"Seleccione una opcion: "<<endl;
    cin>>opcion;
        if (opcion==1)
        {
            almacen1.verProductos();
            cout<<endl;  
                   
        }
        if (opcion==2)
        {
            string id;
            int cantidad;
            int confirmacion=2;
            while (confirmacion==2)
            {
            cout<<"Escribe Id"<<endl;
            cin>>id;
            cout<<"Escribe la cantidad"<<endl;
            cin>>cantidad;
            cout<<"El id del producto que deseas es: "<<id<<endl<<"La cantidad que ingresaste es: "<<cantidad<<endl;
            cout<<"Lo que ingresaste es corecto? 1)Si,2)No"<<endl;
            cin>>confirmacion;
            if (confirmacion==1)
            {
                if (almacen1.getExistencia(id)>=cantidad)
                {
                    tamanoCarrito=tamanoCarrito+1;
                    carrito1.agregarProducto(id,cantidad);
                    cout<<"El producto se ha agregado con exito."<<endl;
                    cout<<endl;
                    break;
                } 
                else 
                {
                    cout<<"No hay existencia"<<endl;
                    cout<<endl;
                    break;
                }
            }
            else
            {
            confirmacion==2;
            }
            }    
        }
        if (opcion==3)
        {
            
            carrito1.verCarrito();
            cout<<endl;
        }
        if (opcion==4)
        {
            int decision;
            int nuevaCantidad;
            int cantidadRegresar;
            string id;
            cout<<"Quiere eliminar el producto del carrito o quiere modificar la cantidad? 1)Eliminar 2)Modificar"<<endl;
            cin>>decision;
            cout<<"Que producto desea eliminar? ingrese el ID"<<endl;
            cin>>id;
            if (decision==1)
            {
                
                carrito1.eliminarProducto(id); 
                cout<<"Se ha eliminado el producto "<<id<<" con exito"<<endl; 
                cout<<endl;    
            }
            if (decision==2)
            {
                cantidadRegresar=carrito1.getCantidad(id);
                
                cout<<"Ingrese la nueva cantidad de productos"<<endl;
                cin>>nuevaCantidad;
                if (almacen1.getExistencia(id)>=nuevaCantidad)
                {
                    carrito1.editarCarrito(id,nuevaCantidad);
                }
                cout<<endl;                
            }            
        } 
        if (opcion==5)
        {
            int i;
            string id;
            int cantidad=0;
            for (i=0;i<tamanoCarrito;i++)
            {
                id=carrito1.getId(i);
                cantidad=carrito1.getCantidad(id);
                almacen1.modificarExistencia(id,cantidad);
            } 
            carrito1.pagar();
            cout<<"Gracias por su compra "<<endl;
            cout<<endl;       

        }  
        if (opcion!=1 || opcion!=2 || opcion!=3 || opcion!=4 || opcion!=5 || opcion!=6 )
        {
            cout<<"Opcion incorrecta "<<endl;
        }         
    }
    cout<<"Compra finalizada";
}