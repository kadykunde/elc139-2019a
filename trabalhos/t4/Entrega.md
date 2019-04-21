[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T2

Nome: Ricardo Kunde Schlesner

### Parte 1 - PThreads:

Questões:

#### 1 - 

Particionamento:

O particionamento é onde a tarefa é dividida para ser executada em varias threads, o que é calculado nas seguintes linhas:
	
Aqui se cria vetores (e os preence) baseado na quantia de trabalho e número de threads especificadas nos argumentos do programa.
	
```
	dotdata.a = (double *) malloc(wsize*nthreads*sizeof(double));
	fill(dotdata.a, wsize*nthreads, 0.01);
	dotdata.b = (double *) malloc(wsize*nthreads*sizeof(double));
	fill(dotdata.b, wsize*nthreads, 1.0);
```
	
E aqui, na função dotproduct_worker, é calculado o ponto inicial e final daquela thread, baseado em um offset que muda linearmente entre as threads.
	
```
	int start = offset*wsize;
	int end = start + wsize;
```

	
Comunicação:

Onde uma thread se comunica com a outra para fazer qualquer tipo de sincronização necessario para o processo, nesse caso foi utilizado um join na função dotprod_threads:

```
	for (i = 0; i < nthreads; i++) {
		pthread_join(threads[i], NULL);
	}
```

Aglomeração:

As threads realizam cálculos em dados diferentes para chegar em apenas um resultado, e isso é realizado com uma estrutura global que todas as threads podem acessar atravez de um mutex (para não ocorrer problemas de duplo acesso):

```
	pthread_mutex_lock (&mutexsum);
	dotdata.c += mysum;
	pthread_mutex_unlock (&mutexsum);
```

Mapeamento:

Enquanto que o código de particionamento determina as tarefas de cada thread, o mapeamento é a criação e parametrização dessas, realizadas pelo seguinte código:

```
	threads = (pthread_t *) malloc(nthreads * sizeof(pthread_t));
	pthread_mutex_init(&mutexsum, NULL);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < nthreads; i++) {
		pthread_create(&threads[i], &attr, dotprod_worker, (void *) i);
	}
```

#### 2 - 

Em média (de 10 rodadas de cada configuração), a configuração de 1 thread demorou 5869357 usec, enquanto que a de 2 threads demorou 2949172 usec.
Calculando-se 5869357/2949172 temos 1.9901, concluíndo-se que a configuração de 2 threads tem aproximadamente 199% a velocidade da de 1 thread.

#### 3 -

Analisando os valores demonstrados nas tabelas representadas abaixo na questão número 4, pode-se ver que de 1 para 2 threads se tem o desempenho dobrado, enquanto que de 2 threads para 4 é um aumento de aproximadamente 50%, o que já mostra uma desaceleração.

A mudança de carga tem um efeito bem linear, e as threads continuaram tendo desempenho similar.
Trocar o tamanho de carga e o número de repetições teve resultados proporcionais, o que faz sentido ao se fazer análise do código, já que são 2 for loops.

#### 4 -

Carga total de 1000000:

| tool     | nthreads | size    | repetitions | usec    | speedup | 
|----------|----------|---------|-------------|---------|---------| 
| Pthreads | 1        | 1000000 | 2000        | 6038125 | 1       |
| Pthreads | 2        | 500000  | 2000        | 3053475 | 1.977   |
| Pthreads | 4        | 250000  | 2000        | 1999010 | 1.527   |

Carga total de 10000:

| tool     | nthreads | size    | repetitions | usec    | speedup | 
|----------|----------|---------|-------------|---------|---------|
| Pthreads | 1        | 10000   | 2000        | 58932   | 1       |
| Pthreads | 2        | 5000    | 2000        | 29985   | 1.965   |
| Pthreads | 4        | 2500    | 2000        | 20544   | 1.459   |

#### 5 -

A diferença está nas seguintes linhas:

```
	pthread_mutex_lock (&mutexsum);
	dotdata.c += mysum;
	pthread_mutex_unlock (&mutexsum);
```

Onde na segunda versão se mantém apenas a segunda linha.

Essa mudança abre uma brecha para erros que podem ocorrer quando 2 threads tentam realizar a operação de soma no mesmo instante sobre a memória compartilhada, causando uma das operações a ser sobrescrita.

### Referências
-

