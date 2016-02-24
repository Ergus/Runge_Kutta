#!/usr/bin/env gnuplot

set terminal pdf
set output "output.pdf"

set title "Runge Kuta orden 2"
set xlabel "t(s)"
set grid

arr="t Susceptible Infectious Recovered"

plot for[i=4:8:2] "data.dat" u 2:i w lines lw 0.25 title word(arr,i/2)