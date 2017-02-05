#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int hello_world_01_init(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}


void hello_world_01_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
}

module_init(hello_world_01_init);
module_exit(hello_world_01_exit);
