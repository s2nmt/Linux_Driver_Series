obj-m:= gpio_syfs.o

CROSS=/home/s2nmt/work/beagle_bone_black/bb-kernel/dl/gcc-8.5.0-nolibc/arm-linux-gnueabi/bin/arm-linux-gnueabi-
KERNEL=/home/s2nmt/work/beagle_bone_black/bb-kernel/KERNEL/

EXTRA_CFLAG:=-Wall

all:
	make ARCH=arm CROSS_COMPILE=${CROSS} -C ${KERNEL} M=$(PWD) modules
clean:
	make -C ${KERNEL} M=$(PWD) clean
