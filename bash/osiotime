#!/bin/bash

# Pull out the lines from a given sar file where the difference between await
# and svctm is greater than a given number of milliseconds.


if [ $# != 2 ]; then
	echo Usage: osiotime SAR_FILE MILLISECONDS
	exit
fi

echo '00:00:00          DEV       tps  rd_sec/s  wr_sec/s  avgrq-sz  avgqu-sz     await     svctm     %util'
awk '/await/,/Average/' $1 | grep -Ev 'await|Average' | awk -v MS=$2 '( $(NF-2) - $(NF-1) ) > MS '
