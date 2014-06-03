#!/usr/bin/env python

from datetime import *

x = raw_input("Enter an epoch timestamp: ")
print datetime.fromtimestamp(float(x))
