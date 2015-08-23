#!/usr/bin/env python

import sys

usage = "Usage: 'byteconvert {size}{unit}' where {unit} is one of b, k, m, g, t, p (pages), or h (huge pages).\n\
Example: 'byteconvert 123m'"

bytes = 'b'
kilobytes = 'k'
megabytes = 'm'
gigabytes = 'g'
terabytes = 't'
pages = 'p'
huge_pages = 'h'

def bconv(value): #Convert bytes to KiB, MiB, GiB, TiB, pages, huge pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)" % \
	(value, value / 1024, value / (1024 ** 2), value / (1024 ** 3), value / (1024 ** 4), value / 4096, value / 2097152) 

def kconv(value): #Convert KiB to bytes, MiB, GiB, TiB, pages, huge pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)"   % \
	(value * 1024, value, value / 1024, value / (1024 ** 2), value / (1024 ** 3), value / 4, value / 2048)

def mconv(value): #Convert MiB to bytes, KiB, GiB, TiB, pages, huge pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)"   % \
	(value * (1024 ** 2), value * 1024, value, value / 1024, value / (1024 **2), value * 256, value / 2)

def gconv(value): #Convert GiB to bytes, KiB, MiB, TiB, pages, huge pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)"   % \
	(value * (1024 ** 3), value * (1024 ** 2), value * 1024, value, value / 1024, value * 262144, value / (2.0 / 1024.0))

def tconv(value): #Convert TiB to bytes, KiB, MiB, GiB, pages, huge pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)"   % \
	(value * (1024 ** 4), value * (1024 ** 3), value * (1024 ** 2), value * 1024, value, value * 268435456, value / (2.0 / (1024.0 ** 2)))

def pconv(value): #Convert pages to bytes, KiB, MiB, GiB, TiB, huge pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)"   % \
	(value * 4096, value * (4096 / 1024), value * (4096.0 / (1024.0 ** 2)), value * (4096.0 / (1024.0 ** 3)), value * (4096.0 / (1024.0 ** 4)), value, value / 512)

def hconv(value): #Convert huge pages to bytes, KiB, MiB, GiB, TiB, pages
	print "%.2f B : %.2f KiB : %.2f MiB : %.2f GiB : %.2f TiB\n%d pages (rounded down) : %d huge pages (rounded down)"   % \
	(value * 2097152, value * 2048, value * 2, value * (2.0 / 1024.0), value * (2.0 / (1024.0 ** 2)), value * 512, value)

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
	elif unit in pages:
		pconv(value)
	elif unit in huge_pages:
		hconv(value)
	else:
		print usage

def is_number(s): #Tests if a string is a number
	try:
		float(s)
		return True
	except ValueError:
		return False

if len(sys.argv) == 2:
	data = sys.argv[1]
	if is_number(data[0:-1]) == True:
		value = float(data[0:-1])
		unit = data[-1].lower()
		determine_unit()
	else:
		print usage
else:
	print usage
