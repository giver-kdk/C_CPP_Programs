#include <stdio.h>
#include <string.h>
#define N 5					// Max buffer size
#define M 50				// Max input code string size

char buffer1[N], buffer2[N], memory[M];			
int bp = -1, fp = 0;		// Begin and Forward Pointer
int indexRAM = 0;				// RAM memory index
int turn = 1;

void fillBuffer(char buffer[N]);
void extractLexeme();
int bufferEnd(char buffer[N]);
int lexemeEnd(char buffer[N]);

int main()
{
	int i;
	printf("Enter input code string:\n");	
	gets(memory);
	// Fill 1st input buffer
	fillBuffer(buffer1);
	// Loop until entire input code string is scanned
	while(!(memory[indexRAM] == '\0'))
	{
		for(i = 0; i < N; i++, fp++)
		{
			if(turn == 1 && bufferEnd(buffer1))
			{
				fillBuffer(buffer2);
				turn = 2;
				i = 0;
			}
			else if(turn == 2 && bufferEnd(buffer2))
			{
				fillBuffer(buffer1);
				turn = 1;
				i = 0;
			}
			else if(turn == 1 && lexemeEnd(buffer1))
			{
				extractLexeme();
				bp = fp;
			}
			else if(turn == 2 && lexemeEnd(buffer2))
			{
				extractLexeme();
				bp = fp;
			}
		}
	}

}

int bufferEnd(char buffer[N])
{
	if(buffer[fp % N] == '\0' && memory[indexRAM] != '\0')
		return 1;
	else return 0;
}
int lexemeEnd(char buffer[N])
{
	if((buffer[fp % N] == ' ' || buffer[fp % N] == ';'))
		return 1;
	else return 0;
}
void fillBuffer(char buffer[N])
{
	int i;
	strcpy(buffer, "");		// Clear buffer
	for(i = 0; i < N - 1 && memory[indexRAM] != '\0'; i++, indexRAM++)
		buffer[i] = memory[indexRAM];
	buffer[i] = '\0';
}
void extractLexeme()
{
	int i, j;
	char lexeme[M];
	for(i = bp + 1, j = 0; i < fp; i++)
	{
		if(i % (2 * N) < N)
		{
			if(buffer1[i % N] != ' ' && buffer1[i % N] != '\0') 
			{
				lexeme[j] = buffer1[i % N]; 
				j++;
			}
		}
		else 
		{
			if(buffer2[i % N] != ' ' && buffer2[i % N] != '\0') 
			{
				lexeme[j] = buffer2[i % N];
				j++;
			}
		}
	}
	lexeme[j] = '\0';
	if(lexeme[0] != '\0') printf("Lexeme: %s\n", lexeme);
}