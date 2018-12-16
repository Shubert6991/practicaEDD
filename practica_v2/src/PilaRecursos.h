#ifndef PILARECURSOS_H
#define PILARECURSOS_H
#include "NodoRecurso.h"
#include <string>
#include <list>

class PilaRecursos{
private:
  NodoRecurso* buscar(std::string s);
  public:
  NodoRecurso *inicio, *fin;
  PilaRecursos();
  void insertarAlInicio(Recurso r);
  Recurso getResource(std::string tipo);
  bool estaVacia();
  std::list<Recurso> getList();
  std::string pop();
};
#endif //PILARECURSOS_H
