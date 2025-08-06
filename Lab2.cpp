//Write a C program to recognize strings under 'a*', 'a*b+', 'abb'
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[20], c;
    int state = 0, i = 0;

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;  // Remove newline

    while (s[i] != '\0') {
        c = s[i++];
        switch (state) {
            case 0:
                if (c == 'a')
                    state = 1;
                else if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 1:
                if (c == 'a')
                    state = 3;
                else if (c == 'b')
                    state = 4;
                else
                    state = 6;
                break;
            case 2:
                if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 3:
                if (c == 'a')
                    state = 3;
                else if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 4:
                if (c == 'b')
                    state = 5;
                else
                    state = 6;
                break;
            case 5:
                if (c == 'b')
                    state = 2;
                else
                    state = 6;
                break;
            case 6:
                printf("\n%s is not recognized", s);
                exit(0);
        }
    }

    if (state == 1 || state == 3)
        printf("%s is accepted under rule 'a*'", s);
    else if (state == 2 || state == 4)
        printf("%s is accepted under rule 'a*b+'", s);
    else if (state == 5)
        printf("%s is accepted under rule 'abb'", s);
    else
        printf("%s is not recognized", s);
    return 0;
}

