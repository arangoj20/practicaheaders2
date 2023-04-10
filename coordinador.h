#pragma once
#include <iostream>
#include "usuario.h"
#include "articulo_deportivo.h"
#include "articulo_tecnologico.h"
#include "articulo_extranjero.h"
#include "inventario.h"
using namespace std;

class coordinador: public usuario{
public:
  articulo crear_producto(int cod, string nom, int pre, int t);
  lista añadir(lista l,articulo a);
  lista modificar_nombre(lista l, int cod,string nom);
  lista modificar_precio(lista l, int cod,int pre);
  lista eliminar(lista l, int cod);
  lista ver_lista(lista l);
};