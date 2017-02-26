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

# if 0
This is quick section gives real o/p inserting and removing the simple module
o/p

Feb 26 23:58:53 shrikant-VirtualBox kernel: [ 6297.531271] hello_world_01: module license 'unspecified' taints kernel.
Feb 26 23:58:53 shrikant-VirtualBox kernel: [ 6297.531275] Disabling lock debugging due to kernel taint
Feb 26 23:58:53 shrikant-VirtualBox kernel: [ 6297.534579] This function is hello_world_01_init at line 7 
Feb 26 23:59:22 shrikant-VirtualBox kernel: [ 6326.815988] This function is hello_world_01_exit at line 14 

#endif
