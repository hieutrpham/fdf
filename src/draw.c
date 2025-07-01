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
void	put_pixel(mlx_image_t *img, uint16_t x, uint16_t y, int color)
{
	if (x < img->width && y < img->height)
		mlx_put_pixel(img, x, y, color);
}

// Bresenham's Line Algorithm implementation
// @draw a line between 2 points p0 -> p1
t_bres	*init_bres(t_point2d p0, t_point2d p1)
{
	t_bres	*bres;

	bres = malloc(sizeof(t_bres));
	if (!bres)
		return (NULL);
	if (p0.x < p1.x)
		bres->sx = 1;
	else
		bres->sx = -1;
	if (p0.y < p1.y)
		bres->sy = 1;
	else
		bres->sy = -1;
	bres->dy = abs(p1.y - p0.y);
	bres->dx = abs(p1.x - p0.x);
	bres->err = bres->dx - bres->dy;
	return (bres);
}

void	draw_line(mlx_image_t *img, t_point2d p0, t_point2d p1, int color)
{
	t_bres	*bres;

	bres = init_bres(p0, p1);
	if (!bres)
		return ;
	while (p0.x != p1.x || p0.y != p1.y)
	{
		put_pixel(img, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		int e2 = 2 * bres->err;
		if (e2 > -bres->dy)
		{
			bres->err -= bres->dy;
			p0.x += bres->sx;
		}
		if (e2 < bres->dx)
		{
			bres->err += bres->dx;
			p0.y += bres->sy;
		}
	}
	free(bres);
}
