#include <stdio.h>
#include <string.h>

#define MAX 1000

void decrypt(char word[]){
    int len = strlen(word);
    char temp[MAX];
    for(int i = 1; i <= 25; i++){
        strcpy(temp, word); // copia o original
        for(int j = 0; j < len; j++){
            if (temp[j] >= 'A' && temp[j] <= 'Z'){
                temp[j] = (temp[j] - 'A' + i) % 26 + 'A';
            }
            if(temp[j] >= 'a' && temp[j] <= 'z'){
                temp[j] = (temp[j] - 'a' + i) % 26 + 'a';
            }
        }
        printf("Shift %2d: %s\n", i, temp); // printa o temp
    }
}


int main(){
    char word[MAX], ch;
    int menuChoice;

    printf("=======CEASAR CIPHER DECODER=======\n");
    printf("       1 - DECRYPT\n");
    printf("       2 - QUIT\n");
    scanf("%d", &menuChoice);
    getchar();
    if (menuChoice == 2){
        printf("       Quiting...");
        return 0;
    }
    while(menuChoice != 1 && menuChoice != 2){
        printf("\n       Invalid Option!!\n");
        printf("       1 - DECRYPT\n");
        printf("       2 - QUIT\n");
        scanf("%d", &menuChoice);
        getchar();
    }
    printf("       ENTER A TEXT\n ");
    fgets(word, MAX, stdin);

    printf("\n\n");

    
    word[strcspn(word, "\n")] = '\0';

    decrypt(word);

    printf("     PICK WHAT MAKES SENSE");
    return 0;
}