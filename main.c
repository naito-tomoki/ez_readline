#include "lib/ez_readline.h"

int
main(void)
{
	t_ezrl	*rl;

	char *res = ez_readline("inputkin: ", &rl);
	printf("res: %s\n", res);
	res = ez_readline("inputkin: ", &rl);
	printf("res: %s\n", res);
	return 0;
}
