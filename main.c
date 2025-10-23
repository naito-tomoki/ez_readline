#include "ez_readline.h"
#include <stdlib.h>

int
main(void)
{
	t_ezrl	rl;
	char *res;

	rl = ezrl_init();

	res = ez_readline("connect normal-0: ", &rl);
	res = ez_readline("connect normal-1: ", &rl);
	res = ez_readline("connect normal-Z: ", &rl);

	ezrl_add_history(&rl);

	ezrl_set_conn_str("\n", &rl);

	res = ez_readline("connect herdoc-0: ", &rl);
	res = ez_readline("connect herdoc-1: ", &rl);
	res = ez_readline("connect herdoc-Z: ", &rl);

	ezrl_add_history(&rl);
	ez_readline("check your input: ", &rl);
	ezrl_endall(&rl);
	return 0;
}
