#include <stdio.h>

int uadd_ok(unsigned int x, unsigned int y){
	unsigned sum = x + y;
	if (sum > x && sum && y){
		return 1;
	}
	return 0;
}

int main(){
	printf("%d\n", uadd_ok(2155555555,2155555555));

	return 0;
}