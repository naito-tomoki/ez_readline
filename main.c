#include "ez_readline.h"
#include <stdlib.h>

int
main(void)
{
	t_ezrl	rl;

	rl = ezrl_init();

	char *res = ez_readline("inputkin: ", &rl);
	printf("res: %s\n", res);
	res = ez_readline("inputseikin: ", &rl);
	printf("res: %s\n", res);

	printf("funya\n");
	ezrl_add_history(&rl);
	printf("ge-funyamorake\n");

	res = ez_readline("lastchancekin: ", &rl);
	printf("res: %s\n", res);
	free(res);
	return 0;
}
