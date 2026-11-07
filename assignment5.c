#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int choice;
    char str1[100], str2[100], ch;
    char sub[100];

    while (1)
    {
        printf("\n===== String Operations Menu =====\n");
        printf("1. Find length (strlen)\n");
        printf("2. Copy string (strcpy)\n");
        printf("3. Concatenate strings (strcat)\n");
        printf("4. Compare strings (strcmp)\n");
        printf("5. Find character (strchr)\n");
        printf("6. Find substring (strstr)\n");
        printf("7. Tokenize string (strtok)\n");
        printf("8. Convert to uppercase\n");
        printf("9. Convert to lowercase\n");
        printf("10. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Length = %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                strcpy(str2, str1);
                printf("Copied string: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter second string: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 5:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter character to find: ");
                scanf("%c", &ch);
                getchar();

                if (strchr(str1, ch) != NULL)
                    printf("Character found.\n");
                else
                    printf("Character not found.\n");
                break;

            case 6:
                printf("Enter main string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Enter substring: ");
                fgets(str2, 100, stdin);
                str2[strcspn(str2, "\n")] = '\0';

                if (strstr(str1, str2) != NULL)
                    printf("Substring found.\n");
                else
                    printf("Substring not found.\n");
                break;

            case 7:
                printf("Enter a string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                printf("Tokens are:\n");

                char *token = strtok(str1, " ");

                while (token != NULL)
                {
                    printf("%s\n", token);
                    token = strtok(NULL, " ");
                }
                break;

            case 8:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                for (int i = 0; str1[i] != '\0'; i++)
                    str1[i] = toupper(str1[i]);

                printf("Uppercase string: %s\n", str1);
                break;

            case 9:
                printf("Enter string: ");
                fgets(str1, 100, stdin);
                str1[strcspn(str1, "\n")] = '\0';

                for (int i = 0; str1[i] != '\0'; i++)
                    str1[i] = tolower(str1[i]);

                printf("Lowercase string: %s\n", str1);
                break;

            case 10:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}