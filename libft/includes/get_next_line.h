/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasamadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:18:30 by nasamadi          #+#    #+#             */
/*   Updated: 2023/02/06 14:43:23 by nasamadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048
# include "libft.h"
# include <unistd.h>

typedef struct s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

typedef struct s_gnl
{
	t_file			*f;
	char			buff[BUFF_SIZE + 1];
	ssize_t			size;
	char			*tmp;
}	t_data;

int					get_next_line(const int fd, char **line);

#endif
