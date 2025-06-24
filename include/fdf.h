/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:23:29 by trupham           #+#    #+#             */
/*   Updated: 2025/06/20 12:25:08 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>
#include <fcntl.h>
#include "../libft/libft.h"
#define WIDTH 1920
#define HEIGHT 2000
#ifndef PI
#define PI 3.14159265358979323846
#endif
#define WHITE 0xFFFFFFFF
#define SCALE 10
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

typedef struct s_map
{
	unsigned int height;
	unsigned int width;
} t_map;

void put_pixel(mlx_image_t* img, unsigned int x, unsigned int y, int color);
void draw_line(mlx_image_t* img, t_point2d p0, t_point2d p1,  int color);
t_point2d project_isometric(t_point3d p3d, int map_width, int map_height, int scale);
t_list *build_list(char *av);
t_map *build_map(t_list *head);
