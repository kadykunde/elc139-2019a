[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T7

### Nome: Ricardo Kunde Schlesner

### Parte 1

[sr_bcast](https://github.com/kadykunde/elc139-2019a/blob/master/trabalhos/t7/sr_bcast.c)

|np |t(ms)  |
|---|-------|
|8	|0.6967 |
|16	|0.893	|
|32	|1.2824	|

[mpi_bcast](https://github.com/kadykunde/elc139-2019a/blob/master/trabalhos/t7/mpi_bcast.c)

|np |t(ms)  |
|---|-------|
|8	|0.7351 |
|16	|1.0506	|
|32	|1.4298	|

Analisando os resultados se conclui que para este caso, o send recieve foi um pouco mais rapido.

### Parte 2

[avg](https://github.com/kadykunde/elc139-2019a/blob/master/trabalhos/t7/avg.c)

Os testes abaixo foram feitos com 500 posições(vetor) e 16 processos, variando a latência e a largura da banda.

|bw(Mbps) |lat(ums) |t(ms)  |
|---------|---------|-------| 
|125	    |5        |2.0196 |
|25	      |5        |9.9529 |
|250	    |5	      |1.0279 |
|125	    |10       |2.0558 |
|125	    |50       |2.3459 |
|250	    |50	      |10.2792|




### Referências
- 

