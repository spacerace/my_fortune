/*     #######################################
 *    #    FORTUNE                            #
 *    #                                       #
 *    # (c) 2018 NS <stecdose@gmail.com>      #
 *    #                                       #
 *     #######################################
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char default_db[3][24] = { "./fortune_db.txt", "~/.fortune_db.txt", "/etc/fortune_db" };
static FILE *fptr;

int main(int argc, char **argv) {
	unsigned int cookies, cookie;
	int c;
	char linebuf[2048];

	/* we open db and count items */
	fptr = fopen(default_db[0], "r");
	if(fptr == NULL) {
		printf("error while opening '%s'\n", default_db[0]);
		exit(-1);
	}

	cookies = 0;
	do {
		c = fgetc(fptr);
		if(c == '\n') cookies++;
	} while(c != EOF);

	/* now we choose a random item */
	srand(time(NULL));
	cookie = rand() % cookies;

	/* now we walk along db until we reach the chosen item,
         * then print, then exit. */
	rewind(fptr);	/* start over at beginning of file */
	cookies = 0; 	/* we reuse cookies as counter */

	while(fgets(linebuf, sizeof(linebuf), fptr) != NULL) {
		if(cookies == cookie) {
			printf("%s", linebuf);
			fclose(fptr);
			exit(0);
		}
		cookies++;
	}

	fclose(fptr);

	return 0;
}


