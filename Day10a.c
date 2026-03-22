#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int i = 0;
    int j = strlen(str) - 1;
    int isPalindrome = 1;

    while (i < j) {
        if (str[i] != str[j]) {
            isPalindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (isPalindrome)
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}