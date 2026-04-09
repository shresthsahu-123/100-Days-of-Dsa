#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int visited[26] = {0}; // for 'a' to 'z'

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    printf("-1\n"); // no repeated character
    return 0;
}