#!/usr/bin/env python

"""
For the numbers 1-100 inclusive, if the number is divisible by 3 print fizz,
if the number is divisible by 5 print buzz, if the number is divisible by both
3 and 5 print fizzbuzz, else print the number itself.
"""

nums = range(1,101)

for i in nums:
    if i % 3 == 0 and i % 5 == 0:
        print("fizzbuzz")
    elif i % 3 == 0:
        print("fizz")
    elif i % 5 == 0:
        print("buzz")
    else:
        print(i)
