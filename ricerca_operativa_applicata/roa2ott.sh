for f in $(find . -name metadata_lesson.tex)
do
	if grep -q "Ricerca Operativa Applicata" $f
	then
		sed -i -e 's/Ricerca Operativa Applicata/Ottimizzazione/' $f
	fi
done

