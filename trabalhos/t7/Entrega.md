[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T5

### Nome: Ricardo Kunde Schlesner

### Parte 1

Substitui a parte que usa send e recieve por 2 funções
A broadcast, que envia toda a matriz inserida na função (servindo como o primeiro send)
e Scatter, que divide e envia segmentos para os outros processos.

[matrix_mult.c](https://github.com/kadykunde/elc139-2019a/blob/master/trabalhos/t6/matrix_mult.c)

### Parte 2

Que nem o artigo "goto considered harmful" de Dijkstra, este artigo argumenta que send/recieve é inadequado para a programação paralela e que se devia utilizar outras alternativas que conseguem ter mais clareza sem perder potencial ou desempenho.
O corpo do artigo é separado em 5 categorias, cada uma trabalha com uma característica onde send/recieve se beneficiaria de ser substituido, onde no começo é apresentado um "mito", e atravez de argumentos se a uma conclusão que invalida tal mito.

Pessoalmente os argumentos me pareciam convincentes, e minha experiencia com esse trabalho se encaixa com o que é dito no artigo, porém eu sinto que não tenho experiencia o bastante para concordar ou não. Consigo imaginar situações onde ter o controle mais "baixo-nivel" que o send/recieve oferecem é benéfico, mas eu também posso dizer o mesmo pro goto.


### Referências
- Send-receive considered harmful https://dl.acm.org/citation.cfm?id=963780

