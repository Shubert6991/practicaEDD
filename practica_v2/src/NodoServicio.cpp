#include "NodoServicio.h"
//constructores
NodoServicio::NodoServicio(Servicio s){
  s.identificador_session = getIdentificador();
  service = s;
  siguiente = NULL;
}

NodoServicio::NodoServicio(Servicio s,NodoServicio*sig){
  service = s;
  siguiente = sig;
}

//metodos
Servicio NodoServicio::getServicio(){
  return service;
}

NodoServicio* NodoServicio::getSiguiente(){
  return siguiente;
}

void NodoServicio::setSiguiente(NodoServicio *s){
  siguiente = s;
}

std::string NodoServicio::getIdentificador()
{
  static const std::string charList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  srand(time(0));
  std::string alphanumeric = "";
  for(int i = 0; i < 8; i++) {
    alphanumeric += charList [rand() % charList.size()];
  }

return alphanumeric;
}
