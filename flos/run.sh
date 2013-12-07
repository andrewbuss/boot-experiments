losetup /dev/loop0 floppy.img
mount /dev/loop0 /mnt
cp kernel /mnt/kernel
umount /dev/loop0
bochs -qf bochsrc.txt
/sbin/losetup -d /dev/loop0
