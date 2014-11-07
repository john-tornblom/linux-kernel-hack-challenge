### About
Based on [the sample code provided](https://github.com/christoffer-nylen/linux-kernel-hack-challenge), I've created an environment which allow some testing on a host environment by translating powerpc instruction using qemu. You won't get accurate readings, but at least you'll be able to compile and execute the kernel without access to real powerpc hardware.

Perhaps someone else but me will find this stuff useful.

### Preparations
On ubuntu, install qemu, make and gcc
```
$ sudo apt-get install make gcc-powerpc-linux-gnu qemu-system-ppc
```

### Compile
Configure the kernel (just save and exit works fine), build it, and create an initial ramdisk containing the testcase
```
$ make menuconfig
$ make kernel
$ make initrd
```

### Test
Execute the testcase in a qemu enviorment, and save stdout to a log file
```
$ make test > test_results.log
```
When the test cases has finished executing, abort the execution using Ctrl-C
