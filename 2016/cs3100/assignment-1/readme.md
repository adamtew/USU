# Serial Mandelbrot

> Create a program that generates images of the Mandelbrot set.  The images are to be produced in the PPM format.  The images may be coloured in any manner desired, but should clearly be the Mandelbrot set.  In addition your program must time the creation of the image and report average and standard deviations of these times.

### The following components should be a generic (re-usable) as possible as they will be used in future assignments.

- A means of timing an arbitrary function (use std::chrono)
- The computation of averages and standard deviations
- The computation of the colour of a pixel in a Mandelbrot image


### Run with

```
cmake .
make
./main
```

### Stats

#### pi 3

```bash
This function took: 3819 milliseconds
This function took: 3819 milliseconds
This function took: 3882 milliseconds
This function took: 3783 milliseconds
This function took: 3960 milliseconds
This function took: 3783 milliseconds
This function took: 3784 milliseconds
This function took: 3783 milliseconds
This function took: 4136 milliseconds
This function took: 3784 milliseconds

Your average was 3853 milliseconds.
With a standard deviation of 109 milliseconds
```

#### Macbook Pro

```bash
This function took: 993 milliseconds
This function took: 943 milliseconds
This function took: 936 milliseconds
This function took: 931 milliseconds
This function took: 937 milliseconds
This function took: 921 milliseconds
This function took: 966 milliseconds
This function took: 956 milliseconds
This function took: 987 milliseconds
This function took: 928 milliseconds

Your average was 949 milliseconds.
With a standard deviation of 23 milliseconds
```