all: hbbasefont1.ttf hbbasefont2.ttf

%.ttf: %.ufo
	fontforge -script ufo2ttf.py $<