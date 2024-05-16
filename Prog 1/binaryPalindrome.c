#include <stdio.h>

int main(void) {
    int number, altNumber;
    int binary = 0;
    int count = 0;
    int position = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    altNumber = number;

    while (altNumber > 0) {
        binary += (altNumber % 2) * position;
        altNumber /= 2;
        position *= 10;
        count++;
    }

    printf("The value of your soul is %d.\n", binary);

    // If binary length is even
    if (count % 2 == 0) {
        int half1, half2;
        position = 1;

        count /= 2;

        for (int j = 0; j < 2; j++) {

            // First Half (reversed)
            if (j == 0) {       
                int reversedBinary = 0;

                for (int i = 0; i < count; i++) {
                    reversedBinary *= 10;
                    if (number % 2) reversedBinary += 1;
                    number /= 2;
                }
                half1 = reversedBinary;
            }

            // Second Half
            else if (j == 1) {
                half2 = 0;
                for (int i = 0; i < count; i++) {
                    half2 += (number % 2) * position;
                    number /= 2;
                    position *= 10;
                }        
            }
        }

        printf("%d - %d\n", half1, half2);

        if (half1 == half2) printf("You are worth my child.");
        else if (half1 != half2) printf("Ahh, you are filty. Be gone.");
    }

    // If binary length is odd
    else {
        int half1, half2, middle;
        position = 1;

        middle = (count / 2) + 1;

        for (int j = 0; j < 2; j++) {
            //1011101 - 93
            // First Half (reversed)
            if (j == 0) {       
                int reversedBinary = 0;

                for (int i = 0; i < middle-1; i++) {
                    reversedBinary *= 10;
                    if (number % 2) reversedBinary += 1;
                    number /= 2;
                }
                half1 = reversedBinary;
                number /= 2;
                printf("%d", number);
            }

            // Second Half
            else if (j == 1) {
                half2 = 0;
                for (int i = 0; i < middle-1; i++) {
                    half2 += (number % 2) * position;
                    number /= 2;
                    position *= 10;
                }        
            }
        }

        if (half1 == half2) printf("You are worth my child.");
        else if (half1 != half2) printf("Ahh, you are filty. Be gone.");
    }

    return 0;
}