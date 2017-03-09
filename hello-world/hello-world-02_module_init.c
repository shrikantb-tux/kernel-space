/* only init with this module, so while inserting we observe normal insertion behaviour,
 * but while removing the module: rmmod : no exit defined so we can't able to remove it rmmod
 * always fails saying "device or resource busy" as the exit plays role of cleanup.
 * to remove such inserted module we have to reboot the system.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int hello_world_02_init(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}


module_init(hello_world_02_init);

MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World: Only Init, exit explicitly skipped");
MODULE_LICENSE("GPL");
