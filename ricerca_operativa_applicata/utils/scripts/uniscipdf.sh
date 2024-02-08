#!/bin/sh

pdffiles=$(ls *_L.pdf *_S[1-3].pdf)
num=$(ls [0-9][0-9]*_L.pdf | cut -c 1-2)
pdfjoin $pdffiles -o  INIM13_1099A_${num}.pdf
#rsync 

