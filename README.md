# rm-decode
Decoder for Register Machines. It decodes any given natural (Gödel) number into its respective RM.

### Register Machines / RM
A detailed explanation for RM dealt with by this program can be found at:

https://www.cl.cam.ac.uk/teaching/1718/CompTheory/lecture-2.pdf

And explanation Gödel encodings:

https://www.cl.cam.ac.uk/teaching/1718/CompTheory/lecture-3.pdf


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
