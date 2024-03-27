#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findKey(int A, int B, int YN, char *YorN, int count);

int main(){
	int A, B, YN, answer = 0, count = 0;
	char *YorN;

	scanf("%d %d %d", &A, &B, &YN);
	
	YorN = (char *)malloc(sizeof(char)*(YN + 1));
	scanf("%s", YorN);

	answer = findKey(A, B, YN, YorN, count);
	printf("%d", answer);

	free(YorN);

	return 0;
}

int findKey(int A, int B, int YN, char *YorN, int count)
{
	if (count == YN+1) return A;

	int M = (A + B) / 2;

	if (A == B) return A;
	else if (YorN[count] == 'Y') findKey(M + 1, B, YN, YorN, count+=1);
	else if (YorN[count] == 'N') findKey(A, M, YN, YorN, count+=1);
}
