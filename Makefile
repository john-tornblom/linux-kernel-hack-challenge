INITRD := initrd.cpio.gz
KERNEL := linux/arch/powerpc/boot/uImage
CONFIG := linux/arch/powerpc/configs/mpc85xx_defconfig

QEMU      := qemu-system-ppc
QEMU_ARGS := -kernel $(KERNEL) -initrd $(INITRD) -serial stdio -append "console=ttyS0"
QEMU_ARGS += -M mpc8544ds -cpu e500v2

all: $(INITRD) $(KERNEL)

.PHONY: $(INITRD) $(KERNEL) menuconfig

$(INITRD):
	make -C testcase
	cp testcase/case1 init
	echo init | cpio -o -H newc | gzip > $@ 
	rm init

$(KERNEL):
	git submodule sync
	git submodule update --init linux
	make -C linux ARCH=powerpc CROSS_COMPILE=powerpc-linux-gnu-

initrd: $(INITRD)

kernel: $(KERNEL)

menuconfig:
	cp $(CONFIG) linux/.config
	make -C linux ARCH=powerpc CROSS_COMPILE=powerpc-linux-gnu- menuconfig

test:
	$(QEMU) $(QEMU_ARGS)

clean:
	make -C testcase clean
	make -C linux clean
	rm -rf linux/.config
	rm -rf $(INITRD)
