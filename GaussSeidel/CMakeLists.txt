cmake_minimum_required( VERSION 3.10 )

project( gauss )

add_executable( gauss gauss.c gauss_calculate.c gauss_express.c gauss_judge.c gauss_serve.c gauss_substitute.c )

target_link_libraries(gauss m)
