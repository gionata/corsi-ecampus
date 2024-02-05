for f in $(find . -name [0-1][0-9]*.tex)
do
	if grep -q ecampus_lm32_red $f
	then
		sed -i -e 's/ecampus_lm32_red/savoia_benincasa/' $f
	fi
done

