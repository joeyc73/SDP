from socket import *
import select

data = None

timeout = 3 #seconds
msg = "test"

host = "localhost"
port = 1080

s = socket(AF_INET, SOCK_STREAM)

ready = select.select([s],[],[],timeout)
s.connect((host,port))

while 1:
   if data != None:
      print("Sending message...")
      s.sendall(msg)
      data = None
      print("Sent")
      continue

   if ready[0]: #data is available
      data = s.recv(4096)
      print("Data Received")
      print data
      continue
