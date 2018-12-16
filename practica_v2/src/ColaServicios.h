#ifndef COLASERVICIOS_H
#define COLASERVICIOS_H
#include "NodoServicio.h"
#include <string>
#include <list>

class ColaServicios{
private:
  NodoServicio* buscar(std::string s);
  public:
  NodoServicio *inicio, *fin;
  ColaServicios();
  void insertarAlFinal(Servicio s);
  Servicio getServicio(std::string serv);
  bool estaVacia();
  std::list<Servicio> getList();
  std::string getServiceByID(std::string uid);
};
#endif //COLASERVICIOS_H
