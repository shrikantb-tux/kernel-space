#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

int count = 0;

module_param(count, int, 0644); //param name, data type and permisson to edit the /sys/module* variable entry

int hello_world_06_init(void)
{
	int index = 0;
	
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	for(index=0; index <= count ; index++)
	{
		printk(KERN_ALERT "The check index = %d from function: %s \n", index, __FUNCTION__);
	}
	return 0;
}


void hello_world_06_exit(void)
{
	int index = 0;
	
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	for(index=0; index <= count; index++)
	{
		printk(KERN_ALERT "The check index = %d from function: %s \n", index, __FUNCTION__);
	}

}

module_init(hello_world_06_init);
module_exit(hello_world_06_exit);


MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World: param part one");
MODULE_LICENSE("GPL");
