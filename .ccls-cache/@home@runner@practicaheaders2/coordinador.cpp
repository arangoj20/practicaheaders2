#include "coordinador.h"

articulo coordinador::crear_producto(int cod, string nom, int pre, int t){
  articulo art;
  if(t==1){
    articulo_deportivo artdep;
    artdep.codigo=cod;
    artdep.nombre=nom;
    artdep.precio=pre;
    artdep.tipo=t;
    art=artdep;
  }else{
    if(t==2){
      articulo_tecnologico arttec;
      arttec.codigo=cod;
      arttec.nombre=nom;
      arttec.precio=pre;
      arttec.tipo=t;
      art=arttec;
    }else{
      if(t==3){
        float imp;
        articulo_extranjero artex;
        artex.codigo=cod;
        artex.nombre=nom;
        imp=pre*artex.impuesto;
        artex.precio=pre+imp;
        artex.tipo=t;
        art=artex;
      }
    }
  }
  cout<<"Producto creado"<<endl;
  return art;
}

lista coordinador::añadir(lista l,articulo a){
  if(l.cabeza==NULL){
    l.cabeza=new nodo;
    l.cabeza->value=a;
    return l;
  }else{
    nodo*temporal=l.cabeza;
    while(temporal->siguiente!=NULL){
      temporal=temporal->siguiente;
    }
    temporal->siguiente=new nodo;
    temporal->siguiente->value=a;
    return l;
  }
}

lista coordinador::modificar_nombre(lista l, int cod,string nom){
  nodo*temporal=l.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    temporal->value.nombre=nom;
  }else{
    cout<<"Codigo incorrecto"<<endl;
  }
  cout<<"Nombre modificado"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<""<<endl;
  return l;
}

lista coordinador::modificar_precio(lista l, int cod,int pre){
  nodo*temporal=l.cabeza;
  while(temporal->value.codigo!=cod){
    temporal=temporal->siguiente;
  }
  if(temporal->value.codigo==cod){
    temporal->value.precio=pre;
  }else{
    cout<<"Codigo incorrecto"<<endl;
  }
  cout<<"Precio modificado"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<""<<endl;
  return l;
}

lista coordinador::eliminar(lista l, int cod){
  nodo*temporal=l.cabeza;
  while(temporal->siguiente->value.codigo!=cod){
    temporal=temporal->siguiente;
  }

  if(temporal->siguiente->value.codigo==cod){
    if(temporal->siguiente->siguiente!=NULL){
      temporal->siguiente=temporal->siguiente->siguiente;
    }else{
      if(temporal->siguiente->siguiente==NULL){
        temporal->siguiente=NULL;
      }
    }
  }
  cout<<"Producto eliminado"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<""<<endl;
  return l;
}

lista coordinador::ver_lista(lista l){
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