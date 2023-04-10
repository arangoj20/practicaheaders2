#include "cliente.h"

lista cliente::agregar_carro(int cod, lista inven, lista carro){
  nodo*temporal=inven.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    articulo a;
    a.codigo=temporal->value.codigo;
    a.nombre=temporal->value.nombre;
    a.precio=temporal->value.precio;
    temporal=inven.cabeza;
    while(temporal->siguiente!=NULL){
      temporal=temporal->siguiente;
    }
    if(carro.cabeza==NULL){
      carro.cabeza=new nodo;
      carro.cabeza->value=a;
    }else{
      temporal=carro.cabeza;
      while(temporal->siguiente!=NULL){
        temporal=temporal->siguiente;
      }
      temporal->siguiente=new nodo;
      temporal->siguiente->value=a;
    }
  }
  cout<<"Producto agregado"<<endl;
  cout<<""<<endl;
  return carro;
}

void cliente::pagar(lista carro){
  cliente c;
  nodo*temporal=carro.cabeza;
  int total=0;
  bool d;

  if(temporal->siguiente==NULL){
    total=total+temporal->value.precio;
    cout<<"Nombre: "<<temporal->value.nombre<<endl;
    cout<<"Precio: "<<temporal->value.precio<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"Total sin descuento:"<<endl;
    cout<<total<<endl;
  }else{
    while(temporal->siguiente!=NULL){
    total=total+temporal->value.precio;
    cout<<"Nombre: "<<temporal->value.nombre<<endl;
    cout<<"Precio: "<<temporal->value.precio<<endl;
    cout<<"------------------------------------------"<<endl;
    temporal=temporal->siguiente; 
    }
    if(temporal->siguiente==NULL){
      total=total+temporal->value.precio;
      cout<<"Nombre: "<<temporal->value.nombre<<endl;
      cout<<"Precio: "<<temporal->value.precio<<endl;
      cout<<"------------------------------------------"<<endl;
      cout<<""<<endl;
      cout<<"Total sin descuento:"<<endl;
      cout<<total<<endl;
    }
  }
  d=c.calcular_descuento(carro);
  if(d==true){
    total=total-(total*0.1);
    cout<<"Total con descuento:"<<endl;
    cout<<total<<endl;
  }else{
    if(d==false){
      cout<<"No hay descuentos por aplicar"<<endl;
    }
  }
}

bool cliente::calcular_descuento(lista carro){
  nodo*temporal=carro.cabeza;
  int tipot1=carro.cabeza->value.tipo;
  while(temporal->siguiente!=NULL){
    int tipot2=temporal->value.tipo;
    if(tipot1==tipot2){
      return true;
      break;
    }else{
      tipot1=temporal->value.tipo;
      temporal=temporal->siguiente;
    }
    if(temporal->siguiente==NULL){
      return false;
      break;
    }
  }
  return false;
}

lista cliente::ver_lista(lista l){
  if (l.cabeza==NULL){
    cout<<"No hay productos"<<endl;
    return l;
  }else{
    nodo*temporal=l.cabeza;
    while(temporal!=NULL){
      cout<<"Codigo: "<<temporal->value.codigo<<endl;
      cout<<"Nombre: "<<temporal->value.nombre<<endl;
      cout<<"Precio: "<<temporal->value.precio<<endl;
      cout<<"------------------------------------------"<<endl;
      temporal=temporal->siguiente;
    }
    return l;
  }
}

lista cliente::ver_carro(lista l){
  if (l.cabeza==NULL){
    cout<<"No hay productos"<<endl;
    return l;
  }else{
    nodo*temporal=l.cabeza;
    while(temporal!=NULL){
      cout<<"Codigo: "<<temporal->value.codigo<<endl;
      cout<<"Nombre: "<<temporal->value.nombre<<endl;
      cout<<"Precio: "<<temporal->value.precio<<endl;
      cout<<"------------------------------------------"<<endl;
      temporal=temporal->siguiente;
    }
    return l;
  }
}