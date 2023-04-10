#include "sistema.h"

void sistema::iniciar(){
  sistema s;
  inventario l;
  l.inv=s.productos_defecto();
   while(true){
    int opcion;
    cout<<""<<endl;
     cout<<"--------------------------------------"<<endl;
    cout<<"Ingresa que tipo de usuario es"<<endl;
    cout<<"1. Cliente"<<endl;
    cout<<"2. Coordinador"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>opcion;
     if(opcion==1){
       carrito_compras car;
       menu m;
       m.menu_cliente(l.inv,car.car);
       break;
     }else{
      if(opcion==2){
        menu m;
        m.menu_coordinador(l.inv);
        break;
      }else{
        if(opcion==3){
          abort();
        }else{
          cout<<"Opcion incorrecta"<<endl;
          cout<<"------------------------------------------"<<endl;
          cout<<""<<endl;
        }
      }
   }
}
}

lista sistema::productos_defecto(){
  coordinador c;
  lista l;
  articulo a;

  a=c.crear_producto(1000, "Samsung S20", 3000000, 1);
  l=c.añadir(l,a);
  a=c.crear_producto(1001, "Iphone X", 1800000, 1);
  l=c.añadir(l,a);
  a=c.crear_producto(1002, "Asus VivoBook", 2200000, 1);
  l=c.añadir(l,a);
  a=c.crear_producto(1003, "Balon futbol Adidas", 200000, 2);
  l=c.añadir(l,a);
  a=c.crear_producto(1004, "Balon Basquet", 120000, 2);
  l=c.añadir(l,a);
  a=c.crear_producto(1005, "Raqueta Tenis", 640000, 2);
  l=c.añadir(l,a);
  a=c.crear_producto(1006, "Raqueta Tenis", 640000, 2);
  l=c.añadir(l,a);
  a=c.crear_producto(1007, "Camiseta Barcelona", 510000, 3);
  l=c.añadir(l,a);
  a=c.crear_producto(1008, "Camiseta Boca Juniors", 330000, 3);
  l=c.añadir(l,a);
  a=c.crear_producto(1009, "Camiseta Real Madrid", 680000, 3);
  l=c.añadir(l,a);
  return l;
}