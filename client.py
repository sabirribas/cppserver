import socket
import json
import logging
import random

class RpcTcpClient:

        def __init__(self,host='localhost',port=5000):
                self.HOST = host
                self.PORT = port

        def call(self,method,params):

                content = {"method":method,"params":params}

                # setup
                HOST = self.HOST # Endereco IP do Servidor
                PORT = self.PORT # Porta que o Servidor esta
                tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                tcp.bind(('0.0.0.0', random.randint(5001,10000)))
                dest = (HOST, PORT)
                tcp.connect(dest)

                # send
                msg = json.dumps(content)
                tcp.send (msg)

                # recv
                msg = tcp.recv(1048576)
                #logging.info('RECEIVED: %s' % msg )

                # close
                tcp.close()

                return msg