#include <stdio.h>

void print_binary(unsigned int n)
{
    unsigned int i;
    for (i = 1 << 8; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}

int main() {
    int value = 0b10; // 00000001b
	char c = 'c';

	// if (value >> 2 & c)
	// 	printf("true");

    printf("\nInitial value: ");
	print_binary(value);

    // 左に1ビットシフト
    printf("\nShifted value: ");
	print_binary(value<<1);

    // 右に1ビットシフト
    printf("\nShifted value: ");
	print_binary(value>>1);

    return 0;
}
