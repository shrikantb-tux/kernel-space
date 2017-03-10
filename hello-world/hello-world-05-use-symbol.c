/*
 * Case 1: directly insert the use module without export function module
 * This module using a exported function from other module, when we try to insert this
 * module, in absence of hello-world-05-export-symbol.ko we unable to instert it into kernel
 * error: Unknown symbol hello_world_print_input (err 0)
 *
 * Case 2: first insert export function and then insert the function use module.
 * check lsmod: observe the count increment of use-by to 1 @ use module name
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int hello_world_print_input(void); // prototype of function 


int hello_world_05_init(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	hello_world_print_input();
	return 0;
}


void hello_world_05_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
}

module_init(hello_world_05_init);
module_exit(hello_world_05_exit);


MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World: use exported function");
MODULE_LICENSE("GPL");
