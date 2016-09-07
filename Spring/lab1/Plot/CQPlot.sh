#!/usr/bin/gnuplot
set terminal png size 800,480 enhanced font 'Arial, 18'
set output 'CQResult.png'

set style line 1 linecolor rgb 'red' linetype 1 linewidth 2
set style line 3 linecolor rgb 'green' linetype 1 linewidth 2

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

plot "CountingSort.dat" using 1:2 title "CountingSort" with linespoints ls 1,\
     "QuickSort.dat" using 1:2 title "QuickSort" with linespoints ls 3
