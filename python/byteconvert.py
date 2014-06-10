#!/usr/bin/env python

import sys

usage = "'byteconvert [SIZE]' where SIZE is a number followed by b, k, m, g, or t. E.g. '1024m'."

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
	if unit == "b":
		bconv(value)
	elif unit == "k":
		kconv(value)
	elif unit == "m":
		mconv(value)
	elif unit == "g":
		gconv(value)
	elif unit == "t":
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
else:
	print usage
