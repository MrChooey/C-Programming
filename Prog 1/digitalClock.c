#include <stdio.h>

int main(void){
	int seconds,hour,minutes;
	
	printf("Enter time in seconds: ");
	scanf("%d",&seconds);
	
	hour = seconds / 3600;
	minutes = (seconds - hour*3600) / 60;
	seconds = seconds - hour*3600 - minutes*60;
	
	printf("Time: %02d:%02d:%02d",hour,minutes,seconds);
	
	return 0;
}
