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
	

### Referências
- Top500. HPC4 - Proliant DL380 Gen10. https://www.top500.org/system/179444
- Intel. LINPACK Benchmark. https://software.intel.com/en-us/articles/intel-linpack-benchmark-download-license-agreement

