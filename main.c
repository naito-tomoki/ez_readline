#include "ez_readline.h"
#include <stdlib.h>
#include <stdio.h>

int
main(void)
{
	t_ezrl	rl;
	const char *res;

	(void)res;

	rl = ezrl_init();

	ezrl_set_histsize(-1, &rl);

	//res = ez_readline("connect normal-0: ", &rl);
	//res = ez_readline("connect normal-1: ", &rl);
	//res = ez_readline("connect normal-Z: ", &rl);

	//ezrl_add_history(&rl);

	//ezrl_set_conn_str("\n", &rl);

	//res = ez_readline("connect herdoc-0: ", &rl);
	//printf("res: %s\n", res);
	//res = ez_readline("connect herdoc-1: ", &rl);
	//printf("res: %s\n", res);
	//res = ez_readline("connect herdoc-Z: ", &rl);
	//printf("res: %s\n", res);

	ezrl_add_history(&rl);
	ez_readline("1:", &rl);
	ezrl_add_history(&rl);
	ezrl_add_history(&rl);
	ez_readline("2:", &rl);
	ez_readline("2-1:", &rl);
	ez_readline("2-2:", &rl);
	printf("2-2 add:%s\n", ezrl_get_inputing_line(&rl));
	ez_readline("2-3:", &rl);
	ez_readline("2-4:", &rl);
	ez_readline("2-5:", &rl);
	ezrl_add_history(&rl);
	ez_readline("3:", &rl);
	ez_readline("3-1:", &rl);
	ez_readline("3-2:", &rl);
	ez_readline("3-3:", &rl);
	ez_readline("3-4:", &rl);
	ezrl_add_history(&rl);
	ez_readline("4:", &rl);
	ezrl_add_history(&rl);


	//ez_readline("check your input: ", &rl);

	printf("history count: %d\n", ezrl_get_history_count(&rl));
	printf("total lines: %d\n", ezrl_get_total_inputlines(&rl));

	ezrl_endall(&rl);
	return 0;
}
