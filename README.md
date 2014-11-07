Preparations
===========================
$ sudo apt-get install make gcc-powerpc-linux-gnu qemu-system-ppc

Compile
===========================
$ make menuconfig
$ make kernel
$ make initrd

Test
===========================
$ make test > test_results.log

