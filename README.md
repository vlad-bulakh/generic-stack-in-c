# Generic stack implementation in C
As the name implies, this is a generic stack implementation in C programming language.  The code is written in ISO C90 and should compile on any C90 compiler.  This stack implementation uses void pointers and has built-in functions for printing the values stored on the stack.  There are also several test cases in the src/Main.c file, which insert/delete integers, doubles, floats, characters, and character strings.

## Compiling
To compile the code on GNU/Linux, simply type:

```
make
```
in the terminal.  If everything went well, you should see the following output:
```
gcc -Wall -Wextra -g -ansi -pedantic src/Stack.c src/Main.c  -o stack
```
and the binary file 'stack' should be created in the same directory.

## Running
To run the compiled code, type
```
./stack
```
in the terminal.  You should then see the output similar to the one below:
```
Stack initialized.

Stack size: 0 
Item pushed onto stack: first 
Item pushed onto stack: third 
Item pushed onto stack: second 
Stack size: 3 


=======================================================
BEGIN PRINTING STACK INFORMATION

Number of items in stack: 3

Item position:		Item value:
-----------------------------------
 0			second
 1			third
 2			first

END PRINTING STACK INFORMATION
=======================================================


Removed item from stack: second 
Removed item from stack: third 
Removed item from stack: first 
Stack size: 0 

Stack destroyed.
```
To run other test cases, simply uncomment them in the src/Main.c file and recompile the program.

## Memory leaks
If used properly, there should not be any memory leaks.  Sample valgrind output:
```
==2480== 
==2480== HEAP SUMMARY:
==2480==     in use at exit: 0 bytes in 0 blocks
==2480==   total heap usage: 95 allocs, 95 frees, 3,348 bytes allocated
==2480== 
==2480== All heap blocks were freed -- no leaks are possible
==2480== 
==2480== For counts of detected and suppressed errors, rerun with: -v
==2480== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```

