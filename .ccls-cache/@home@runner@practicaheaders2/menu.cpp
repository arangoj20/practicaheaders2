#include "menu.h"
#include "sistema.h"
void menu::menu_cliente(lista l,lista car){
  cliente cl;
  while(true){
    int opcion;
    cout<<""<<endl;
    cout<<"Ingresa lo que deseas hacer"<<endl;
    cout<<"1. Ver lista de productos"<<endl;
    cout<<"2. Comprar productos"<<endl;
    cout<<"3. Ver carro"<<endl;
    cout<<"4. Pagar"<<endl;
    cout<<"5. Salir"<<endl;
    cin>>opcion;
    if(opcion==1){
      cl.ver_lista(l);
    }else{
      if(opcion==2){
        int cod;
        cout<<""<<endl;
        cout<<"Ingrese el codigo del producto"<<endl;
        cin>>cod;
        car=cl.agregar_carro(cod, l, car);
      }else{
        if(opcion==3){
          cl.ver_carro(car);
        }else{
          if(opcion==4){
            cl.pagar(car);
          }else{
            if(opcion==5){
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
  }
}

void menu::menu_coordinador(lista l){
  coordinador c;
  while(true){
    int opcion;
    cout<<""<<endl;
    cout<<"Ingresa lo que deseas hacer"<<endl;
    cout<<"1. Ver inventario"<<endl;
    cout<<"2. Agregar producto"<<endl;
    cout<<"3. Modificar producto"<<endl;
    cout<<"4. Eliminar producto"<<endl;
    cout<<"5. Salir"<<endl;
    cin>>opcion;

    if(opcion==1){
      c.ver_lista(l);
    }else{
      if(opcion==2){
        articulo a;
        int cod;
        string nom;
        int pre;
        int t;
        cout<<""<<endl;
        cout<<"Ingresa el codigo"<<endl;
        cin>>cod;
        cout<<"Ingresa el nombre"<<endl;
        cin>>nom;
        cout<<"Ingresa el precio"<<endl;
        cin>>pre;
        while(true){
          cout<<""<<endl;
          cout<<"Ingresa el tipo"<<endl;
          cout<<"1. tecnologico"<<endl;
          cout<<"2. deportivo"<<endl;
          cout<<"3. extranjero"<<endl;
          cin>>t;
          if(t==1){
            break;
          }else{
            if(t==2){
              break;
            }else{
              if(t==3){
                break;
              }else{
                cout<<"Opcion incorrecta"<<endl;
                cout<<"------------------------------------------"<<endl;
                cout<<""<<endl;
              }
            }
          }
        }
        a=c.crear_producto(cod, nom, pre,t);
        l=c.añadir(l,a);
      }else{
        if(opcion==3){
          while(true){
            cout<<""<<endl;
            cout<<"Ingresa lo que deseas hacer"<<endl;
            cout<<"1. Modificar precio"<<endl;
            cout<<"2. Modificar nombre"<<endl;
            cout<<"3. Salir"<<endl;
            cin>>opcion;
            if(opcion==1){
              int cod;
              int pre;
              cout<<""<<endl;
              cout<<"Ingresa el codigo del producto"<<endl;
              cin>>cod;
              cout<<"Ingresa el nuevo precio"<<endl;
              cin>>pre;
              l=c.modificar_precio(l, cod, pre);
              break;
            }else{
              if(opcion==2){
                int cod;
                string nom;
                cout<<""<<endl;
                cout<<"Ingresa el codigo del producto"<<endl;
                cin>>cod;
                cout<<"Ingresa el nuevo nombre"<<endl;
                cin>>nom;
                l=c.modificar_nombre(l, cod, nom);
                break;
              }else
                if(opcion==3){
                  abort();
                }else{
                  cout<<"Opcion incorrecta"<<endl;
                  cout<<"------------------------------------------"<<endl;
                  cout<<""<<endl;
                }
              }
            }
        }else{
          if(opcion==4){
            int cod;
            cout<<""<<endl;
            cout<<"Ingresa el codigo del producto"<<endl;
            cin>>cod;
            c.eliminar(l, cod);
          }else{
            if(opcion==5){
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
  }
}