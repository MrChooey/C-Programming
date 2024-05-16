#include <stdio.h>

int main(void){
	int num,start,end,sum;
	
	start = 11;
	end = 99;
	sum = 0;

/*	
	num = start;
	while (num <= end){
		if (num%2 == 0){
			sum += num;
		}	
		num++
	}
*/	

	if (num%2 == 1) num++;
	while (num <= end){
		sum += num;
		num += 2;
	}
	
	printf("%d",sum);
	return 0;
}
