#include <stdio.h>
#include <string.h> 

#define MAX 1000 // maximum length for the text

void encrypt(char text[], int key){
    int len = strlen(text); // measure the length of the string excluding the \0 char
    for(int i = 0; i < len; i++){
        if(text[i] >= 'A' && text[i] <= 'Z'){
            /*this line transform the letter in another one, using the key provided by the user, the first part calculates how many characters ahead of 'A' the current letter is in the ASCII table .The modulo it's useful in case the character goes past Z , returning back to A. Finally, the '+ A' shifts the number back into the uppercase alphabet range of the ASCII table.    */
            text[i] =(text[i] - 'A' + key ) % 26 + 'A'; 
        }
        else if (text[i] >= 'a' && text[i] <= 'z'){
            text[i] = (text[i] - 'a' + key ) % 26 + 'a';
        }
    }
    printf("\n2    ENCRYPTED TEXT: \n\n");
    printf("%s\n\n", text);
}


int main(){
    int choice;

    printf("==========================CAESAR CIPHER==============================\n\n");
    do{
        char text[MAX];
        int key;
        printf("    INSERT A TEXT (1000 characters maximum)\n\n");
        fgets(text, MAX, stdin);

        int ch;
        //clear any leftover characters in the input buffer 
        while((ch = getchar() != '\n' && ch != EOF));
        
        text[strcspn(text, "\n")] = '\0'; // replace the \n character with \0
        

        printf("\n\n");
        printf("    CHOOSE A KEY\n\n ");
        printf("    KEY:    ");
        scanf("%d", &key);
        getchar();
        
        key = ((key % 26) + 26) % 26; // if the user choose a negative number it will be converted to positive with this expression

        encrypt(text, key);
        
        
        
        printf("    1 - ENCRYPT NEW TEXT\n"); // return menu
        printf("    2 - QUIT\n");
        scanf("%d", &choice);
        getchar();
        while (choice != 1 && choice != 2){
            printf("    Type an valid option!\n");
            scanf("%d", &choice);
        }
        if (choice == 2){
            printf("    Quitting...");
            return 0;            
        }


        printf("\n\n");

    }while (choice == 1);

    return 0;
}