for d in $(find -maxdepth 1 -name 'lez[01][0-9]' | sort)
do
	dir=$(basename $d)
	cd $dir
	rm -f *.{aux,log,nav,out,snm,toc,pptx,fdb_latexmk,fls,frm,synctex.gz} 
	cd ..
done
