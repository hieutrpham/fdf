/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:22 by trupham           #+#    #+#             */
/*   Updated: 2025/06/20 12:28:55 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int main(int ac, char **av)
{
	mlx_t* mlx;
	mlx_image_t* g_img;

	if (ac != 2)
		return EXIT_FAILURE;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42 FdF Isometric", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!g_img)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	t_list *node = build_list(av[1]);
	t_map *map_data = get_map_data(node);
	if (!map_data)
		return EXIT_FAILURE;
	int *map = build_map(node, map_data);
	t_point2d *point2d = convert_3d_to_2d(map, map_data);
	connect_lines(point2d, g_img, map_data);
	free(map_data);
	free(map);
	free(point2d);
	ft_lstclear(&node, free);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
