#!/bin/bash

img_dir=images_for_pptx
lez=$(ls *.tex)
lez=${lez%.tex}
echo ${lez}
rm -f *.{aux,log,nav,out,snm,toc}
if [ ! -d ${img_dir} ]
then
	mkdir ${img_dir}
else
	rm -f ${img_dir}/*
fi
pdflatex ${lez}
pdflatex ${lez}
rm -f *.{aux,log,nav,out,snm,toc}
cd ${img_dir}
pdftocairo -png ../${lez}.pdf
cd ..
python2 pptx_convert.py ${lez}