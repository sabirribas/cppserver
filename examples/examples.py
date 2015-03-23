import sys
sys.path.append('../')
from client import RpcTcpClient
import json

client = RpcTcpClient(host='localhost',port=5001)

method,params = 'test',{'query':'query'}
resultstring = client.call(method,params)
result = json.loads(resultstring)
print result

method,params = 'echo',{'query':'query'}
resultstring = client.call(method,params)
result = json.loads(resultstring)
print result