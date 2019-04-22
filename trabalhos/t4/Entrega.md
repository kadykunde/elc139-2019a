[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T4

Nome: Ricardo Kunde Schlesner

Os testes foram feitos em uma maquina virutual com 4 cores.

### Resultados

A seguinte estão os resultados que encontrei, existe uma explicação mais detalhada nos slides.

## Sequencial

| nthreads | size    | frames    | sec     |
|----------|---------|-----------|---------|
| 1        | 512     | 32        | 9.0630  |
| 1        | 512     | 64        | 17.1561 |
| 1        | 1024    | 32        | 35.8387 |
| 1        | 1024    | 64        | 68.7447 |
| 1        | 512     | 128       | 37.0565 |


## Paralelo 1

| nthreads | size    | frames    | sec     | speedup | 
|----------|---------|-----------|---------|---------|
| 2        | 1024    | 32        | 18.2507 | 1.9637  |
| 2        | 1024    | 64        | 35.3685 | 1.9436  |
| 2        | 512     | 128       | 19.4115 | 1.9109  |
| 4        | 1024    | 32        | 10.1261 | 3.5392  |
| 4        | 1024    | 64        | 19.2137 | 3.5779  |
| 4        | 512     | 128       | 10.4096 | 3.5598  |
| 8        | 1024    | 32        | 10.5701 | 3.3905  |
| 8        | 1024    | 64        | 20.5846 | 3.3396  |
| 8        | 512     | 128       | 11.8271 | 3.1332  |


## Paralelo 2

| nthreads | size    | frames    | sec     | speedup | 
|----------|---------|-----------|---------|---------|
| 2        | 1024    | 32        | 18.2507 | 1.9637  |
| 2        | 1024    | 64        |  | 1       |
| 2        | 512     | 128       |  | 1       |
| 4        | 1024    | 32        |  | 1       |
| 4        | 1024    | 64        |  | 1       |
| 4        | 512     | 128       |  | 1       |
| 8        | 1024    | 32        |  | 1       |
| 8        | 1024    | 64        |  | 1       |
| 8        | 512     | 128       |  | 1       |


### Referências
-

