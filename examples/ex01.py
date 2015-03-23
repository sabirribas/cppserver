import sys
sys.path.append('../')
from client import RpcTcpClient

method,params = 'test',{'query':'query'}

client = RpcTcpClient(host='localhost',port=5001)
resultstring = client.call(method,params)
print resultstring