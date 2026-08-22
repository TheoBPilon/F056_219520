DOC = relatorio

AUX_FILES = $(wildcard *.aux *.log *.bbl *.blg *.out)

all: $(DOC).pdf

$(DOC).pdf: $(DOC).tex referencias.bib
	pdflatex $(DOC).tex
	bibtex $(DOC)
	pdflatex $(DOC).tex
	pdflatex $(DOC).tex

clean:
	rm -f $(AUX_FILES)
