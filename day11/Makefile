
obj-m = gpio-intr.o

modules:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/sunbeam/Desktop/linux M=`pwd` modules

copy:
	scp gpio-intr.ko switch-led-test.c debian@192.168.7.2:/home/debian/POOJA	
	
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/sunbeam/Desktop/linux M=`pwd` clean

.PHONY: all clean

