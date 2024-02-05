for lez in $(seq -w 16 16)
do
	dir=lez${lez}
	cd $dir
	echo "ENTRO IN ${dir}"
	echo "==============="
	rm Makefile
	ln -s ../utils/scripts/Makefile
	files=$(ls [0-9][0-9]*_L.tex [0-9][0-9]*_S[1-3].tex)
	for f in $files
	do
		target=${f%.tex}
		echo make TARGET=$target
		make TARGET=$target
	done
	pdffiles=$(ls *_L.pdf *_S[1-3].pdf)
	num=$(ls [0-9][0-9]*_L.pdf | cut -c 1-2)
	echo pdftk $pdffiles cat output ottimizzazione_${num}.pdf
	pdftk $pdffiles cat output ottimizzazione_${num}.pdf

	# rm -f *.{aux,log,nav,out,snm,toc,pptx,fdb_latexmk,fls,frm,synctex.gz} 
	cd ..
done
pdftk $(find . -name 'ottimizzazione_*' | sort) cat output lucidi_ottimizzazione_lineare.pdf

