# -*-coding=utf-8 -*-
'''
Created on 2016年11月21日
@author: pg
'''

import os  
  
write_fifo_path = '/tmp/read_fifo'  
read_fifo_path = '/tmp/write_fifo'
  
def main():  
    if(os.access(write_fifo_path, os.F_OK) == False):  
        os.mkfifo(write_fifo_path)
      
    read_fd = os.open(read_fifo_path, os.O_RDONLY)  
    write_fd = os.open(write_fifo_path, os.O_WRONLY)  
      
    while True:  
        out_msg = input('client:>')  
        os.write(write_fd, out_msg.encode(encoding="utf-8"))
        in_msg = os.read(read_fd, 100)  
        print('server:>' + in_msg.decode())
    os.close(read_fd)
    os.write(write_fd)
  
if __name__ == '__main__':  
    main()




