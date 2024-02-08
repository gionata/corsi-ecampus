#!/usr/bin/env bash

DIRS=$(ls -d [0-9]*)
for d in $DIRS
do
	echo == Analisi directory $d ==
	cd $d
	DOCS=$(ls *.doc)
	for doc in $DOCS
	do
			echo inizio conversione $doc
			time soffice --headless --convert-to docx $doc
			echo fine conversione $doc
	done
	cd ..
done
