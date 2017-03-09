/* init function occupied space can be quickly freed after module loading, as the init functuion 
 * get called only once.
 * global data used in init function marked as __initdata and functiuons as __init to save module 
 * total occupied space. Also Note that do not use the __init & __initdata stuff adata or func inside
 * exit or other stuff, because after init the marked stuff will not be accessible, in this case if we
 * explicitly try to add call such unavailable stuff exit or other stuff, out kernel may cause page fault
 * & it may crash too.
 */

/* pass void explicitly if you are not going to add any params */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

__initdata int count = 10;

__init int hello_world_04_b_func_1(void)
{
	printk(KERN_ALERT "Inside function: %s at line : %d ", __FUNCTION__, __LINE__);
	return 0;
}


int hello_world_04_b_func_2(void) /* no __init as hello_world_04_b_exit also using it*/
{
	printk(KERN_ALERT "Inside function: %s at line : %d ", __FUNCTION__, __LINE__);
	return 0;
}


__init int hello_world_04_b_init(void)
{
	int sequence;
	
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	printk(KERN_ALERT "Value of global variable count= %d", count);

	for(sequence=0; sequence < count ; sequence++)
	{
		printk(KERN_ALERT " Inside loop :- %d", sequence);
	}

	hello_world_04_b_func_1();
	hello_world_04_b_func_2();

	return 0;
}


void hello_world_04_b_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	
	hello_world_04_b_func_2();
}

module_init(hello_world_04_b_init);
module_exit(hello_world_04_b_exit);


MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World __init");
MODULE_LICENSE("GPL");
