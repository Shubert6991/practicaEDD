#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include "NodoUsuario.h"
#include <string>
#include <list>

class ListaUsuarios{
private:
  NodoUsuario* buscar(std::string s);
  public:
  NodoUsuario *inicio, *fin;
  ListaUsuarios();
  void insertarAlInicio(Usuario u);
  void insertarAlFinal(Usuario u);
  void insertarOrdenado(Usuario u);
  Usuario getUser(std::string name);
  bool estaVacia();
  std::list<Usuario> getList();
  std::string getUserName(const std::string& uid);
};
#endif //LISTAUSUARIOS_H
