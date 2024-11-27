#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void formatText(const char *text, char *result)
{
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        char ch = tolower(text[i]);
        if (ch >= 'a' && ch <= 'z') // Only alphabetic letters
        {
            result[j++] = ch;
        }
    }
    result[j] = '\0';
}

void encrypt(const char *message, const char *key, char *encryptedMessage)
{
    for (int i = 0; i < strlen(message); i++)
    {
        // Get a 0-25 number from char of message and key
        const int codeCharMessage = message[i] - 'a';
        const int codeCharKey = key[i % strlen(key)] - 'a'; // Fix here: use the length of the key

        // Binary sum (XOR for bitwise addition without carry)
        int sum = codeCharMessage ^ codeCharKey;          // XOR: somma dei bit senza riporto
        int carry = (codeCharMessage & codeCharKey) << 1; // AND per calcolare il riporto

        // Add carry until there is no carry
        while (carry != 0)
        {
            int newSum = sum ^ carry;   // XOR for addition without carry
            carry = (sum & carry) << 1; // AND for calculating new carry
            sum = newSum;
        }

        // Convert result to an alphabetical index, and store in encryptedMessage
        encryptedMessage[i] = (sum % 26) + 'a';
    }
    encryptedMessage[strlen(message)] = '\0'; // Ensure the message is null-terminated
}

int main()
{
    int option;
    char buffer[100]; // Increased buffer size to handle larger inputs
    char plaintext[24]; // Array to store the plaintext
    char key[24]; // Array to store the key
    char encryptedMessage[24]; // Array to store the encrypted message

    printf("Welcome to a Vigenere cipher variant, producing the same result with binary calculation\n");
    printf("What do you want to do?\n");
    printf("1 - Encrypt\n");
    printf("2 - Decrypt\n");
    printf("3 - Exit\n");
    fgets(buffer, sizeof(buffer), stdin);
    option = atoi(buffer); // Convert input to integer

    // Ask for plaintext
    printf("Please, insert the plaintext: (max 24 characters)\n");
    fgets(buffer, sizeof(buffer), stdin);
    formatText(buffer, plaintext); // Remove non-alphabetical characters

    // Ask for key
    printf("Please, insert the key: (max 24 characters)\n");
    fgets(buffer, sizeof(buffer), stdin);
    formatText(buffer, key); // Remove non-alphabetical characters

    switch (option)
    {
    case 1:
        encrypt(plaintext, key, encryptedMessage);
        printf("Encrypted message: %s\n", encryptedMessage);
        break;

    case 2:
        decrypt(message, key, )
        break;

    case 3:
        exit(0); // Exit the program
        break;

    default:
        printf("Invalid choice\n");
        break;
    }

    return 0;
}
