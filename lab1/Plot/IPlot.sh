#!/usr/bin/gnuplot
set terminal png size 1200,720 enhanced font 'Arial, 18'
set output 'IResult.png'

set style line 2 linecolor rgb 'blue' linetype 1 linewidth 2

set border linewidth 1
set key top left
set grid
set mytics 0
set format y "%.6f"
set xlabel "Number of elements" font "Arial, 18"
set format x "%.0f" 
set ylabel "Execution time (sec)" font "Arial, 18"
set xtics 100000 font "Arial, 14"
set ytics font "Arial, 14"
set rmargin 4
set tmargin 2
set mxtics

plot "ISort.dat" using 1:2 title "InsertionSort" with linespoints ls 2
