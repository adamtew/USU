import SimpleHTTPServer

SimpleHTTPServer



import SocketServer
import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM);

s.bind(('localhost', 20001));
s.listen(5);

i = 0;
while i < 5:
	print i;
	i += 1;
	connection, address = serversocket.accept();
	buf = connection.recv(64)

# s = socket.socket(
#     socket.AF_INET, socket.SOCK_STREAM)

# minimal_forking_server

# print "Hello World";


