# Commands

## Copy file to SDCard
sudo mount /dev/sdb1 /media/rootfs/
sudo cp led.ko /media/rootfs/home/debian/
sync
sudo umount /media/rootfs

## turn led on/off 
sudo /sbin/insmod led.ko
sudo /sbin/rmmod led.ko

## export variable to PATH
### Step1: Open file .bashrc to modify
- nano ~/.bashrc
### Step2: add line into last file
- export PATH=$PATH:/sbin
## Step3: save and exit
## apply changes immediately by re-sourcing the file
- source ~/.bashrc
