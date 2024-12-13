# How to control hardware through IOCTL
## What is IOCTL

IOCTL (Input output control) is referred to as Input output control, which is used to talk to device drivers. This system call is available in most driver catgories. The major use of this is in case of handing some specific operations of a device for which the kernel does not have a system call by default.

Some Real-time Applications of IOCTL are:
- Ejecting the media from a 'cd' drive
- Changing the Baud Rate of the Serial port
- Adjusting the Volume
- Reading or Writing device registers

## What is IOCTL Used for in Linux?
### What is IOCTL Used for in Linux?
IOCTL is used to perform specific operations on device drivers that are not covered by standard systems calls. It allows userspace applications to send control commands to the kernel-space driver and retrieve information or modify device behavior.

### How does IOCTL work?

IOCTL works by passing commands and optional arguments from the usespace application to the device driver in the kernel. The driver then interprets the command and performs the requested operation, such as reading or wrting device register, adjusting device settings, or performing other device-specific tasks.

### Can IOCTL Pass Multiple Arguments Between User-space and kernel-space?

Yes. IOCTL can pass multiple arguments between use-space and kernel-space. If you need to pass multiple arguments, you can create a structure that contains all the necessary variables and pass the address of the structure as an argument in the IOCTL command.

### Are there Alternative Method to IOCTL for communication Between use-space and kernel-space?
Yes, there are alternative method to IOCTL for communication between use-space and kernel-space in Linux. Some of these methods include Procfs, Sysfs, Configfs,..

