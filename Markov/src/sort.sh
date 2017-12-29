#!/usr/bin/env bash

sort -n -r -k 2 -t " " countdata/fileone.txt > countdata/sortone.txt
sort -n -r -k 2 -t " " countdata/filetwo.txt > countdata/sorttwo.txt
sort -n -r -k 2 -t " " countdata/filethree.txt > countdata/sortthree.txt

