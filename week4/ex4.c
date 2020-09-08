#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    char word[256];
	while(1)
    {
		fgets(word, sizeof(word), stdin);
		
        char *args[256];

		int t = 0;
        int j = 0;

		for(int i=0; i<256; i++){
			args[i]=NULL;
		}

        int c = 0;
		args[0]=(char*)malloc(256);

		while(1)
        {
			if(word[c] != ' ')
            {
				args[t][j] = word[c];
				c++;
                j++;
			}
			else if(word[c] == ' ')
            {
				c++;
                j = 0;
                t++;
				args[t]=(char*)malloc(256);
			}
			else
            { break; }
		}

		int pid = fork();
		if(pid==0)
        {
			execvp(args[0],args);
		}
	}
    return 0;
}