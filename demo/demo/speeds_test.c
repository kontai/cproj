#include<stdio.h>
#include<stdlib.h>
int main() {
	time_t start_time, end_time;
	double elapsed_time;
	double x, y, pi;
	long i, total;
	total = 0;
	srand((unsigned)time(0));
	time(&start_time);
	for (i = 0; i < 20000000; i++) {
		x = rand() / (double)(RAND_MAX);
		y = rand() / (double)(RAND_MAX);
		if (sqrt(x * x + y * y) < 1) {
			total += 1;
		}
	}
	pi = 4.0 * total / 20000000;
	time(&end_time);
	elapsed_time = difftime(end_time, start_time);
	printf(" total = %d, pi = %f, time = %f", total, pi, elapsed_time);
}