[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T10

## Nome: Ricardo Kunde Schlesner e Matheus Zorzo Grisotti

### Ideia do Programa

Nós decidimos incorporar o que aprendemos em computação gráfica junto com os conhecimentos de programação paralela, o programa gera uma ou mais imagens (dependendo do número de frames especificados) de um cubo 3d formado por pontos girando. Por ser um cubo 3d, existe muitos laços de 3 níveis no código, e vimos oportunidade de paralelisação nisso.

Estamos utilizando CUDA, e isso nos da acesso a um alto número de threads,então decidimos implementar a paralelização criação de cada frame, e não separa-los por frames, pois então a paralelização teria efeito idependente da quantia de frames, além de ser mais facil implementação.

### Desempenho
