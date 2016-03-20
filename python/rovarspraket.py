#!/usr/bin/env python

"""
Take a string and convert it to Rovarspraket. I.e. replace every consonant
with that consonant doubled with an 'o' in between and leave vowels intact.
E.g. 'b' becomes "bob" and "hello" becomes "hohelollolo".

https://www.reddit.com/r/dailyprogrammer/comments/341c03/20150427_challenge_212_easy_r%C3%B6varspr%C3%A5ket/
"""

vowels = 'aeiou'

string_in  = raw_input("Enter a string: ")
string_out = ""

for letter in string_in:
    if letter not in vowels and letter.isalpha():
        letter = letter + 'o' + letter
    string_out += "".join(letter)

print(string_out)
