#include "libxml.h"
#include <stdlib.h>

void		ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab && tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}