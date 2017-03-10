obj-m := hello-world-01.o				# := first initialization
obj-m += hello-world-02_module_init.o   # += adding the modules further, point to note: whole menuconfig works on this obj-$(CONFIG_FOO)
obj-m += hello-world-03_module_exit.o   # where FOO_CONFIG will be either n=disabled y=enabled/builtin kernel image m=module,
                                        # config dependency chain maintained by Kconfig: dependency & details at menuconfig.


obj-m := hello-world-02-and-03.o		# combine two c files together and form only one module, init and exit from diff. source file
hello-world-02-and-03-objs := hello-world-02_module_init.o hello-world-03_module_exit.o


obj-m := hello-world-04-a.o				# init function data (variables and functions) which are not using again in module can be
obj-m += hello-world-04-b.o				# marked with __init & __initdata to save the memory space.


obj-m := hello-world-05-export-symbol.o
obj-m += hello-world-05-use-symbol.o


all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
