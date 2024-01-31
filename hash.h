/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeville <cdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:32 by cdeville          #+#    #+#             */
/*   Updated: 2024/01/31 17:37:53 by cdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

# include <stdlib.h>
# include "my_libft/INCLUDES/libft.h"
# include <math.h>

typedef struct s_hash
{
	char			*key;
	struct s_hash	*next;
}	t_hash;

#endif
