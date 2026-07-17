#include <stdio.h>
#include <string.h>

int main(){
    char text[100];
    int a, b, i;

    printf("Enter Plain Text (UPPERCASE): ");
    scanf("%s", text);

    printf("Enter value of a: ");
    scanf("%d", &a);

    printf("Enter value of b: ");
    scanf("%d", &b);

    printf("Encrypted Text: ");

    for(i = 0; text[i] != '\0'; i++)
    {
        char ch = ((a * (text[i] - 'A') + b) % 26) + 'A';
        printf("%c", ch);
    }

    return 0;
}

OUTPUT

Enter Plain Text (UPPERCASE): HELLO
Enter value of a: 5
Enter value of b: 8
Encrypted Text: RCLLA
