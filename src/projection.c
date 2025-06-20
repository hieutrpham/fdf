/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:48:26 by trupham           #+#    #+#             */
/*   Updated: 2025/06/20 11:48:48 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void connect_lines(t_point2d *points_2d, mlx_image_t *g_img, int map_height, int map_width)
{
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            // Draw horizontal lines
            if (x + 1 < map_width)
                draw_line(g_img, points_2d[y * map_width + x], points_2d[y * map_width + x + 1], WHITE);
            // Draw vertical lines
            if (y + 1 < map_height)
                draw_line(g_img, points_2d[y * map_width + x], points_2d[y * map_width + x + 1], WHITE);
        }
    }
}

/* function that convert a map to an array of 2d points
 */
t_point2d *convert_3d_to_2d(int **map, int map_height, int map_width)
{
	t_point3d p3d;
	t_point2d *points_2d;
	int y;
	int x;

	points_2d = malloc(sizeof(t_point2d) * map_width * map_height);
	if (!points_2d)
		return NULL;
	y = 0;
	while (y < map_height)
    {
		x = 0;
		while (x < map_width)
        {
			p3d.x = x;
			p3d.y = y;
			p3d.z = map[y][x];
            points_2d[y * map_width + x] = project_isometric(p3d, map_width, map_height, SCALE);
			x++;
        }
		y++;
    }
	return points_2d;
}
