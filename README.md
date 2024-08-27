# Simple Shell

## Description

The Simple Shell is a basic command-line interpreter designed to provide fundamental shell functionalities. It allows users to execute commands, manage processes, and navigate the filesystem.

### Prerequisites

To compile the shell, use GCC compiler with the following command:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## How it works?

To start the shell lets run the executable file like this:

* ./hsh

To use a comand in the shell use:

* #cisfun /bin/ls
* #cisfun ls

To exit the shell use:

* Ctrl + C
* Ctrl + D

## Updating the Authors File

To update the list of contributors, execute the following command from the root of the project

./generate-authors.sh

This will generate or update the `AUTHORS` file in the repository root with all the names and emails of the contributors, in alphabetical order.

>>>>>>> origin
