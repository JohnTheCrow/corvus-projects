#!/bin/bash

if [ $# != 1 ]; then
	echo Usage: rpmunpacker RPM
fi

if [ -f $1 ]; then
	PKGDIR=$(rpm -qp --qf '%{NAME}' $1 )
	mkdir $PKGDIR
	cp $1 $PKGDIR
	read -ep 'Do you want to delete the original .rpm file? (y/n) ' ANS
	if [ $ANS == "y" ]; then
		rm $1
	fi
	cd $PKGDIR
	rpm2cpio $1 | cpio -idm --quiet
	rm -f $1
else
	echo Usage: rpmunpacker RPM
fi
