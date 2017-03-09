/* init function occupied space can be quickly freed after module loading, as the init functuion 
 * get called only once.
 * global data used in init function can be marked as __initdata and functiuons as __init to save 
 * module total occupied space.
 */


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

int count = 10;

int hello_world_04_a_func_1(void)
{
	printk(KERN_ALERT "Inside function: %s at line : %d ", __FUNCTION__, __LINE__);
	return 0;
}


int hello_world_04_a_func_2(void)
{
	printk(KERN_ALERT "Inside function: %s at line : %d ", __FUNCTION__, __LINE__);
	return 0;
}


int hello_world_04_a_init(void)
{
	int sequence;
	
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	printk(KERN_ALERT "Value of global variable count= %d", count);

	for(sequence=0; sequence < count ; sequence++)
	{
		printk(KERN_ALERT " Inside loop :- %d", sequence);
	}

	hello_world_04_a_func_1();
	hello_world_04_a_func_2();

	return 0;
}


void hello_world_04_a_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	
	hello_world_04_a_func_2();
}

module_init(hello_world_04_a_init);
module_exit(hello_world_04_a_exit);


MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World __init");
MODULE_LICENSE("GPL");
