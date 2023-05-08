/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   'magic_func.c'                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron  <lbaron@student.42berlin.de>       :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-05-07 18:37:07 by lbaron            :+:    #+#             */
/*   Updated: 2023-05-07 18:37:07 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void populate_split(t_stack *v)
{
    v->i = 0;
    v->split = malloc(sizeof(char *) * 1000);
    while ((v->split[v->i] = get_next_line(v->fd1)) != NULL)
        v->i++;
    v->split[v->i] = NULL;
}

void free_split(t_stack *v)
{
    v->i = 0;
    while (v->split[v->i] != NULL)
    {
        free(v->split[v->i]);
        v->i++;
    }
    free(v->split);
}

void print_split(t_stack *v)
{
    v->i = 0;
    while (v->split[v->i] != NULL)
    {
        write(1, v->split[v->i], ft_strlen(v->split[v->i]));
        v->i++;
    }
}

void get_fd(t_stack *v, char **argv)
{
    v->dirpath = "test_maps/";
    v->dirpath = ft_strjoin(v->dirpath, argv[1]);
    v->fd1 = open(v->dirpath, O_RDONLY);
    if (v->fd1 == -1)
    {
        write(2,"Error: File not found!\n", 24);
        exit(0);
    }
}
