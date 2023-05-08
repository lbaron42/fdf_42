/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   'fdf.h'                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron  <lbaron@student.42berlin.de>       :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-05-03 19:43:51 by lbaron            :+:    #+#             */
/*   Updated: 2023-05-03 19:43:51 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
#define FDF_FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

typedef struct s_stack
{
    char    *title;
	char	spliter;
	char	**split;
    void    *mlx_ptr;
    void    *win_ptr;
    int     x;
    int     y;
    int     z;

	int		i;
    int		fd1;
    char	*line;
	char	*dirpath;
} t_stack;

// magic_func.c
void populate_split(t_stack *v);
void free_split(t_stack *v);
void print_split(t_stack *v);
void get_fd(t_stack *v, char **argv);

#endif //FDF_FDF_H
