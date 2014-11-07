INITRD := initrd.cpio.gz
LINUX  := linux-2.6.32
KERNEL := $(LINUX)/arch/powerpc/boot/uImage
CONFIG := $(LINUX)/arch/powerpc/configs/mpc85xx_defconfig

QEMU      := qemu-system-ppc
QEMU_ARGS := -kernel $(KERNEL) -initrd $(INITRD) -nographic -serial stdio -append "console=ttyS0"
QEMU_ARGS += -M mpc8544ds -cpu e500v2

all: $(INITRD) $(KERNEL)

.PHONY: $(INITRD) $(KERNEL) menuconfig

$(INITRD):
	make -C testcase
	cp testcase/case1 init
	echo init | cpio -o -H newc | gzip > $@ 
	rm init

$(KERNEL):
	make -C $(LINUX) ARCH=powerpc CROSS_COMPILE=powerpc-linux-gnu-

initrd: $(INITRD)

kernel: $(KERNEL)

menuconfig:
	cp $(CONFIG) $(LINUX)/.config
	make -C $(LINUX) ARCH=powerpc CROSS_COMPILE=powerpc-linux-gnu- menuconfig

test:
	$(QEMU) $(QEMU_ARGS)

clean:
	make -C testcase clean
	make -C $(LINUX) clean
	rm -rf $(LINUX)/.config
	rm -rf $(INITRD)
