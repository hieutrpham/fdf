/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:22 by trupham           #+#    #+#             */
/*   Updated: 2025/06/19 15:43:02 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int32_t main(void)
{
	mlx_t* mlx;
	mlx_image_t* g_img;

    mlx = mlx_init(WIDTH, HEIGHT, "MLX42 FdF Isometric", true);
    if (!mlx)
        exit(EXIT_FAILURE);

    g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
    if (!g_img)
    {
        mlx_terminate(mlx);
        exit(EXIT_FAILURE);
    }
    mlx_image_to_window(mlx, g_img, 0, 0);

    int map[11][19] = {
		{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0, 10, 10, 10, 10, 10,  0,  0,  0},
		{0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,  0, 10, 10,  0,  0},
		{0,  0, 10, 10,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0,  0, 10, 10,  0,  0},
		{0,  0, 10, 10, 10, 10, 10, 10,  0,  0,  0,  0, 10, 10, 10, 10,  0,  0,  0},
		{0,  0,  0, 10, 10, 10, 10, 10,  0,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0,  0, 10, 10,  0,  0,  0, 10, 10,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0,  0, 10, 10,  0,  0,  0, 10, 10, 10, 10, 10, 10,  0,  0},
		{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
		{0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}
    };
    int map_width = 19;
    int map_height = 11;

    // --- Convert all 3D points to 2D projected points ---
    t_point2d projected_points[map_height][map_width];

    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            t_point3d p3d = {x, y, map[y][x]}; // x=column, y=row, z=height
            projected_points[y][x] = project_isometric(p3d);
        }
    }
    // --- Draw Lines (Wireframe) ---
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            // Draw horizontal lines
            if (x + 1 < map_width)
                draw_line(g_img, projected_points[y][x], projected_points[y][x+1], 0xFFFFFFFF);
            // Draw vertical lines
            if (y + 1 < map_height)
                draw_line(g_img, projected_points[y][x], projected_points[y+1][x], 0xFFFFFFFF);
        }
    }
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}
