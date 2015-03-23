import sys
sys.path.append('../')
from client import RpcTcpClient
import json

method,params = 'echo',{'query':'query'}

client = RpcTcpClient(host='localhost',port=5001)
resultstring = client.call(method,params)
result = json.loads(resultstring)
print result