/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:48:26 by trupham           #+#    #+#             */
/*   Updated: 2025/07/01 18:12:23 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/* @brief: loop through the map and connect lines
 */
void	connect_lines(t_point2d *points_2d, mlx_image_t *g_img, t_map *map_data)
{
	int	y;
	int	x;

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
	t_point3d	p3d;
	t_point2d	*points_2d;
	int			y;
	int			x;
	float		scale;

	scale = WIDTH / get_diagnal(map_data) * cos(30.0f / 180.0f * M_PI) * 0.75;
	points_2d = malloc(sizeof(t_point2d) * map_data->width * map_data->height);
	if (!points_2d)
		return (NULL);
	y = -1;
	while (++y < map_data->height)
	{
		x = -1;
		while (++x < map_data->width)
		{
			p3d.x = x;
			p3d.y = y;
			p3d.z = map[y * map_data->width + x];
			points_2d[y * map_data->width + x] = project_isometric(p3d,
					map_data, scale);
		}
	}
	return (points_2d);
}

float	get_diagnal(t_map *map)
{
	return (sqrt(map->width * map->width + map->height * map->height));
}

// converts a 3d point {x,y,z} to a 2d point {x,y} base on isometric projection
t_point2d	project_isometric(t_point3d p3d, t_map *map, float scale)
{
	t_point2d	p2d;
	float		cos30;
	float		sin30;

	cos30 = cos(30.0f / 180.0f * M_PI);
	sin30 = sin(30.0f / 180.0f * M_PI);
	p3d.x -= map->width * 0.5f;
	p3d.y -= map->height * 0.5f;
	p2d.x = (int)((cos30 * p3d.x - cos30 * p3d.y) * scale + (float)WIDTH / 2.f);
	p2d.y = (int)((sin30 * p3d.x + sin30 * p3d.y - p3d.z) * scale
			+ (float)HEIGHT / 2.f);
	return (p2d);
}
