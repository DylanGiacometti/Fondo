#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define size 5


char playfairMatrix[5][5]={
    {'e', 's', 'm', 'p', 'i'},
    {'o', 'l', 'a', 'y', 'f'},
    {'r', 'b', 'c', 'd', 'g'},
    {'h', 'k', 'n', 'q', 't'},
    {'u', 'v', 'w', 'x', 'z'}
};

char *formatText(const char *text)
{
    static char result[256]; // Buffer statico per il risultato
    int j = 0;

    // Processa ogni carattere del testo di input
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = tolower(text[i]);
        if (ch >= 97 && ch <= 122)
        {
            result[j++] = ch;
        }
    }
    result[j] = '\0'; // Termina la stringa

    return result;
    
}

void findPosition(char elem, int *row, int *col){
    for(int i = 0; i < size; i++){
        for(int k = 0; k < size; k++){
            if(playfairMatrix[i][k] == elem){
                *row = i;
                *col = k;
            }
        }
    }
}

void encrypt(){
    char messageIn[24];
    printf("Inserisci il messaggio da cifrare:\n");
    fgets(messageIn, sizeof(messageIn), stdin);
    messageIn[strcspn(messageIn, "\n")] = 0;

    const char *message = formatText(messageIn);

    printf("Messaggio: %s\n", message);

    int length = strlen(message);
    char bigram[2];
    int k=0;
    char result[24];
    int variatore = 1;

    for(int i = 0; i < length; i+= variatore){
        //Creo il bigramma
        bigram[0] = message[i];
        if(i + 1 < length && message[i] != message[i+1]){
            bigram[1] = message[i+1];
            variatore = 2;
        } else {
            bigram[1] = 'x';
            variatore = 1;
        }
        //ricavo la posizione delle lettere
        int x1, y1, x2, y2;
        findPosition(bigram[0], &y1, &x1);
        findPosition(bigram[1], &y2, &x2);

        if(y1 == y2){ //Stessa riga
            bigram[0]= playfairMatrix[y1][(x1+1) % size];
            bigram[1]= playfairMatrix[y2][(x2+1) % size];
        } else if(x1 == x2){ //stessa colonna
            bigram[0]= playfairMatrix[(y1+1)%size][x1];
            bigram[1]= playfairMatrix[(y2+1)%size][x2];
        } else { //Rettangolo
            bigram[0]= playfairMatrix[y1][x2];
            bigram[1]= playfairMatrix[y2][x1];
        }
        result[k++]= bigram[0];
        result[k++]= bigram[1];
        }
        result[k] = '\0';
        printf("%s", result);
}




int main(){
    int option;
    char bfr[10];
    printf("Programma per la cifratura di un messagio tramite PlayFair\n");
    printf("Cosa vuoi fare?\n");
    printf("1 - Cifrare\n");
    printf("2 - Decifrare\n");
    printf("3 - Esci dal programma\n");
    fgets(bfr, sizeof(bfr), stdin);
    option = atoi(bfr);
    switch(option){
        case 1:
        encrypt();
        break;
        case 3:
        exit(0);
        break;
        default:
        printf("devi scegliere un opzione\n");
        break;
    }

    return 0;
}