DOC = relatorio
all: $(DOC).pdf

$(DOC).pdf:
	pdflatex $(DOC).tex
	bibtex $(DOC)
	pdflatex $(DOC).tex
	pdflatex $(DOC).tex

clean:
	rm -f $(AUX_FILES)

AUX_FILES = $(wildcard *.aux *.log *.bbl *.blg *.out)
