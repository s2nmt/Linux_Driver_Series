#include <linux/module.h>   /* This module defines macro such as module_init/module_exit */
#include <linux/kernel.h>   /* This module defines functions such as allocate major/minor number */
#include <linux/device.h>   /* This module defines functions such as class_create/device_create */
#include <linux/slab.h>     /* This module defines functions such as kmalloc */
#include <linux/cdev.h>     /* This module defines struct such as cdev_init/cdev_add */
#include <linux/uaccess.h>  /* This module defines functions such as copy_to_user/copy_from_user */

#define DRIVER_AUTHOR "Minh Tuan"
#define DRIVER_DESC   "GPIO sysfs driver (integer-based)"

struct k_foo_dev {
    struct kobject *kobj_ref;
}mdev;

/*************** Function Prototypes ***************/
static int __init hello_world_init(void);
static void __exit hello_world_exit(void);

/*************** Sysfs functions ***************/
static ssize_t sysfs_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
static ssize_t sysfs_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);

struct kobj_attribute m_attr = __ATTR(direction, 0660, sysfs_show, sysfs_store);

/* This function will be called when we read the sysfs file */
static ssize_t sysfs_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf) {
    pr_info("Sysfs read...\n");
    return 0;
}

/* This function will be called when we write the sysfs file */
static ssize_t sysfs_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count) {
    pr_info("Sysfs write...\n");
    return count;
}

static int __init hello_world_init(void) {
    /* Constructor */
    /* #1. It will create a directory under /sys [firmware_kobj, kernel_kobj] */
    mdev.kobj_ref = kobject_create_and_add("bbb_gpios", NULL);

    /* #2. Creating sys entry under /sys/bbb_gpios */
    if (sysfs_create_file(mdev.kobj_ref, &m_attr.attr)) {
        pr_info("Cannot create sysfs file...\n");
        goto rm_kobj;
    }

    pr_info("Hello! Initialize successfully!\n");
    return 0;

rm_kobj:
    kobject_put(mdev.kobj_ref);
    return -1;
}

static void __exit hello_world_exit(void) {
    /* Destructor */
    sysfs_remove_file(mdev.kobj_ref, &m_attr.attr); /* #2 */
    kobject_put(mdev.kobj_ref); /* #1 */
    pr_info("Good bye my fen!!!\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_VERSION("1.0");
