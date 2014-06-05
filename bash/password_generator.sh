#!/bin/bash

FIRST=$(shuf -n 1 /usr/share/dict/words)
NUM=$(( $RANDOM & 100 ))
LAST=$(shuf -n 1 /usr/share/dict/words)

echo ${FIRST}${NUM}${LAST}
