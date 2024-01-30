/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:32 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/30 17:54:08 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdlib.h>

typedef struct s_hash
{
	char			*key;
	size_t			hash;
	struct s_hash	*next;
}	t_hash;

#endif
