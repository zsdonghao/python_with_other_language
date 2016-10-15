

// http://www.swig.org/Doc1.3/SWIG.html#SWIG_adding_member_functions
// http://stackoverflow.com/questions/2676453/swig-wrapping-c-struct

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
//
//
//
// struct dh
// {
//     int x;
//     int y;
//     void (*func)(int);
// };
// extern struct dh DH;
//
// void triple_fn(int a)
// {
//     int dh = 3;
//     printf("dh * %d = %d\n", a, a * dh);
// };
//
// struct dh DH = { 7, 1, triple_fn };
