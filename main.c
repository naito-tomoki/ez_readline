#include "ez_readline.h"
#include <stdlib.h>

int
main(void)
{
	t_ezrl	rl;

	rl = ezrl_init();

	char *res = ez_readline("input1: ", &rl);
	printf("input1 res: %s\n", res);
	res = ez_readline("input1 again-1: ", &rl);
	printf("input1 res: %s\n", res);

	ezrl_add_history(&rl);

	res = ez_readline("input2: ", &rl);
	printf("input2 res: %s\n", res);
	res = ez_readline("input2 again-1: ", &rl);
	printf("input2 res: %s\n", res);
	res = ez_readline("input2 again-2: ", &rl);
	printf("input2 res: %s\n", res);

	ezrl_add_history(&rl);

	res = ez_readline("input3: ", &rl);
	printf("input3 res: %s\n", res);

	free(res);
	return 0;
}
