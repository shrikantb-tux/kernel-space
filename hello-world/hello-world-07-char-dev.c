#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>


int hw_07_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}

ssize_t hw_07_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}

ssize_t hw_07_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return length;
}

int hw_07_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	return 0;
}


struct file_operations hw_07_file_operations = {
	.owner		=	THIS_MODULE,
	.open		=	hw_07_open,
	.read		=	hw_07_read,
	.write		=	hw_07_write,
	.release	=	hw_07_close,
};


int hello_world_07_init(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	register_chrdev(255, "char dev", &hw_07_file_operations);
	return 0;
}


void hello_world_07_exit(void)
{
	printk(KERN_ALERT "This function is %s at line %d \n", __FUNCTION__, __LINE__);
	unregister_chrdev(250, "char dev");
}

module_init(hello_world_07_init);
module_exit(hello_world_07_exit);


MODULE_AUTHOR("Shrikant");
MODULE_DESCRIPTION("Hello World: char. device driver");
MODULE_LICENSE("GPL");
