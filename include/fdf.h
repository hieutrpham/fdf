/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:23:29 by trupham           #+#    #+#             */
/*   Updated: 2025/07/01 11:15:39 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include <math.h>
#define WIDTH 1920
#define HEIGHT 2000
#define WHITE 0xFFFFFFFF
#define SCALE 8

/* @struct to store 3d point
 * @members: int x, y, z
 * @need to include color later
 */
typedef struct s_point3d
{
	int x;
	int y;
	int z;
} t_point3d;

/* struct to store 2d point
 * @members: int x, int y
*/
typedef struct s_point2d
{
	int x;
	int y;
} t_point2d;

typedef struct s_bres {
	int dx;
    int dy;
    int err;
	int sx;
	int sy;
} t_bres;

typedef struct s_map
{
	int height;
	int width;
} t_map;

void put_pixel(mlx_image_t* img, uint16_t x, uint16_t y, int color);
void draw_line(mlx_image_t* img, t_point2d p0, t_point2d p1,  int color);
t_point2d project_isometric(t_point3d p3d, t_map *map, float scale);
t_list *build_list(char *av);
t_map *get_map_data(t_list *head);
int *build_map(t_list *head, t_map *map_data);
void	free_split(char **arr);
t_point2d *convert_3d_to_2d(int *map, t_map *map_data);
void connect_lines(t_point2d *points_2d, mlx_image_t *g_img, t_map *map_data);
void close_win(mlx_key_data_t keydata, void* param);
float get_diagnal(t_map *map);
#endif // !FDF_H
