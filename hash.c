/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:24 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/31 18:58:27 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

int	ft_is_prime(int nb)
{
	int	diviseur;

	diviseur = 2;
	if (nb <= 1)
		return (0);
	while (diviseur <= (nb / diviseur))
	{
		if (nb % diviseur == 0)
			return (0);
		diviseur++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 1)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

void	init_tab(t_hash *htab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		htab[i].key = NULL;
		htab[i].next = NULL;
		i++;
	}
}

char	*insert_key(char *key)
{
	return (ft_strdup(key));
}

int	handle_collision(t_hash *htab, char *key)
{
	t_hash	*actual;

	actual = htab;
	while (actual)
	{
		if (actual->key == NULL)
		{
			actual->key = insert_key(key);
			if (actual->key == NULL)
				return (-2);
			return (0);
		}
		if ((!ft_strncmp(actual->key, key, ft_strlen(actual->key) + 1)))
			return (-1);
		else if (actual->next == NULL)
		{
			actual->next = (t_hash *)malloc(sizeof(t_hash));
			if (actual->next == NULL)
				return (-2);
			init_tab(actual->next, 1);
		}
		actual = actual->next;
	}
	return (0);
}

t_hash	*dup_exit(char *key)
{
	ft_printf("Find a duplicate of key: %s.\n", key);
	return (NULL);
}

unsigned int	hash(char *key, int size)
{
	return (ft_atoi(key) * ft_find_next_prime(size) % size);
}

t_hash	*create_htab(int size, char *tab[])
{
	t_hash			*htab;
	unsigned int	index;
	int				j;

	j = 0;
	htab = (t_hash *)malloc((size) * sizeof(t_hash));
	if (htab == NULL)
		return (NULL);
	init_tab(htab, size);
	while (j < size)
	{
		index = hash(tab[j], size);
		if (htab[index].key == NULL)
			htab[index].key = ft_strdup(tab[j]);
		else
			if (handle_collision(&htab[index], tab[j]) == -1)
				return (dup_exit(tab[j]));
		j++;
	}
	return (htab);
}

void print_tab(t_hash *htab, int size)
{
	int		i;
	int		color;
	t_hash	*actual;

	i = 0;
	while (i < size)
	{
		color = 0;
		if (htab[i].key == NULL)
			ft_printf("\t%i\t===>\t\n", i);
		else
		{
			actual = &htab[i];
			ft_printf("\t%i", i);
			while (actual)
			{
				ft_printf("\033[0;3%im\t===>\t%s", (color % 6) + 1, actual->key);
				actual = actual->next;
				color++;
			}
			ft_printf("\033[0;37m\n");
		}
		i++;
	}
}

void print_efficiency(t_hash *htab, int size)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (htab[i].key == NULL)
			count++;
		i++;
	}
	ft_printf("The effiency of that hash table is %d%%\n", (size - count) * 100 / size);
}

int	main(int argc, char *argv[])
{
	t_hash	*htab;
	char	**tab;
	int		size;

	size = 0;
	tab = ft_split(argv[1], ' ');
	if (tab == NULL)
		return (-1);
	while (tab[size])
		size++;
	htab = create_htab(size, tab);
	if (htab)
	{
		print_tab(htab, size);
		print_efficiency(htab, size);
	}
	return (0);
}
