#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 5

// Playfair matrix
char playfairMatrix[5][5] = {
    {'e', 's', 'm', 'p', 'i'},
    {'o', 'l', 'a', 'y', 'f'},
    {'r', 'b', 'c', 'd', 'g'},
    {'h', 'k', 'n', 'q', 't'},
    {'u', 'v', 'w', 'x', 'z'}
};

// Prototipi delle funzioni
void formatText(const char *text, char *result);
void findPosition(char elem, int *row, int *col);
char *vigenereCipher(const char *message);
char *playfairCipher(const char *message);

int main() {
    char messageInput[24];
    char message[24];
    char buffer[4]; // Buffer per le opzioni del menu
    int choice;

    printf("Welcome to C-ypher.\n");

    while (1) { // Loop principale per consentire più operazioni
        // Prompt per il messaggio da cifrare
        printf("Please enter the message you would like to encrypt (max 24 characters):\n");
        fgets(messageInput, sizeof(messageInput), stdin);

        // Rimuove caratteri non alfabetici dal plaintext
        formatText(messageInput, message);

        // Opzioni del menu
        printf("Make your choice, which cipher do you choose?\n");
        printf("1 - Vigenere\n");
        printf("2 - Playfair\n");
        printf("3 - Exit\n");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        char *encryptedMessage = NULL; // Messaggio cifrato

        switch (choice) {
            case 1:
                encryptedMessage = vigenereCipher(message);
                break;
            case 2:
                encryptedMessage = playfairCipher(message);
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                continue; // Ritorna all'inizio del loop
        }

        if (encryptedMessage != NULL) {
            printf("Encrypted message: %s\n", encryptedMessage);
            free(encryptedMessage); // Libera la memoria allocata
        } else {
            printf("Error: Encryption failed.\n");
        }

        // Chiede se continuare o uscire
        printf("Do you want to do something else?\n");
        printf("1 - Yes, please\n");
        printf("2 - No, exit\n");
        fgets(buffer, sizeof(buffer), stdin);
        choice = atoi(buffer);

        if (choice == 2) {
            printf("Goodbye!\n");
            break; // Esce dal loop
        } else if (choice != 1) {
            printf("Invalid choice. Returning to the main menu.\n");
        }
    }

    return 0;
}



// This function processes the input text, removing non-alphabetic characters and converting the text to lowercase
void formatText(const char *text, char *result) {
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = tolower(text[i]);
        if (ch >= 'a' && ch <= 'z') { // Only alphabetic letters
            result[j++] = ch;
        }
    }
    result[j] = '\0';
}

// This function searches for the position (row and column) of a given letter in the Playfair matrix
void findPosition(char elem, int *row, int *col) {
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            if (playfairMatrix[i][k] == elem) {
                *row = i;
                *col = k;
            }
        }
    }
}

// This function encrypts the given message using the Vigenère cipher
// The key is taken from user input, and the message is processed with that key
char *vigenereCipher(const char *message) {
    char keyInput[24];
    printf("Enter the key to be used for encryption (max 24 characters):\n");
    fgets(keyInput, sizeof(keyInput), stdin);

    // Rimuove il carattere '\n', se presente
    keyInput[strcspn(keyInput, "\n")] = 0;

    // Rimuove i caratteri non alfabetici dalla chiave
    char key[24];
    formatText(keyInput, key);

    // Controlla se la chiave è valida
    if (strlen(key) == 0) {
        printf("Invalid key, it must contain at least one alphabetic character.\n");
        return NULL;
    }

    // Alloca dinamicamente la memoria per il messaggio cifrato
    char* encryptedMessage = malloc(strlen(message) + 1);
    if (encryptedMessage == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    int keyLength = strlen(key);

    for (int i = 0; i < strlen(message); i++) {
        const int messageCharCode = message[i] - 'a';
        const int keyCharCode = key[i % keyLength] - 'a';
        const char encryptedChar = (messageCharCode + keyCharCode) % 26 + 'a';
        encryptedMessage[i] = encryptedChar;
    }
    encryptedMessage[strlen(message)] = '\0'; // Termina la stringa

    return encryptedMessage;
}

// This function encrypts the given message using the Playfair cipher
// It handles the creation of bigrams and encryption based on the Playfair matrix
char *playfairCipher(const char *message) {
    int length = strlen(message);
    char bigram[2];
    int k = 0;
    int pairLength = 1;

    // Alloca dinamicamente la memoria per il messaggio cifrato
    char* encryptedMessage = malloc(length * 2 + 1); // Ogni bigramma produce 2 caratteri
    if (encryptedMessage == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }

    for (int i = 0; i < length; i += pairLength) {
        // Create the bigk+1ram
        bigram[0] = message[i];
        if (i + 1 < length && message[i] != message[i + 1]) {
            bigram[1] = message[i + 1];
            pairLength = 2;
        } else {
            bigram[1] = 'x';
            pairLength = 1;
        }

        // Retrieve the position of the letters
        int x1, y1, x2, y2;
        findPosition(bigram[0], &y1, &x1);
        findPosition(bigram[1], &y2, &x2);

        if (y1 == y2) { // Same row
            bigram[0] = playfairMatrix[y1][(x1 + 1) % size];
            bigram[1] = playfairMatrix[y2][(x2 + 1) % size];
        } else if (x1 == x2) { // Same column
            bigram[0] = playfairMatrix[(y1 + 1) % size][x1];
            bigram[1] = playfairMatrix[(y2 + 1) % size][x2];
        } else { // Rectangle
            bigram[0] = playfairMatrix[y1][x2];
            bigram[1] = playfairMatrix[y2][x1];
        }

        encryptedMessage[k++] = bigram[0];
        encryptedMessage[k++] = bigram[1];
    }
    encryptedMessage[k] = '\0'; // Termina la stringa

    return encryptedMessage;
}

