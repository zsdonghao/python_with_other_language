# Build a python module with SWIG

## Tutorial
Basic:

* [Unix-English](http://www.swig.org/tutorial.html)
* [Uinx-Chinese](http://www.swig.org/translations/chinese/tutorial.html)
* [Mac-English](http://www.dabeaz.com/cgi-bin/wiki.pl?SwigFaqMaxOSXSharedLibraries)

More:

* [Pass numpy to C](http://stackoverflow.com/questions/5862915/passing-numpy-arrays-to-a-c-function-for-input-and-output)


## Example Script
* example.c : the C codes
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

# Create <example.o>, <example.py>, <example_wrap.o>
unix % gcc -c example.c example_wrap.c \
      -I/usr/local/include/python2.1 

# Link assembly file using ld, create _example.so
unix % ld -shared example.o example_wrap.o -o _example.so
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
>>> example.fact(5)
120
>>> example.my_mod(7,3)
1
>>> example.get_time()
'Sun Feb 11 23:01:07 1996'
>>>
```
