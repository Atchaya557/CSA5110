#include <stdio.h>
#include <string.h>

int main(){
    char text[100], key[100];
    int i, j = 0;

    printf("Enter Plain Text (UPPERCASE): ");
    scanf("%s", text);

    printf("Enter Key (UPPERCASE): ");
    scanf("%s", key);

    int keyLen = strlen(key);

    printf("Encrypted Text: ");

    for(i = 0; text[i] != '\0'; i++){
        char ch = ((text[i] - 'A') + (key[j] - 'A')) % 26 + 'A';
        printf("%c", ch);

        j++;
        if(j == keyLen)
            j = 0;
    }

    return 0;
}

OUTPUT

Enter Plain Text (UPPERCASE): HELLO
Enter Key (UPPERCASE): HILL
Encrypted Text: OMWWV
