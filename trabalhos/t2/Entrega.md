[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T2

Nome: Ricardo Kunde Schlesner

Parte 1 - PThreads:

Questões:

1 - 
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

### Referências
-

