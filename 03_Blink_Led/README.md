# Introduction
This folder contains code to implement an LED blink driver on the BeagleBone Black.

To cross-compile the led.c file and build it into the led.ko kernel module, follow these steps:
- 1 Cross-compile the led.c file on your host machine to generate led.ko.
- 2 Copy led.ko to an SD card using the following command:

    sudo mount /dev/sdb1 /media/rootfs/
    sudo cp led.ko /media/rootfs/home/debian/
    sync
    sudo umount /media/rootfs
- 3 Insert the SD card into the BeagleBone Black, power it on and load the kerbel module with:

    sudo /sbin/insmod led.ko

The LED will turn on when you use insmod, and it will turn off when you remove the module with rmmod:

    sudo /sbin/rmmod led.ko

## export variable to PATH
### Step1: Open file .bashrc to modify
- nano ~/.bashrc
### Step2: add line into last file
- export PATH=$PATH:/sbin
### Step3: save and exit

## Apply changes immediately by re-sourcing the file
- source ~/.bashrc
