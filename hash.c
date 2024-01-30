/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/30 19:18:07 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "../libft/INCLUDES/libft.h"

int	put

void	init_tab(t_hash *htab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		htab[i] = NULL;
		i++;
	}
}

t_hash	*dup_exit(char *key)
{
	ft_prinft("Find a duplicate of key: %s.\n", key);
	return (NULL);
}

unsigned int	hash(char *key, int size)
{
	unsigned int	value;
	int				i;

	i = 0;
	value = 0;
	while (key[i])
	{
		value = (value + key[i]) * key[i] % size;
		i++;
	}
	return (value);
}

t_hash	*create_htab(int size, char *tab[])
{
	t_hash			*htab;
	unsigned int	value;

	htab = (t_hash *)malloc((size) * sizeof(t_hash));
	if (htab == NULL)
		return (NULL);
	init_tab(htab, size);
	while (size--)
	{
		value = hash(tab[size], size);
		if (htab[value] == NULL)
		{
			htab[value].key = ft_strdup(tab[size]);
			htab[value].hash = value;
		}
		else

	}
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_printf("%d\n", hash(argv[i], argc));
		i++;
	}
	return (0);
}
