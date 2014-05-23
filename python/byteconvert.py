#!/usr/bin/env python

size = ["b", "K", "M", "G"]

print "Enter a number followed immediately by a file size.\n\
Allowed file sizes are b, K, M, and G. For example: '12M'.\n\
Note that binary prefixes are assumed, i.e. 1K = 1024b.\n\
Stop with Ctrl+C, Ctrl+D, or by pulling your computer's power cord."

while 2 > 1:

	num = raw_input("File size> ")

	if num[-1] not in size:
		print "Enter a file size that ends in b, K, M, or G."
	elif num[-1] == "b":
# Convert b to K, M, and G
		print \
num + ' : ' + \
str(float(num[0:-1]) / 1024) + "K" + ' : ' + \
str(float(num[0:-1]) / (1024 ** 2)) + "M" + ' : ' + \
str(float(num[0:-1]) / (1024 ** 3)) + "G"
	elif num[-1] == "K":
# Convert K to b, M, and G
		print \
str(float(num[0:-1]) * 1024) + 'b'  + ' : ' + \
num + ' : ' + \
str(float(num[0:-1]) / 1024) + "M" + ' : ' + \
str(float(num[0:-1]) / (1024 ** 2)) + "G"
	elif num[-1] == "M":
# Convert M to b, K, and G
		print \
str(float(num[0:-1]) * (1024 ** 2)) + 'b'  + ' : ' + \
str(float(num[0:-1]) * 1024) + "K"  + ' : ' + \
num + ' : ' + \
str(float(num[0:-1]) / 1024) + "G"
	elif num[-1] == "G":
# Convert G to b, K, and M
		print \
str(float(num[0:-1]) * (1024 ** 3)) + 'b'  + ' : ' + \
str(float(num[0:-1]) * (1024 ** 2)) + "K"  + ' : ' + \
str(float(num[0:-1]) * 1024) + "M" + ' : ' + \
num
	else:
		print "This is a place holder. Don't look it in the eyes."
