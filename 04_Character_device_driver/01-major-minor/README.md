# Major minor

## 1. Dynamic Allocation of Device Number
    if (alloc_chrdev_region(&mdev.dev_num, 0, 1, "m_cdev") < 0) {
        pr_err("Failed to alloc chrdev region\n");
        return -1;
    }

alloc_chrdev_region(): This function dynamically allocates a range of character device numbers.

- &mdev.dev_num: This is where the allocated device number will be stored.
- 0: The second argument is the starting minor number. 0 means the kernel will automatically choose an available minor number.
- 1: The third argument specifies how many minor numbers to allocate. In this case, it allocates one minor number.
- "m_cdev": This is the name of the device, typically used for debugging and printing in dmesg logs.
  
If the allocation fails (returns a negative number), it prints an error message and returns -1 to indicate failure.

This method allows the kernel to automatically assign the device numbers (major and minor), avoiding the need to manually assign them.

## 2. Static Allocation of Device Number

    dev_t dev = MKDEV(173, 0);
    register_chrdev_region(&mdev.dev_num, 1, "m-cdev")

MKDEV(173, 0) : This is a macro used to create a dev_t value from a major number (173) and a minor number (00). Here, 173 is the major number for the device, and 0 is the minor number.

register_chrdev_region(): This function registers a statically allocated range of character device numbers.

- The first argument (&mdev.dev_num) is where the device number will be stored.
- The second argument (1) indicates that one device number is being registered.
- The third argument ("m-cdev") is the name of the device.

 ## What are Major and Minor numbers?

 ## Major number
The major number identifies the driver associated with a device.
  
Each major number is assigned to a specific driver, and the kernel uses it to determine which driver to invoke when interacting with the device.
  
For example:

- Major number 1 is typically assigned to the mem driver, which handles /dev/null , /dev/zero , etc.
- Major number 8 is typically assigned to SCSI disk drivers (/dev/sda, /dev/sdb).
## Minor Number:
The minor number is used to differentiate between devices that are handled by the same driver.
