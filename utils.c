#include "utils.h"

int
ft_isspace(int c)
{
	unsigned char uc = c;
	return (uc == ' ' || ('\t' <= uc && uc <= '\r'));
}
