# rm-decode
Decoder for Register Machines (RM). It decodes any given natural (Goedel) number into its respective RM.

### Register Machines
A detailed explanation of RM dealt with by this program can be found at:

https://www.cl.cam.ac.uk/teaching/1718/CompTheory/lecture-2.pdf

### Compilation

A makefile is available for use. To compile, simply:
```
make
```
or
```
make all
```

To clean up object and binary files:
```
make clean
```

### Usage

```
./rm_decode [encoding]
```
where [encoding] is the natural number encoding for the RM.