# Pin control subsystem
command: to access root.

    su 

![alt text](image.png)

command: move the this folder.

    cd /sys/class/gpio/ 

![alt text](image-1.png)

    ls

![alt text](image-2.png)

command: export GPIO31 Pin

    echo 31 > /sys/class/gpio/export  

![alt text](image-3.png)

    cd gpio31 + ls

![alt text](image-4.png)

    cat direction

![alt text](image-5.png)

    echo out > direction

![alt text](image-6.png)

    echo 1 turn on LED

![alt text](image-7.png)
![alt text](image-8.png)

    echo 0 turn off LED 

![alt text](image-9.png)
![alt text](image-10.png)

    cd .. 
    echo 31 > /sys/class/gpio/unexport
    ls
    
![alt text](image-11.png)