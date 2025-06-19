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

void put_pixel(mlx_image_t* img, unsigned int x, unsigned int y, int color)
{
    if (x < img->width && y < img->height)
        mlx_put_pixel(img, x, y, color);
}

// Bresenham's Line Algorithm implementation
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
t_point2d project_isometric(t_point3d p3d)
{
    t_point2d p2d;

	p3d.x -= 19 /2; // width of the map
	p3d.y -= 11/2; // height of the map
	p2d.x = (2 * p3d.x - 2*p3d.y) * 10 + WIDTH/2; // 10 is scale that needs to be adjusted to the map
	p2d.y = (p3d.x + p3d.y - p3d.z) * 10 + HEIGHT/2;

    return p2d;
}

