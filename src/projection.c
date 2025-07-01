/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:48:26 by trupham           #+#    #+#             */
/*   Updated: 2025/07/01 11:28:49 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* @brief: loop through the map and connect lines
 */
void	connect_lines(t_point2d *points_2d, mlx_image_t *g_img, t_map *map_data)
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	x = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			if (x + 1 < map_data->width)
				draw_line(g_img, points_2d[y * map_data->width + x], points_2d[y
					* map_data->width + x + 1], WHITE);
			if (y + 1 < map_data->height)
				draw_line(g_img, points_2d[y * map_data->width + x],
					points_2d[(y + 1) * map_data->width + x], WHITE);
			x++;
		}
		y++;
	}
}

/* convert a map of array of ints to an array of 2d points
 */
t_point2d	*convert_3d_to_2d(int *map, t_map *map_data)
{
	t_point3d		p3d;
	t_point2d		*points_2d;
	unsigned int	y;
	unsigned int	x;

	points_2d = malloc(sizeof(t_point2d) * map_data->width * map_data->height);
	if (!points_2d)
		return (NULL);
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			p3d.x = x;
			p3d.y = y;
			p3d.z = map[y * map_data->width + x];
			points_2d[y * map_data->width + x] = project_isometric(p3d,
					map_data, SCALE);
			x++;
		}
		y++;
	}
	return (points_2d);
}

// converts a 3d point {x,y,z} to a 2d point {x,y} base on isometric projection
t_point2d	project_isometric(t_point3d p3d, t_map *map, float scale)
{
	t_point2d	p2d;

	p3d.x -= map->width / 2;
	p3d.y -= map->height / 2;
	p2d.x = (2 * p3d.x - 2 * p3d.y) * scale + WIDTH / 2;
	p2d.y = (p3d.x + p3d.y - p3d.z) * scale + HEIGHT / 2;
	return (p2d);
}
