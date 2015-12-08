#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void readInputTillAllCharsAreEntered()
{
	int bitFlagToTrackAllChars = (1 << 25) * 2 - 1;

	while(bitFlagToTrackAllChars > 0)
	{
		char c = fgetc(stdin);
		fflush(stdin);
		if(c < 'a' || c > 'z')
			continue;

		int bitFlagForChar = 1 << (c - 'a');
		printf("%d char:\n", bitFlagForChar);
		printf("%d chars:\n", bitFlagToTrackAllChars);
		if(bitFlagToTrackAllChars & bitFlagForChar)
			bitFlagToTrackAllChars -= bitFlagForChar;
	}
	printf("All characters have been entered\n");
}

void main()
{
	readInputTillAllCharsAreEntered();
	getche();
}