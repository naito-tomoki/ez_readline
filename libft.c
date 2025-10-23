#include "libft.h"
#include <stdlib.h>

size_t
ft_strlen(const char *s)
{
	const char *cp = s;
	while (*s) s++;
	return (s - cp);
}

void *
ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*udest = (unsigned char *)dest;
	unsigned char	*usrc = (unsigned char *)src;
	if (src > dest) {
		while (n--)
			*udest++ = *usrc++;
	}
	else {
		udest += (n - 1); usrc += (n - 1);
		while (n--)
			*udest-- = *usrc--;
	}
	return (dest);
}

char *
ft_strdup(const char *s)
{
	if (!s) return (NULL);
	const size_t slen = ft_strlen(s);
	char *res = malloc(slen + 1);
	if (!res) return (NULL);
	ft_memmove(res, s, slen); res[slen] = 0;
	return (res);
}
