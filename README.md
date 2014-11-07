Preparations
===========================
On ubuntu, install qemu, make and gcc
```
$ sudo apt-get install make gcc-powerpc-linux-gnu qemu-system-ppc
```

Compile
===========================
Configure the kernel (just save and exit works fine), build it, and create an initial ramdisk containing the testcase
```
$ make menuconfig
$ make kernel
$ make initrd
```

Test
===========================
Execute the testcase in a qemu enviorment, and save stdout to a log file
```
$ make test > test_results.log
```
When the test cases has finished executing, abort the execution using Ctrl-C
