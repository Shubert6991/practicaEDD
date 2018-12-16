#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H

#include <string>

struct Usuario{
  std::string identificador;
  std::string nombre;
  std::string correo;
  std::string fecha;
};

class NodoUsuario{
protected:
    Usuario user;
    NodoUsuario *siguiente,*anterior;
    std::string getIdentificador();
public:
  //constructor
  NodoUsuario(Usuario u);
  NodoUsuario(Usuario u,NodoUsuario*sig,NodoUsuario*ant);
  //metodos
  Usuario getUser();
  NodoUsuario* getSiguiente();
  NodoUsuario* getAnterior();
  void setSiguiente(NodoUsuario *s);
  void setAnterior(NodoUsuario *a);
};


#endif //NODOUSUARIO_H
