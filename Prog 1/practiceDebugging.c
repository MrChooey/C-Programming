#include <stdio.h>

int main(){
    int sec, hou, min;

    printf("Enter the time in seconds: ");
    scanf("%d", &sec);

    hou = sec/3600;
    min = (sec - hou*3600)/60;
    sec = sec - hou*3600 - min*60;
    printf("Time in hours, minutes, and seconds: %02d:%02d:%02d", hou, min, sec);
    
    return 0;
}
