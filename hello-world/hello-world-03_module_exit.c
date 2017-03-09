/*
 * with only exit function defined in module, we can able to insert module normally,
 * only one note: there will be no init func notifications i.e. obvious
 * so only using lsmod e can confirm module is loaded successfully
 * exit function is defined below so no change in exit/rmmod behaviour
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

void hello_world_03_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
}

module_exit(hello_world_03_exit);

MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World: Only Exit, init explicitly skipped");
MODULE_LICENSE("GPL");
