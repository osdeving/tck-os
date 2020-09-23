#!/bin/bash

sudo losetup /dev/loop0 ../bin/FAT.ima
sudo mount /dev/loop0 ../floppy
sudo cp ../bin/kernel.sys ../floppy
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
