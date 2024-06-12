#include <stdio.h>
#include <stdlib.h>

#define filename1 "my_code.txt"
#define filename2 "πŸ∑ΩÃ‚Ω‚.txt"

int main()
{
	FILE *pf1 = fopen(filename1 , "ab+"); 
	fclose(pf1);
	pf1 = NULL;
	FILE *pf2 = fopen(filename2 , "ab+");
	fclose(pf2);
	pf2 = NULL;
} 
