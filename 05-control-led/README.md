# How to control hardware through IOCTL
## What is IOCTL

IOCTL (Input output control) is referred to as Input output control, which is used to talk to device drivers. This system call is available in most driver catgories. The major use of this is in case of handing some specific operations of a device for which the kernel does not have a system call by default.

Some Real-time Applications of IOCTL are:
- Ejecting the media from a 'cd' drive
- Changing the Baud Rate of the Serial port
- Adjusting the Volume
- Reading or Writing device registers

## Steps Involved in IOCTL
There are some steps involved in implementing IOCTL in Linux Device Drivers-
    Create IO