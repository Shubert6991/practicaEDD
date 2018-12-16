#ifndef NODORECURSO_H
#define NODORECURSO_H

#include <string>

struct Recurso{
  std::string tipo;
  std::string contenido;
};

class NodoRecurso{
protected:
    Recurso resource;
    NodoRecurso *anterior;
public:
  //constructor
  NodoRecurso(Recurso r);
  NodoRecurso(Recurso r,NodoRecurso*ant);
  //metodos
  Recurso getRecurso();
  NodoRecurso* getAnterior();
  void setAnterior(NodoRecurso *a);
};


#endif //NODORECURSO_H
