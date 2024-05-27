#include <stdio.h>

int main()
{
    FILE *outputFile;
    char txt[100], outputFileName[50];
    int key, choice;
    char inputOption;

    printf("********************************************\n");
    printf("*             Caesar Cipher Program          *\n");
    printf("********************************************\n");

    printf("Do you want to input text manually or from a file? (M/F): ");
    scanf(" %c", &inputOption);

    if (inputOption == 'M' || inputOption == 'm')
    {
        // Input text manually
        printf("Enter the text \n");
        getchar(); // Consume the newline character left in the buffer
        fgets(txt, sizeof(txt), stdin);
    }
    else if (inputOption == 'F' || inputOption == 'f')
    {
        // Input from file
        FILE *inputFile;
        char inputFileName[50];

        printf("Enter the input file name: ");
        scanf("%s", inputFileName);

        inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL)
        {
            printf("Error opening input file.\n");
            return 1;
        }

        // Read content from the file
        fgets(txt, sizeof(txt), inputFile);
        fclose(inputFile);
    }
    else
    {
        printf("Invalid option. Exiting program.\n");
        return 1;
    }

    printf("Text: %s\n", txt);

    // Prompt the user to enter the encryption/decryption key
    printf("Enter the Key: ");
    scanf("%d", &key);

    // Display the menu for the user to choose between encryption and decryption
    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Encryption logic
        for (int i = 0; txt[i]; i++)
        {
            if (txt[i] == ' ')
            {
                continue;
            }
            else if (txt[i] >= 'a' && txt[i] <= 'z')
            {
                if (txt[i] + key > 'z')
                {
                    txt[i] = txt[i] + key - 26;
                }
                else
                    txt[i] = txt[i] + key;
            }
            else if (txt[i] >= 'A' && txt[i] <= 'Z')
            {
                if (txt[i] + key > 'Z')
                {
                    txt[i] = txt[i] + key - 26;
                }
                else
                    txt[i] = txt[i] + key;
            }
            else if (txt[i] >= '0' && txt[i] <= '9')
            {
                key = key % 10;
                if (txt[i] + key > '9')
                {
                    txt[i] = txt[i] + key - 10;
                }
                else
                    txt[i] = txt[i] + key;
            }
        }
        printf("Encrypted text is: %s", txt);

        // Output to file
        printf("Enter the output file name: ");
        scanf("%s", outputFileName);
        outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL)
        {
            printf("Error opening output file.\n");
            return 1;
        }
        fprintf(outputFile, "Encrypted text is: %s", txt);
        fclose(outputFile);
        break;

    case 2:
        // Decryption logic
        for (int i = 0; txt[i]; i++)
        {
            if (txt[i] == ' ')
                continue;
            else if (txt[i] >= 'a' && txt[i] < 'z')
            {
                if (txt[i] - key < 'a')
                {
                    txt[i] = txt[i] - key + 26;
                }
                else
                    txt[i] = txt[i] - key;
            }
            else if (txt[i] >= 'A' && txt[i] < 'Z')
            {
                if (txt[i] - key < 'A')
                {
                    txt[i] = txt[i] - key + 26;
                }
                else
                    txt[i] = txt[i] - key;
            }
            else if (txt[i] >= '0' && txt[i] <= '9')
            {
                if (txt[i] - key < '0')
                {
                    txt[i] = txt[i] - key + 10;
                }
                else
                    txt[i] = txt[i] - key;
            }
        }
        printf("\nThe Decrypted text is: %s", txt);

        // Output to file
        printf("Enter the output file name: ");
        scanf("%s", outputFileName);
        outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL)
        {
            printf("Error opening output file.\n");
            return 1;
        }
        fprintf(outputFile, "Decrypted text is: %s", txt);
        fclose(outputFile);
        break;

    default:
        printf("Invalid choice!\n");
        return 1;
    }

    return 0;
}

