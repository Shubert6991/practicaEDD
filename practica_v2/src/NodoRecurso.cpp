#include "NodoRecurso.h"
//constructores
NodoRecurso::NodoRecurso(Recurso r){
  resource = r;
  anterior = NULL;
}

NodoRecurso::NodoRecurso(Recurso r,NodoRecurso*ant){
  resource = r;
  anterior = ant;
}

//metodos
Recurso NodoRecurso::getRecurso(){
  return resource;
}

NodoRecurso* NodoRecurso::getAnterior(){
  return anterior;
}

void NodoRecurso::setAnterior(NodoRecurso *a){
  anterior = a;
}
