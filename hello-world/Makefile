obj-m := hello-world-01.o				# := first initialization
obj-m += hello-world-02_module_init.o   # += adding the modules further, point to note: whole menuconfig works on this obj-$(CONFIG_FOO)
obj-m += hello-world-03_module_exit.o   # where FOO_CONFIG will be either n=disabled y=enabled/builtin kernel image m=module,
                                        # config dependency chain maintained by Kconfig: dependency & details at menuconfig.

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
