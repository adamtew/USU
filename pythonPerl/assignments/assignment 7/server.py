def fun(limit):
    limit = int(limit)
    limitn = limit+1
    primes = dict()
    for i in range(2, limitn): primes[i] = True

    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

import socket

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serversocket.bind(('localhost', 20001))
serversocket.listen(5) # become a server socket, maximum 5 connections

while True:
    connection, address = serversocket.accept()
    while 1:
        n = connection.recv(1024)
        if not n:       break;
        print address, "Connected";
        print "Received ", n, " from client"
        n = fun(n);
        n = str(n)
        print "Returning ", n, " to client\n\n"

        connection.sendall(n);


