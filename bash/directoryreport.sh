#!/bin/bash

# Tests if directories are empty or have items within.
# Does not follow symbolic links.

if test $# == 0; then
	echo "Usage: directoryreport {DIRECTORIES}..."
else 
echo ' '
	for d in $@; do
		if test -L $d -o ! -d $d; then
			echo "${d}: is not a directory"
		fi	

		if test ! -L $d -a -d $d -a $( ls -l $d | wc -l ) == 1; then
			echo "${d}: is empty"
		fi

		if test $( ls -l $d | wc -l ) -gt 1; then 
			echo "${d}: is not empty"
		fi

	done		
echo ' '
fi
