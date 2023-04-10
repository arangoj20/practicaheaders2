#pragma once
#include <iostream>
#include "usuario.h"
#include "inventario.h"
#include "carrito_compras.h"
using namespace std;

class cliente: public usuario{
public:
  lista agregar_carro(int cod, lista inv, lista carro);
  lista ver_lista(lista l);
  lista ver_carro(lista l);
  void pagar(lista carro);
  bool calcular_descuento(lista carro);
};