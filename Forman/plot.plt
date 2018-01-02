# !/usr/local/bin/gnuplot


set size square
set xrange [0:1000]
set yrange [0:3000]
set xlabel 'F1'
set ylabel 'F2'

plot 'A.txt' w p ls 7, 'I.txt' w p ls 9, 'U.txt' w p ls 11, 'E.txt' w p ls 13, 'O.txt' w p ls 5
