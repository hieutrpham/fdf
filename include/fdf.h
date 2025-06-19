/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:23:29 by trupham           #+#    #+#             */
/*   Updated: 2025/06/19 14:55:56 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>   // For abs()

#define WIDTH 1920
#define HEIGHT 2000
#ifndef PI
#define PI 3.14159265358979323846
#endif

typedef struct s_point3d
{
	int x;
	int y;
	int z;
} t_point3d;

typedef struct s_point2d
{
	int x;
	int y;
} t_point2d;

void put_pixel(mlx_image_t* img, unsigned int x, unsigned int y, int color);
void draw_line(mlx_image_t* img, t_point2d p0, t_point2d p1,  int color);
t_point2d project_isometric(t_point3d p3d);
