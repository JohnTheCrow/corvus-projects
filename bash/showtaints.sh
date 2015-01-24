#!/bin/bash

# Run this in a sosreport and it will tell you what the individual taint
# values are.

POWERS='1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536 131072 262144 524288 1048576 2097152 4194304 8388608 16777216 33554432 67108864 134217728 268435456 536870912 1073741824 2147483648'

for taint in $POWERS ; do echo $(cat proc/sys/kernel/tainted) $taint | gawk 'and($1, $2) {print $2}'; done

echo
echo '    1 - A module with a non-GPL license has been loaded, this'
echo '        includes modules with no license.'
echo '        Set by modutils >= 2.4.9 and module-init-tools.'
echo '    2 - A module was force loaded by insmod -f.'
echo '        Set by modutils >= 2.4.9 and module-init-tools.'
echo '    4 - Unsafe SMP processors: SMP with CPUs not designed for SMP.'
echo '    8 - A module was forcibly unloaded from the system by rmmod -f.'
echo '   16 - A hardware machine check error occurred on the system.'
echo '   32 - A bad page was discovered on the system.'
echo '   64 - The user has asked that the system be marked "tainted".  This'
echo '        could be because they are running software that directly modifies'
echo '        the hardware, or for other reasons.'
echo '  128 - The system has died.'
echo '  256 - The ACPI DSDT has been overridden with one supplied by the user'
echo '         instead of using the one provided by the hardware.'
echo '  512 - A kernel warning has occurred.'
echo ' 1024 - A module from drivers/staging was loaded.'
echo
echo https://access.redhat.com/solutions/40594
