# 0x16. C - Simple Shell

## Resources:books:
Read or Watch:
* [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
* [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
* [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
* [Everything you need to know to start coding your own shell](https://intranet.hbtn.io/concepts/64)

---
## Description
In this project we are tasked with creating our own simple UNIX command interpreter that executes commands from the standard input or from a file.

---
## Instructions:bulb:

- Compiling the program: ```sh gcc -Wall -Werror -Wextra -pedantic *.c -o hsh ```
- Interactive mode:
```sh
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
- Non-interactive mode:
```sh
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

---
## Project requirements

- All your files will be compiled on Ubuntu 14.04 LTS
- Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to

---
## Authors
* [Santigo Peña](https://github.com/santiagopemo/simple_shell)
* [Ricky Mosquera](https://github.com/FabianMosquera)

