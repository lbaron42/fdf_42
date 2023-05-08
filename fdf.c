/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   'fdf.c'                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaron  <lbaron@student.42berlin.de>       :+:  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-05-03 11:28:48 by lbaron            :+:    #+#             */
/*   Updated: 2023-05-03 11:28:48 by lbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;

void draw_line(t_stack *v, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2) {
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x1, y1, color);
        int e2 = 2*err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
    mlx_pixel_put(v->mlx_ptr, v->win_ptr, x2, y2, color);
}


void draw_triangle(t_stack *v, int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    draw_line(v, x1, y1, x2, y2, color);
    draw_line(v, x2, y2, x3, y3, color);
    draw_line(v, x3, y3, x1, y1, color);
}

void draw_square(t_stack *v, int x, int y, int size, int color) {
    int i;

    for (i = x; i < x + size; i++) {
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, i, y, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, i, y + size, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x, i, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x + size, i, color);
    }
}

void draw_circle(t_stack *v, int x0, int y0, int radius, int color) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 + x, y0 + y, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 + y, y0 + x, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 - y, y0 + x, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 - x, y0 + y, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 - x, y0 - y, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 - y, y0 - x, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 + y, y0 - x, color);
        mlx_pixel_put(v->mlx_ptr, v->win_ptr, x0 + x, y0 - y, color);

        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        } else {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}


int main(int argc, char **argv)
{
	t_stack v;

    if (argc != 2)
    {
        write(2,"Error: Wrong number of arguments!\n", 35);
        return (0);
    }
    get_fd(&v, argv);
    populate_split(&v);
    v.mlx_ptr = mlx_init();
    if (v.mlx_ptr == NULL)
        return (-1);
    v.win_ptr = mlx_new_window(v.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
    if (v.win_ptr == NULL)
    {
        free(v.win_ptr);
        return (-1);
    }

    draw_triangle(&v, 450, 100, 200, 200, 240, 450, 0x00FF00);
    draw_square(&v, 100, 100, 100, 0x0000FF);
    draw_circle(&v, 450, 450, 100, 0xFF0000);
    mlx_loop(v.mlx_ptr);

    mlx_destroy_window(v.mlx_ptr, v.win_ptr);
    mlx_destroy_display(v.mlx_ptr);
    free(v.mlx_ptr);
    print_split(&v);
    free_split(&v);
	free(v.dirpath);
	close(v.fd1);
	return (0);
}
