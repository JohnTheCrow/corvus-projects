#!/usr/bin/env python

from datetime import *
import sys

if len(sys.argv) == 1:
	x = raw_input("Enter an epoch timestamp: ")
	print datetime.fromtimestamp(float(x))
elif len(sys.argv) == 2:
	x = sys.argv[1]
	print datetime.fromtimestamp(float(x))
else:
	print "Enter just one arguement."
