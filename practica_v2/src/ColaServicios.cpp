#include "ColaServicios.h"

ColaServicios::ColaServicios(){
  inicio = fin = NULL;
}

void ColaServicios::insertarAlFinal(Servicio s){
  NodoServicio* nuevo = new NodoServicio(s);
  if(estaVacia()){
    inicio = fin = nuevo;

  }else {
     fin -> setSiguiente(nuevo);
     fin = nuevo;
   }
}

NodoServicio* ColaServicios::buscar(std::string ids){
  NodoServicio* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getServicio().identificador_session==ids){
          return tmp;
      }
      tmp = tmp->getSiguiente();
  }
  return NULL;
}

bool ColaServicios::estaVacia() {
  if(inicio == NULL){
    return true;
  }
  return false;
}

Servicio ColaServicios::getServicio(std::string ids){
  Servicio result = {"",""};
    NodoServicio * search = buscar(ids);
    if(search!=NULL){
        return search->getServicio();
    }
 return result;
}

std::list<Servicio> ColaServicios::getList(){
  std::list<Servicio> lista;
  NodoServicio* tmp = inicio;

  while (tmp != NULL) {
    lista.push_back(tmp -> getServicio());
    tmp = tmp -> getSiguiente();
  }

  return lista;
}

std::string ColaServicios::getServiceByID(std::string uid){
  std::string uname = "No se encontro el servicio";
  NodoServicio * search = inicio;
  Servicio seu;
  while(search != NULL){
    seu = search -> getServicio();
    if(seu.identificador_usuario == uid){
      uname = seu.identificador_session;
    }
    search = search -> getSiguiente();
  }
   return uname;
}
