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

# if 0
This is quick section gives real o/p inserting and removing the simple module
o/p
Mar  5 23:18:31 shrikant-VirtualBox kernel: [ 4333.071395] hello_world_03_module_exit: module license 'unspecified' taints kernel.
Mar  5 23:18:31 shrikant-VirtualBox kernel: [ 4333.071398] Disabling lock debugging due to kernel taint

after adding lic:

as no init functuion available so no notifiation in logs/dmesg
only available way to check via lsmod as below..

lsmod | grep hello 
hello_world_03_module_exit    16384  0
#endif
