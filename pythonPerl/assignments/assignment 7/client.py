import socket;
import struct;

sendData = '157867';

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM);
clientSocket.connect(('localhost', 20001));

print "Sending ", sendData, " to the server";

clientSocket.send(sendData);
data = clientSocket.recv(1024);
print 'Received', repr(data), " from the server\n\n";
# clientSocket.close()

#str(3).encode('utf')
