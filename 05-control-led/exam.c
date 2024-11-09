#include <linux/module.h>   /* Define module_init(), module_exit() */
#include <linux/fs.h>       /* Define alloc_chrdev_region(), register_chrdev_region() */
#include <linux/device.h>   /* Define device_create(), class_create() */
#include <linux/cdev.h>     /* Define cdev_init(), cdev_add() */
#include <linux/uaccess.h>  /* Define copy_to_user(), copy_from_user() */
#include <linux/slab.h>     /* Define kmalloc(), kfree() */
#include <linux/ioctl.h>    /* Define ioctl macros */
#include <linux/io.h>

#define DRIVER_AUTHOR "phonglt9 linuxfromscratch@gmail.com"
#define DRIVER_DESC   "Hello world kernel module with ioctl"
#define DRIVER_VERS   "1.0"

#define NPAGES  1

/* Define IOCTL commands */
#define IOCTL_MAGIC 'k'
#define IOCTL_FUNC1 _IO(IOCTL_MAGIC, 1)
#define IOCTL_FUNC2 _IO(IOCTL_MAGIC, 2)

#define GPIO_0_ADDR_BASE        0x44E07000
#define GPIO_0_ADDR_SIZE        (0x44E07FFF - 0x44E07000)

#define GPIO_OE_OFFSET                  0x134
#define GPIO_CLEARDATAOUT_OFFSET        0x190
#define GPIO_SETDATAOUT_OFFSET          0x194

#define LED                             (1 << 31)


uint32_t __iomem *base_addr;

struct m_foo_dev {
    int32_t size;
    char *kmalloc_ptr;
    dev_t dev_num;
    struct class *m_class;
    struct cdev m_cdev;
} mdev;

/* Function Prototypes */
static int      __init chdev_init(void);
static void     __exit chdev_exit(void);
static int      m_open(struct inode *inode, struct file *file);
static int      m_release(struct inode *inode, struct file *file);
static long     m_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/* File operations structure */
static struct file_operations fops = {
    .owner          = THIS_MODULE,
    .open           = m_open,
    .release        = m_release,
    .unlocked_ioctl = m_ioctl,
};

/* IOCTL function */
static long m_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    switch (cmd) {
        case IOCTL_FUNC1:
            pr_info("Function 1 called via ioctl\n");
            *(base_addr + GPIO_SETDATAOUT_OFFSET/4) |= LED; 
	    // Call your function1() here
            break;
        case IOCTL_FUNC2:
            pr_info("Function 2 called via ioctl\n");
	    *(base_addr + GPIO_CLEARDATAOUT_OFFSET / 4) |= LED;
            // Call your function2() here
            break;
        default:
            pr_info("Invalid ioctl command\n");
            return -EINVAL;
    }
    return 0;
}

/* Open function */
static int m_open(struct inode *inode, struct file *file)
{
    pr_info("Device opened\n");
    return 0;
}

/* Release function */
static int m_release(struct inode *inode, struct file *file)
{
    pr_info("Device closed\n");
    return 0;
}

/* Constructor */
static int __init chdev_init(void)
{
    base_addr = ioremap(GPIO_0_ADDR_BASE,GPIO_0_ADDR_SIZE);
    if(!base_addr){
        return -ENOMEM;
    }
    *(base_addr + GPIO_OE_OFFSET/4) &= ~LED;

    if (alloc_chrdev_region(&mdev.dev_num, 0, 1, "m-cdev") < 0) {
        pr_err("Failed to allocate chrdev region\n");
        return -1;
    }

    pr_info("Major = %d, Minor = %d\n", MAJOR(mdev.dev_num), MINOR(mdev.dev_num));

    if ((mdev.m_class = class_create(THIS_MODULE, "m_class")) == NULL) {
        pr_err("Cannot create class\n");
        goto rm_device_numb;
    }

    if ((device_create(mdev.m_class, NULL, mdev.dev_num, NULL, "m_cdev")) == NULL) {
        pr_err("Cannot create device\n");
        goto rm_class;
    }

    cdev_init(&mdev.m_cdev, &fops);
    if (cdev_add(&mdev.m_cdev, mdev.dev_num, 1) < 0) {
        pr_err("Cannot add cdev to system\n");
        goto rm_device;
    }

    pr_info("Kernel module initialized\n");
    return 0;

rm_device:
    device_destroy(mdev.m_class, mdev.dev_num);
rm_class:
    class_destroy(mdev.m_class);
rm_device_numb:
    unregister_chrdev_region(mdev.dev_num, 1);
    return -1;
}

/* Destructor */
static void __exit chdev_exit(void)
{
    *(base_addr + GPIO_CLEARDATAOUT_OFFSET / 4) |= LED;
    iounmap(base_addr);

    cdev_del(&mdev.m_cdev);
    device_destroy(mdev.m_class, mdev.dev_num);
    class_destroy(mdev.m_class);
    unregister_chrdev_region(mdev.dev_num, 1);
    pr_info("Kernel module removed\n");
}

module_init(chdev_init);
module_exit(chdev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION(DRIVER_VERS);
