#include "PilaRecursos.h"

PilaRecursos::PilaRecursos(){
  inicio = fin = NULL;
}

void PilaRecursos::insertarAlInicio(Recurso r){
  NodoRecurso* nuevo = new NodoRecurso(r);
  if(estaVacia()){
    inicio = fin = nuevo;
  }else {
     nuevo -> setAnterior(inicio);
     inicio = nuevo;
   }
}

NodoRecurso* PilaRecursos::buscar(std::string s){
  NodoRecurso* tmp = inicio;
  while (tmp!=NULL) {
      if(tmp->getRecurso().tipo==s){
          return tmp;
      }
      tmp = tmp->getAnterior();
  }
  return NULL;
}

bool PilaRecursos::estaVacia() {
  if(inicio == NULL){
    return true;
  }
  return false;
}

Recurso PilaRecursos::getResource(std::string tipo){
  Recurso result = {"",""};
    NodoRecurso * search = buscar(tipo);
    if(search!=NULL){
        return search->getRecurso();
    }
 return result;
}

std::list<Recurso> PilaRecursos::getList(){
  std::list<Recurso> lista;
  NodoRecurso* tmp = inicio;

  while (tmp != NULL) {
    lista.push_back(tmp -> getRecurso());
    tmp = tmp -> getAnterior();
  }

  return lista;
}

std::string PilaRecursos::pop(){
  NodoRecurso* aux = inicio;
  Recurso auxr;
  if(aux != NULL){
    auxr = aux -> getRecurso();
    inicio = inicio -> getAnterior();
    return "tipo : " + auxr.tipo + ", contenido: " + auxr.contenido;
  }
  return "Pila de recursos vacia";
  delete aux;
}
