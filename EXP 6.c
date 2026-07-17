#include <stdio.h>

int main()
{
    int a, b;

    for(a = 1; a < 26; a++)
    {
        if(a % 2 == 0 || a == 13) // valid values of a
            continue;

        b = (1 - (a * 4)) % 26;
        if(b < 0)
            b += 26;

        if((a * 19 + b) % 26 == 20)
        {
            printf("Key found:\n");
            printf("a = %d\n", a);
            printf("b = %d\n", b);
            break;
        }
    }

    return 0;
}

OUTPUT

Key found:
a = 3
b = 15
