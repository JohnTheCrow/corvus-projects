#!/usr/bin/env python

import sys

usage = "\
Usage:\n\
'byteconvert [SIZE][UNIT_letter]' :: Example: byteconvert 2048G\n\
'byteconvert [SIZE] [UNIT_word]' :: Example: byteconvert 500 megabytes\n\
[UNIT_word] can be one of: k, kilo, kb, kib, kilobytes, m, mb, mib,\n\
megabytes, g, gig, gb, gib, gigabytes, t, tb, tib, terabytes.\n\
'byteconvert'. Then, File size> '[UNIT_letter]'\
"

bytes = ['b', 'bytes']
kilobytes = ['k', 'kilo', 'kb', 'kib', 'kilobytes']
megabytes = ['m', 'mb', 'mib', 'megabytes']
gigabytes = ['g', 'gig', 'gb', 'gib', 'gigabytes']
terabytes = ['t', 'tb', 'tib', 'terabytes']

def bconv(value): #Convert bytes to KiB, MiB, GiB, TiB
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB" % \
	(value, value / 1024, value / (1024 ** 2), value / (1024 ** 3), value / (1024 ** 4))

def kconv(value): #Convert KiB to bytes, MiB, GiB, TiB
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB" % \
	(value * 1024, value, value / 1024, value / (1024 ** 2), value / (1024 ** 3))

def mconv(value): #Convert MiB to bytes, KiB, GiB, TiB
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB" % \
	(value * (1024 ** 2), value * 1024, value, value / 1024, value / (1024 **2))

def gconv(value): #Convert GiB to bytes, KiB, MiB, TiB
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB" % \
	(value * (1024 ** 3), value * (1024 ** 2), value * 1024, value, value / 1024)

def tconv(value): #Convert TiB to bytes, KiB, MiB, GiB
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB" % \
	(value * (1024 ** 4), value * (1024 ** 3), value * (1024 ** 2), value * 1024, value)

def determine_unit():
	if unit in bytes:
		bconv(value)
	elif unit in kilobytes:
		kconv(value)
	elif unit in megabytes:
		mconv(value)
	elif unit in gigabytes:
		gconv(value)
	elif unit in terabytes:
		tconv(value)
	else:
		print usage

def is_number(s): #Tests if a string is a number
	try:
		float(s)
		return True
	except ValueError:
		return False

if len(sys.argv) == 1: #Only the command was entered
	data = raw_input("File size: ")
	if is_number(data[0:-1]) == True:
		value = float(data[0:-1])
		unit = data[-1].lower() #Make sure unit is lowercase
		determine_unit()
	else:
		print usage
elif len(sys.argv) == 2: #One argument was given
	data = sys.argv[1]
	if is_number(data[0:-1]) == True:
		value = float(data[0:-1])
		unit = data[-1].lower()
		determine_unit()
	else:
		print usage
elif len(sys.argv) == 3: #Unit given separately
	if is_number(sys.argv[1]) == True:
		value = float(sys.argv[1])
		unit = sys.argv[2].lower()
		determine_unit()
	else:
		print usage
else:
	print usage
