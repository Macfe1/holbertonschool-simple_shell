# Simple Shell

## Description

The Simple Shell is a basic command-line interpreter designed to provide fundamental shell functionalities. It allows users to execute commands, manage processes, and navigate the filesystem.

## Prerequisites

### To dowland the shell you should clone the repository like this:

`git clone git@github.com:Macfe1/holbertonschool-simple_shell.git`

This will create a local copy of the repository on your machine.


### To compile the shell, use GCC compiler with the following command:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

# How it works?

## Interactive mode

To start the shell in interactive mode lets run the executable file like this:

* `./hsh`

To use a comand in the shell use:

* `#cisfun /bin/ls`
* `#cisfun ls`

To start the shell in non-interactiveinteractive mode lets run the executable file like this:

* `echo "/bin/ls" | ./hsh`
* `cat test_ls_2 | ./hsh`

To exit the shell use:

* Ctrl + C
* Ctrl + D
* exit in interactive mode

## Updating the Authors File

To update the list of contributors, execute the following command from the root of the project

./generate-authors.sh

This will generate or update the `AUTHORS` file in the repository root with all the names and emails of the contributors, in alphabetical order.

