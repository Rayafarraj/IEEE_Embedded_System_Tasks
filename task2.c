#include <stdio.h>

int ToggleBit(int x, int position)
{
    int answer;
    answer = x ^ (1 << position);
    return answer;
}

int main()
{
    int x = 10;
    int position = 1; 
    printf("Original value: %d\n", x);
    x = ToggleBit(x, position);
    printf("After toggling bit %d: %d\n", position, x);
    return 0;
}
