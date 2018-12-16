#ifndef NODOSERVICIO_H
#define NODOSERVICIO_H

#include <string>

struct Servicio{
  std::string identificador_session;
  std::string identificador_usuario;
  std::string contenido;
};

class NodoServicio{
protected:
    Servicio service;
    NodoServicio *siguiente;
    std::string getIdentificador();
public:
  //constructor
  NodoServicio(Servicio s);
  NodoServicio(Servicio s,NodoServicio*sig);
  //metodos
  Servicio getServicio();
  NodoServicio* getSiguiente();
  void setSiguiente(NodoServicio *s);
};


#endif //NODOSERVICIO_H
