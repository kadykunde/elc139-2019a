#include <algorithm>
#include <iostream>
#include <string>
//#include <thread>
//#include <mutex>
#include <omp.h>

class SharedArray {
private:
	char* array;
	int index;
	int size;
public:
	SharedArray(int n) : size(n), index(0) {
		array = new char[size];
		std::fill(array, array + size, '-');
	}
	~SharedArray() {
		delete[] array;
	}
	void addChar(char c) {
#pragma omp critical
		{
			array[index] = c;
			spendSomeTime();
			index++;
		}
	}
	void addCharNoMutex(char c) {
		array[index] = c;
		spendSomeTime();
		index++;
	}
	int countOccurrences(char c) {
		return std::count(array, array + size, c);
	}
	std::string toString() {
		return std::string(array, size);
	}
private:
	void spendSomeTime() {
		for (int i = 0; i < 10000; i++) {
			for (int j = 0; j < 100; j++) {
				// These loops shouldn't be removed by the compiler
			}
		}
	}
};


class ArrayFiller {
private:
	static const int nTimes = 60;
	SharedArray* array;
	int chunkSize = 5;
	int config;
public:
	ArrayFiller(int mode) {
		config = mode;
		array = new SharedArray(nTimes);
	}
	void fillArrayConcurrently() {
		switch(config){
			case 1: {
#pragma omp parallel for schedule(static, chunkSize)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 2: {
#pragma omp parallel for schedule(static)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 3: {
#pragma omp parallel for schedule(dynamic)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 4: {
#pragma omp parallel for schedule(dynamic, chunkSize)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 5: {
#pragma omp parallel for schedule(guided)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 6: {
#pragma omp parallel for schedule(guided, chunkSize)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
			}
			case 7: {
#pragma omp parallel for schedule(runtime)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 8: {
#pragma omp parallel for schedule(auto)
				for (int i = 0; i < nTimes; i++) {
					array->addChar('A' + omp_get_thread_num());
				}
				break;
			}
			case 9: {
#pragma omp parallel for schedule(auto)
				for (int i = 0; i < nTimes; i++) {
					array->addCharNoMutex('A' + omp_get_thread_num());
				}
				break;
			}
		}
		/*std::thread t[nThreads];
		for (int i = 0; i < nThreads; ++i)
			t[i] = std::thread(&ArrayFiller::run, this, 'A' + i);
		for (int i = 0; i < nThreads; ++i)
			t[i].join();*/
	}
	void printStats() {
		std::cout << array->toString() << std::endl;
		for (int i = 0; i < 3; ++i)
			std::cout << (char)('A' + i) << "="
			<< array->countOccurrences('A' + i) << " ";
		std::cout << std::endl;
	}
	~ArrayFiller() {
		delete array;
	}
};


int main() {
	omp_set_num_threads(3);
	std::cout << "Each thread should add its char to the array n times (n=20)" << std::endl;
	std::cout << "Correct results should total exactly nThreads*nTimes chars" << std::endl;
	std::cout << "Case 1: static, chunk" << std::endl;
	ArrayFiller m1(1);
	m1.fillArrayConcurrently();
	m1.printStats();

	std::cout << "Case 2: static" << std::endl;
	ArrayFiller m2(2);
	m2.fillArrayConcurrently();
	m2.printStats();

	std::cout << "Case 3: dynamic, chunk" << std::endl;
	ArrayFiller m3(3);
	m3.fillArrayConcurrently();
	m3.printStats();

	std::cout << "Case 4: dynamic" << std::endl;
	ArrayFiller m4(4);
	m4.fillArrayConcurrently();
	m4.printStats();

	std::cout << "Case 5: guided, chunk" << std::endl;
	ArrayFiller m5(5);
	m5.fillArrayConcurrently();
	m5.printStats();

	std::cout << "Case 6: guided" << std::endl;
	ArrayFiller m6(6);
	m6.fillArrayConcurrently();
	m6.printStats();

	std::cout << "Case 7: dynamic" << std::endl;
	ArrayFiller m7(7);
	m7.fillArrayConcurrently();
	m7.printStats();

	std::cout << "Case 8: auto" << std::endl;
	ArrayFiller m8(8);
	m8.fillArrayConcurrently();
	m8.printStats();

	std::cout << "Case 9: auto, no mutex" << std::endl;
	ArrayFiller m9(9);
	m9.fillArrayConcurrently();
	m9.printStats();
}