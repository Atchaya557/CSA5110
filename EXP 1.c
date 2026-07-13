#include <stdio.h>
#include <string.h>

int main(){
    char text[100];
    int key, i;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    for(i = 0; text[i] != '\0'; i++){
        if(text[i] >= 'A' && text[i] <= 'Z')
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        else if(text[i] >= 'a' && text[i] <= 'z')
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
    }

    printf("Encrypted Text: %s", text);

    return 0;
}

OUTPUT:

Enter text: Hello
Enter key (1-25): 3
Encrypted Text: Khoor
