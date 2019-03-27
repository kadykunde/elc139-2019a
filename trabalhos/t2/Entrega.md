[Programação Paralela](https://github.com/AndreaInfUFSM/elc139-2018a) > T2

Nome: Ricardo Kunde Schlesner

Parte 1 - PThreads:

Questões:

1 - 
	Particionamento:
	O particionamento é feito na função dotprod_threads, onde são configuradas e criadas threads baseado nos parametros passados como argumentos.
	
	``
	threads = (pthread_t *) malloc(nthreads * sizeof(pthread_t));
	pthread_mutex_init(&mutexsum, NULL);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for (i = 0; i < nthreads; i++) {
	  pthread_create(&threads[i], &attr, dotprod_worker, (void *) i);
	}
	``
	
	Comunicação:
	

### Referências
- Top500. HPC4 - Proliant DL380 Gen10. https://www.top500.org/system/179444
- Intel. LINPACK Benchmark. https://software.intel.com/en-us/articles/intel-linpack-benchmark-download-license-agreement

