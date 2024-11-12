#include <stdio.h>
#include <string.h>

void search(char* ptn, char* txt) {
    int m = strlen(ptn);
    int n = strlen(txt);
    int i, j;
    int found = 0; 
    
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (txt[i + j] != ptn[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index: %d\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char txt[100], ptn[100];

    printf("Enter the text: ");
    fgets(txt, sizeof(txt), stdin); 
    
    if (txt[strlen(txt) - 1] == '\n') {
        txt[strlen(txt) - 1] = '\0';
    }

    printf("Enter the pattern: ");
    fgets(ptn, sizeof(ptn), stdin);
    
    if (ptn[strlen(ptn) - 1] == '\n') {
        ptn[strlen(ptn) - 1] = '\0';
    }

    search(ptn, txt);

    return 0;
}


