#include <stdio.h>

int tadd_ok(int x, int y){
	if (x >= 0 && y >= 0){
		if (x + y <= 0){
			return 0;//positive overflow
		}
	}
	else if (x < 0 && y < 0){
		if (x + y => 0){
			return 0;
		}
	}
	return 1;
}

int main(){
	printf("%d\n", tadd_ok(-8, -8));//if run in 4-bit machine,it works

	return 0;
}