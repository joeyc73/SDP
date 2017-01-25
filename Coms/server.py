from threading import Thread
import select, os, socket

class server:
   def __init__(self):
      self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
      self.socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) #idk
      self.socket.bind(('localhost', 1080))

   def run(self):
      self.socket.listen(5)
      print "Listening..."
      self.conn, self.addr = self.socket.accept()
      try:
         print "Connected"
         while 1:
            self.conn.send("Hello!\n")
      except Exception, errtxt:
         print errtxt

   def exit(self):
      print "Disconnected"
      self.conn.close()

S = server()
S.run()
