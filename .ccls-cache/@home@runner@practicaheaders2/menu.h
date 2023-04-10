#pragma once
#include <iostream>
#include "coordinador.h"
#include "cliente.h"
using namespace std;
class menu{
public:
  usuario tipo_usuario;
  void menu_cliente(lista i,lista carro);
  void menu_coordinador(lista i);
};