[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T2

Nome: Ricardo Kunde Schlesner


### Sequencial

| nthreads | size    | frames    | sec     |
|----------|---------|-----------|---------|
| 1        | 512     | 32        | 9.0630  |
| 1        | 512     | 64        | 17.1561 |
| 1        | 1024    | 32        | 35.8387 |
| 1        | 1024    | 64        | 68.7447 |

Carga total de 10000:

| tool     | nthreads | size    | repetitions | usec    | speedup | 
|----------|----------|---------|-------------|---------|---------|
| Pthreads | 1        | 10000   | 2000        | 58932   | 1       |
| Pthreads | 2        | 5000    | 2000        | 29985   | 1.965   |
| Pthreads | 4        | 2500    | 2000        | 20544   | 1.459   |

### Referências
-

