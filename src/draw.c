/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:41:36 by trupham           #+#    #+#             */
/*   Updated: 2025/06/19 14:55:43 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// helper for mlx_put_pixel
void put_pixel(mlx_image_t* img, unsigned int x, unsigned int y, int color)
{
    if (x < img->width && y < img->height)
        mlx_put_pixel(img, x, y, color);
}

// Bresenham's Line Algorithm implementation
// WARN: need to refactor
void draw_line(mlx_image_t* img, t_point2d p0, t_point2d p1,  int color)
{
	int dx = abs(p1.x - p0.x);
    int dy = abs(p1.y - p0.y);
    int sx = p0.x < p1.x ? 1 : -1;
    int sy = p0.y < p1.y ? 1 : -1;
    int err = dx - dy;

    int x = p0.x;
    int y = p0.y;

    while (x != p1.x || y != p1.y)
    {
        put_pixel(img, x, y, color);
        if (x == p1.x && y == p1.y)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

// function that converts a 3d point {x,y,z} to a 2d point {x,y} base on isometric projection
t_point2d project_isometric(t_point3d p3d, int map_width, int map_height, int scale)
{
    t_point2d p2d;

	p3d.x -= map_width /2;
	p3d.y -= map_height/2;
	p2d.x = (2 * p3d.x - 2*p3d.y) * scale + WIDTH/2;
	p2d.y = (p3d.x + p3d.y - p3d.z) * scale + HEIGHT/2;

    return p2d;
}

