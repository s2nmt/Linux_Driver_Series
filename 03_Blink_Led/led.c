#include <linux/module.h>       /* Needed by all modules */
#include <linux/io.h>


#define GPIO_0_ADDR_BASE        0x44E07000
#define GPIO_0_ADDR_SIZE        (0x44E07FFF - 0x44E07000)

#define GPIO_OE_OFFSET                  0x134
#define GPIO_CLEARDATAOUT_OFFSET        0x190
#define GPIO_SETDATAOUT_OFFSET          0x194

#define LED                             (1 << 31)


uint32_t __iomem *base_addr;


static int __init led_init(void)
{
    base_addr = ioremap(GPIO_0_ADDR_BASE,GPIO_0_ADDR_SIZE);
    if(!base_addr){
        return -ENOMEM;
    }
    *(base_addr + GPIO_OE_OFFSET/4) &= ~LED;
    *(base_addr + GPIO_SETDATAOUT_OFFSET/4) |= LED;

    pr_info("Hello! Initizliaze successfully!\n");

    return 0;
}

static void __exit led_exit(void)
{
    *(base_addr + GPIO_CLEARDATAOUT_OFFSET / 4) |= LED;
    iounmap(base_addr);
    pr_info("Good bye my friend");
}

module_init(led_init);
module_exit(led_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Minh Tuan");
MODULE_DESCRIPTION("Blink led");
