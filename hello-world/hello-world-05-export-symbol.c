#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int hello_world_print_input(void)
{
	printk(KERN_ALERT "This is exported function %s at line : %d", __FUNCTION__, __LINE__);
	return 0;
}

EXPORT_SYMBOL(hello_world_print_input);

int hello_world_05_init(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}


void hello_world_05_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
}

module_init(hello_world_05_init);
module_exit(hello_world_05_exit);


MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World: export a function ");
MODULE_LICENSE("GPL");
