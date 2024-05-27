#include <stdio.h>
#include <ctype.h>
#include <string.h>

void FOLLOW(char[], char);
void FIRST(char[], char);
void addToResultSet(char[], char);
int numOfProductions;
char productionSet[10][10];
char firstSet[10][10];
char followSet[10][10];

void main() {
    int i;
    char choice;
    char ch;
    printf("How many number of productions?:");
    scanf("%d", &numOfProductions);				// Use: 6
    fflush(stdin);

    for (i = 0; i < numOfProductions; i++) {
        printf("Enter productions number %d :", i + 1);
        gets(productionSet[i]);
    }
	/*  
		Use This: 
			S=AaB
			S=Bb
			A=b
			A=c
			B=a
			B=c
	*/
    for (i = 0; i < numOfProductions; i++) {
        for (int j = 0; j < 10; j++) {
            firstSet[i][j] = '\0';
            followSet[i][j] = '\0';
        }
    }

    // Compute FIRST sets for all non-terminals
    for (i = 0; i < numOfProductions; i++) {
        FIRST(firstSet[i], productionSet[i][0]);
    }

    do {
        printf("Find the FOLLOW of :");
        scanf(" %c", &ch);
        FOLLOW(followSet[ch - 'A'], ch);
        printf("\n FOLLOW(%c)={", ch);
        for (i = 0; followSet[ch - 'A'][i] != '\0'; i++) {
            printf("%c", followSet[ch - 'A'][i]);
        }
        printf("}\n");

        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    printf("\n***** Name: Giver Khadka *****");
}

void FIRST(char *Result, char ch) {
    int i, j, k;
    char subResult[20];
    int foundEpsilon;
    subResult[0] = '\0';
    Result[0] = '\0';

    if (!isupper(ch)) {
        addToResultSet(Result, ch);
        return;
    }

    for (i = 0; i < numOfProductions; i++) {
        if (productionSet[i][0] == ch) {
            if (productionSet[i][2] == '$') {
                addToResultSet(Result, '$');
            } else {
                j = 2;
                while (productionSet[i][j] != '\0') {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for (k = 0; subResult[k] != '\0'; k++) {
                        addToResultSet(Result, subResult[k]);
                    }
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] == '$') {
                            foundEpsilon = 1;
                            break;
                        }
                    }
                    if (!foundEpsilon) {
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

void FOLLOW(char *Result, char ch) {
    int i, j, k;
    char subResult[20];
    char lhs;
    subResult[0] = '\0';
    Result[0] = '\0';

    if (ch == productionSet[0][0]) {
        addToResultSet(Result, '$');
    }

    for (i = 0; i < numOfProductions; i++) {
        for (j = 2; productionSet[i][j] != '\0'; j++) {
            if (productionSet[i][j] == ch) {
                if (productionSet[i][j + 1] != '\0') {
                    FIRST(subResult, productionSet[i][j + 1]);
                    for (k = 0; subResult[k] != '\0'; k++) {
                        if (subResult[k] != '$') {
                            addToResultSet(Result, subResult[k]);
                        }
                    }
                    if (strchr(subResult, '$')) {
                        lhs = productionSet[i][0];
                        if (lhs != ch) {
                            FOLLOW(subResult, lhs);
                            for (k = 0; subResult[k] != '\0'; k++) {
                                addToResultSet(Result, subResult[k]);
                            }
                        }
                    }
                } else {
                    lhs = productionSet[i][0];
                    if (lhs != ch) {
                        FOLLOW(subResult, lhs);
                        for (k = 0; subResult[k] != '\0'; k++) {
                            addToResultSet(Result, subResult[k]);
                        }
                    }
                }
            }
        }
    }
}

void addToResultSet(char *Result, char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val) return;
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
