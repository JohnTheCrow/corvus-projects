#!/usr/bin/env python

sen = raw_input("Enter a string: ").replace(" ","")

vwls = 'aeiou'

print "".join(l for l in sen if l not in vwls)
print "".join(l for l in sen if l in vwls) 
