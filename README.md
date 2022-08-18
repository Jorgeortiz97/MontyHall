# MontyHall

This repository contains the source code for the Monty Hall problem.

I cover this topic [on my blog](https://jorgeortizesc.es/application/montyhall).

## Dependencies

In order to run the following code, you need to have a C compiler; e.g., `gcc`.
On Ubuntu OS, it can be installed by using the following command:

```bash
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install gcc make
```

`make` is optional, but I recommend you to use it.

## Compilation

This program can be easily compiled by using `make`:

```bash
$ make main
gcc -o main main.c
```

## Execution

This program can be executed as follows:

```bash
$ ./main < true / false >
```

The required parameter indicates the simulation strategy to follow in the simulation.

Example:

```bash
$ ./main true
Starting simulation of the Monty Hall problem
.........................................
  - Switch mode:   true
  - #total_rounds: 10000000
  - #won_rounds:   6666242 (66.66%)
.........................................
$ ./main false
Starting simulation of the Monty Hall problem
.........................................
  - Switch mode:   false
  - #total_rounds: 10000000
  - #won_rounds:   3332717 (33.33%)
.........................................
```