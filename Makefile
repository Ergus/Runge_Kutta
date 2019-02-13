CC:= gcc

all: main.x

main.x: main.cc
	${CC} $< -o $@

.PHONY: clean test graph

clean:
	rm -rf *.x *.pdf *.dat

test: main.x
	./$<

data.dat: main.x
	./$< > $@

graph: data.dat
	./gnuplot.plt
