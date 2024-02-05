for n in `seq 1 8`
do
	convert schermata${n}.png -crop 1366x634+0+0 schermata_${n}.cropped.png
done
