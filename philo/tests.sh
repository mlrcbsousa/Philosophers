#!/bin/bash

echo
echo "== Error output tests =="
./philo 1 1 1 1 1 1
./philo 1 2 3 hh
./philo 1 2 3 -214748
./philo 0 800 200 200

echo
echo "== 1 800 200 200 =="
./philo 1 800 200 200 # Should not eat and die

# ./philo 5 800 200 200 # no one should die

echo
echo "== 5 800 200 200 7 =="
./philo 5 800 200 200 7 # should stop after all have eaten 7 times

# ./philo 4 410 200 200 # no one should die

echo
echo "== 4 310 200 100 =="
./philo 4 310 200 100 # one should die

# ./philo 4 800 200 200
# ./philo 2 60 60 60
# ./philo 4 410 200 200 3
# ./philo 4 410 200 200 5
# ./philo 4 410 200 200 8

# echo "Leaks."
# valgrind --tool=memcheck --leak-check=yes --show-reachable=yes \
# 					--num-callers=20 --track-fds=yes ./philo 4 310 200 100
