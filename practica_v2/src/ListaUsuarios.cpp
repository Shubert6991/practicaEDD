#include "ListaUsuarios.h"

ListaUsuarios::ListaUsuarios(){
  inicio = fin = NULL;
}

void ListaUsuarios::insertarAlInicio(Usuario u){
  NodoUsuario* nuevo = new NodoUsuario(u);
  if(estaVacia()){
    inicio = fin = nuevo;

  }else {
     nuevo -> setSiguiente(inicio);
     inicio -> setAnterior(nuevo);
     inicio = nuevo;
   }
}

void ListaUsuarios::insertarAlFinal(Usuario u){
  NodoUsuario* nuevo = new NodoUsuario(u);
  if(estaVacia()){
    inicio = fin = nuevo;

  }else {
     nuevo -> setAnterior(fin);
     fin -> setSiguiente(nuevo);
     fin = nuevo;
   }
}

void ListaUsuarios::insertarOrdenado(Usuario u){
  NodoUsuario* nuevo = new NodoUsuario(u);
  if(estaVacia()){
    inicio = fin = nuevo;
  } else{
    Usuario uCabeza = inicio -> getUser();
    Usuario uCola = fin -> getUser();
    //si es menor que el primero
    if(u.nombre < uCabeza.nombre){
      insertarAlInicio(u);
    }
    //si es mayor que el ultimo
    else if(u.nombre > uCola.nombre){
      insertarAlFinal(u);
    }
    //si va en medio
    else {
      NodoUsuario *tmp = inicio -> getSiguiente();
      Usuario utmp = tmp -> getUser();
      while(utmp.nombre < u.nombre){
        tmp = tmp -> getSiguiente();
        utmp = tmp -> getUser();
      }
      //insertar el nuevo nodo antes de temp
      NodoUsuario* antmp = tmp -> getAnterior();
      antmp -> setSiguiente(nuevo);
      nuevo -> setAnterior(antmp);
      tmp -> setAnterior(nuevo);
      nuevo -> setSiguiente(tmp);
    }
  }

}

NodoUsuario* ListaUsuarios::buscar(std::string s){
  NodoUsuario* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getUser().nombre==s){
          return tmp;
      }
      tmp = tmp->getSiguiente();
  }
  return NULL;
}

bool ListaUsuarios::estaVacia() {
  if(inicio == NULL){
    return true;
  }
  return false;
}

Usuario ListaUsuarios::getUser(std::string name){
  Usuario result = {"",""};
    NodoUsuario * search = buscar(name);
    if(search!=NULL){
        return search->getUser();
    }
 return result;
}

std::list<Usuario> ListaUsuarios::getList(){
  std::list<Usuario> lista;
  NodoUsuario* tmp = inicio;

  while (tmp != NULL) {
    lista.push_back(tmp -> getUser());
    tmp = tmp -> getSiguiente();
  }

  return lista;
}

std::string ListaUsuarios::getUserName(const std::string& uid){
  std::string uname = "No se encontro el usuario";
  NodoUsuario * search = inicio;
  Usuario seu;
  while(search != NULL){
    seu = search -> getUser();
    if(seu.identificador == uid){
      uname = seu.nombre;
    }
    search = search -> getSiguiente();
  }
   return uname;
}
