#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5] = {
    {'M','O','N','A','R'},
    {'C','H','Y','B','D'},
    {'E','F','G','I','K'},
    {'L','P','Q','S','T'},
    {'U','V','W','X','Z'}
};

void findPosition(char ch, int *row, int *col){
    if(ch == 'J')
        ch = 'I';

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(matrix[i][j] == ch){
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

int main(){
    char text[100], plain[100], cipher[100];
    int i, j = 0;

    printf("Enter Plain Text (UPPERCASE): ");
    scanf("%s", text);

    for(i = 0; text[i] != '\0'; i++){
        if(text[i] == 'J')
            text[i] = 'I';

        plain[j++] = text[i];

        if(text[i] == text[i+1])
            plain[j++] = 'X';
    }
  
    if(j % 2 != 0)
        plain[j++] = 'X';
  
    plain[j] = '\0';
    int k = 0;
  
    for(i = 0; i < j; i += 2){
        int r1, c1, r2, c2;

        findPosition(plain[i], &r1, &c1);
        findPosition(plain[i+1], &r2, &c2);

        if(r1 == r2){
            cipher[k++] = matrix[r1][(c1 + 1) % 5];
            cipher[k++] = matrix[r2][(c2 + 1) % 5];
        }
        else if(c1 == c2){
            cipher[k++] = matrix[(r1 + 1) % 5][c1];
            cipher[k++] = matrix[(r2 + 1) % 5][c2];
        }
        else{
            cipher[k++] = matrix[r1][c2];
            cipher[k++] = matrix[r2][c1];
        }
    }
    cipher[k] = '\0';
    printf("Encrypted Text: %s\n", cipher);
    return 0;
}

OUTPUT

Enter Plain Text (UPPERCASE): HELLO
Encrypted Text: CFSUPM
