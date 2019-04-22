[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T4

Nome: Ricardo Kunde Schlesner

## [Programa 1](https://github.com/kadykunde/elc139-2019a/blob/master/trabalhos/t4/fractalpar1.cpp)
## [Programa 2](https://github.com/kadykunde/elc139-2019a/blob/master/trabalhos/t4/fractalpar2.cpp)

### [SLIDES (link google slides)](https://docs.google.com/presentation/d/12o3TLfig8YaOCGtZA9ZDuOd5XQ4EqBn1ItFaJaYqy7Y/edit?usp=sharing)

### Resultados

A seguinte estão os resultados que encontrei, existe uma explicação mais detalhada nos slides.
Os testes foram feitos em uma maquina virutual com 4 cores.

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
| 2        | 1024    | 32        | 17.9742 | 1.9938  |
| 2        | 1024    | 64        | 34.9139 | 1.9689  |
| 2        | 512     | 128       | 18.8152 | 1.9694  |
| 4        | 1024    | 32        | 9.6495  | 3.7140  |
| 4        | 1024    | 64        | 18.3004 | 3.7564  |
| 4        | 512     | 128       | 9.9432  | 3.7268  |
| 8        | 1024    | 32        | 10.4269 | 3.4371  |
| 8        | 1024    | 64        | 20.1127 | 3.4179  |
| 8        | 512     | 128       | 11.9505 | 3.1008  |


### Referências
- National Instruments - OpenMP Internal Control Variables and Environment Variables - http://zone.ni.com/reference/en-XX/help/370051Y-01/cvi/libref/openmpenvironmentvariables/

