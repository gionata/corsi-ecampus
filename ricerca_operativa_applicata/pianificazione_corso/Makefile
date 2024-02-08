ORIGDIR=$(shell pwd | xargs basename)
TARBALL=$(ORIGDIR).tar.gz

all: ipotesi_pianificazione.pdf clean dist

ipotesi_pianificazione.pdf: ipotesi_pianificazione.tex
	pdflatex ipotesi_pianificazione.tex

clean:
	rm -f *.aux *.log *.toc *.lot *.lof *.loa *.out *~
dist:
	cd ..; \
	tar cvzf $(TARBALL) $(ORIGDIR); \
	rsync -Ravr $(ORIGDIR) /mnt/win/Dropbox/eCampus/corso_RO_LM32/; \
	cd $(ORIGDIR)

