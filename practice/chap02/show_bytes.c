#include <stdio.h>
#include <string.h>
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer starter, size_t cnt){
	size_t i;
	for (i = 0; i != cnt; ++i){
		printf("%.2x ", starter[i]);
	}
	putchar(10);
}

void show_int(int x){
	//x is an Integer, we should pass a byte_pointer to f
	show_bytes((byte_pointer) &x, sizeof(int));
}
void show_double(double x){
	//x is an Integer, we should pass a byte_pointer to f
	show_bytes((byte_pointer) &x, sizeof(double));
}
void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}

int main(){
	int i = 10;
	double d = 10;
	printf("int:\n");
	show_pointer(&i);
	show_int(i);

	printf("double:\n");
	show_double(d);
	show_pointer(&d);

	const char *str = "12345";
	show_bytes((byte_pointer)str, strlen(str));
	return 0;
}