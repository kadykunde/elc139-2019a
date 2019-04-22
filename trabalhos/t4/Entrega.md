[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T2

Nome: Ricardo Kunde Schlesner


### Sequencial

| nthreads | size    | frames    | sec     |
|----------|---------|-----------|---------|
| 1        | 512     | 32        | 9.0630  |
| 1        | 512     | 64        | 17.1561 |
| 1        | 1024    | 32        | 35.8387 |
| 1        | 1024    | 64        | 68.7447 |

Analisando os valores sequenciais, pode-se ver que aumentar a quantia de frames faz o tempo de processamento crescer de forma aproximadamente relativa (com um pouco de vantagem para quantias maiores de frames) enquanto que o tamanho tem efeito dobrado no tempo, o que faz sentido considerando que a imagem é quadrada, quando eu dobro a resolução de uma imagem, a quantia de pixeis quadriplica.

### Sequencial

| nthreads | size    | frames    | sec     | speedup | 
|----------|---------|-----------|---------|---------|
| 1        | 512     | 32        | 9.0630  | 1       |
| 1        | 512     | 64        | 17.1561 | 1       |
| 1        | 1024    | 32        | 35.8387 | 1       |
| 1        | 1024    | 64        | 68.7447 | 1       |


### Referências
-

