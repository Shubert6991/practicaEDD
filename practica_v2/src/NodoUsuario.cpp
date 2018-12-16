#include "NodoUsuario.h"
//constructores
NodoUsuario::NodoUsuario(Usuario u){
  u.identificador = getIdentificador();
  user = u;
  //user.identificador = "getIdentificador()";
  siguiente = NULL;
  anterior = NULL;
}

NodoUsuario::NodoUsuario(Usuario u,NodoUsuario*sig,NodoUsuario*ant){
  user = u;
  siguiente = sig;
  anterior = ant;
}

//metodos

Usuario NodoUsuario::getUser(){
  return user;
}

NodoUsuario* NodoUsuario::getSiguiente(){
  return siguiente;
}

NodoUsuario* NodoUsuario::getAnterior(){
  return anterior;
}

void NodoUsuario::setSiguiente(NodoUsuario *s){
  siguiente = s;
}

void NodoUsuario::setAnterior(NodoUsuario *a){
  anterior = a;
}

std::string NodoUsuario::getIdentificador()
{
  static const std::string charList = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

  srand(time(0));
  std::string alphanumeric = "";
  for(int i = 0; i < 8; i++) {
    alphanumeric += charList [rand() % charList.size()];
  }

return alphanumeric;
}
