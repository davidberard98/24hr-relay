#How to compile this stuff

1. Make sure main.pro is correct & has everything you need
2. "qmake"
3. "make"

#Time

timeTest.cpp: compile with
```
g++ -std=c++11 timeTest.cpp -o timeTest
```

We could use clock() which just measures elapsed processor clock cycles... __BUT__
Processor elapsed clock cycles does not contain time when the program was waiting,
eg between any calculations being done.

Instead we're going to have to use this stupid [chrono](http://www.cplusplus.com/reference/chrono/) thing.
