#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[100][50];
    
    // Input names
    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int maxVotes = 0;
    char winner[50];

    // Count votes
    for(int i = 0; i < n; i++) {
        int count = 1;

        // Skip already counted names
        if(names[i][0] == '\0') continue;

        for(int j = i + 1; j < n; j++) {
            if(strcmp(names[i], names[j]) == 0) {
                count++;
                names[j][0] = '\0'; // mark as counted
            }
        }

        // Update winner
        if(count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        } 
        else if(count == maxVotes) {
            if(strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}