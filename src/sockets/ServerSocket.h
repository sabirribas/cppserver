// Definition of the ServerSocket class

#ifndef ServerSocket_class
#define ServerSocket_class

#include "Socket.h"

///Servidor baseado em Socket.
class ServerSocket : private Socket
{
 public:
  ///Construtor que abre uma porta para comunicação.
  ServerSocket ( int port );
  ///Construtor padrão.
  ServerSocket (){};
  ///Destrutor.
  virtual ~ServerSocket();
  ///Operador de leitura.
  const ServerSocket& operator << ( const std::string& ) const;
  ///Operador de escrita.
  const ServerSocket& operator >> ( std::string& ) const;
  ///Aceitação de conexão.
  void accept ( ServerSocket& );
};


#endif
