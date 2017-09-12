#include <stdio.h>
#include <limits.h>
// int tsub_ok(int x, int y){
// 	int sub = x - y;
// 	//if x is pos, y is neg, sub is pos.
// 	int pos_overflow = !(x & INT_MAX) && (y & INT_MAX) && !(sub & INT_MAX);
// 	//if x is neg, y is pos, sub is neg.
// 	int neg_overflow = (x & INT_MAX) && !(y & INT_MAX) && (sub & INT_MAX);

// 	//if pos_overflow or neg_overflow gets 0, return 0;
// 	return ....
// }

int tsub_ok(int x, int y){
	//consider special situation
	if (y < 0 && -y < 0){
		//y is TMin
		return x <= 0;
	}
	return tadd_ok(x, -y);
}

int main(){
	
	return 0;
}