#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int example_01_simple_module_init(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}


void example_01_simple_module_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
}

module_init(example_01_simple_module_init);
module_exit(example_01_simple_module_exit);
