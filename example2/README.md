# Build a python module with SWIG

## Tutorial
Basic:

* [Unix-English](http://www.swig.org/tutorial.html)
* [Unix-Chinese](http://www.swig.org/translations/chinese/tutorial.html)
* [Mac-English](http://www.dabeaz.com/cgi-bin/wiki.pl?SwigFaqMaxOSXSharedLibraries)

More:

* [Pass numpy to C](http://stackoverflow.com/questions/5862915/passing-numpy-arrays-to-a-c-function-for-input-and-output)


**Structure:**

* [**SWIG adding member functions**](http://www.swig.org/Doc1.3/SWIG.html#SWIG_adding_member_functions)


## Example Script
* example_struct_with_fn : an example to implement function in C struct
* example.c : the C codes
* example.h : the C codes
* example.i : the I/O definition

## Convert C to python module

* Install SWIG
 * For Mac
 * For ubuntu


* Build example.so


```
For Linux:
# Create <example_wrap.c>
unix % swig -python example.i     
       (for py3: swig -python -py3 jetson_led.i)

# Create <example.o>, <example.py>, <example_wrap.o>
unix % gcc -c example.c example_wrap.c \
      -I/usr/local/include/python2.1 
      (for tk1/tx1 gcc -c example.c example_wrap.c -O2 -fPIC -I/usr/include/python2.7)

# Link assembly file using ld, create _example.so
unix % ld -shared example.o example_wrap.o -o _example.so
      (for tk1/tx1 ld -shared example.o example_wrap.o -L/usr/lib -o _example.so)
```


```
For Mac:
export C_INCLUDE_PATH=/System/Library/Frameworks/Python.framework/Headers  

swig -python example.i

cc -c `python-config --cflags` example.c example_wrap.c

cc -bundle `python-config --ldflags` example.o example_wrap.o -o _example.so
```


## Test

In the end, you only need to keep 2 files :

- _example.so
- example.pyc

```
>>> import example
>>> a = example.Vector(1,1,1)
>>> a.magnitude()
1.7320508075688772
>>> a.sum()
3.0
>>> a.distance(2,2,2)
1.7320508075688772
>>> a.distance(1,1,1)
0.0
>>> a.printinfo()
Vector [1, 1, 1]
>>>
```

To test c code only :

```
gcc -o example example.c
```
