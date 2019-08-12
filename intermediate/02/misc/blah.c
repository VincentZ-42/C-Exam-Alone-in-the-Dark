#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_chk(char *str1, char *str2, int len)
{
	int i;
	int i_len;

	i = -1;
	while (str2[++i])
	{
		i_len = -1;
		while (++i_len < len)
		{
			if (str2[i + i_len] != str1[i_len])
				break;
			printf("%s: %c at %d,i_len = %d, len = %d\n", str2, \
				   	str2[i + i_len], i + i_len, i_len, len);
			if (i_len == len - 1)
				return (1);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;
	int prefix;
	int len;
	int ret_prefix;
	int ret_len;

	if (ac > 1)
	{
		ret_prefix = 0;
		ret_len = 0;
		prefix = -1;
		while (av[1][++prefix])
		{
			len = 1;
			printf("*av[1] = %c\n", av[1][prefix]);
			while (av[1][prefix + len - 1])
			{
				i = 1;
				while (++i < ac)
					if (!ft_chk(av[1] + prefix, av[i], len))
						break;
				if (i != ac)
					break;
				len++;
			}
			if (len - 1 > ret_len)
			{
				ret_len = len - 1;
				ret_prefix = prefix;
				printf("--ret_len = %d\n--ret_prefix = %d\n", ret_len, ret_prefix);
			}
		}
		write(1, av[1] + ret_prefix, ret_len);
	}
	write(1, "\n", 1);
	return (0);
}
