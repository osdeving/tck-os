#!/bin/bash

sudo losetup /dev/loop0 ../bin/FAT.ima
sudo mount /dev/loop0 ../floppy
sudo bochs -f ../config/bochs.bxrc -q
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
