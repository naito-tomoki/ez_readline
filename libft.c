#include "libft.h"

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
