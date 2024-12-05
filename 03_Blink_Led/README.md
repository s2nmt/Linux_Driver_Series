# Introduction
This folder contains code to implement an LED blink driver on the BeagleBone Black.

To cross-compile the led.c file and build it into the led.ko kernel module, follow these steps:
- 1 Cross-compile the led.c file on your host machine to generate led.ko (make command in blink_led folder).
- 2 Copy led.ko to an SD card using the following command:

    sudo mount /dev/sdb1 /media/rootfs/
  
    sudo cp led.ko /media/rootfs/home/debian/
  
    sync
  
    sudo umount /media/rootfs
- 3 Insert the SD card into the BeagleBone Black, power it on and load the kerbel module with:

    sudo /sbin/insmod led.ko # Led will turn on

- 4 Remove it

    sudo /sbin/rmmod led.ko # led will turn off

## Export variable to PATH

**Step1: Open file .bashrc to modify**

- nano ~/.bashrc

**Step2: add line into last file**

- export PATH=$PATH:/sbin

**Step3: save and exit**

## Apply changes immediately by re-sourcing the file
- source ~/.bashrc
