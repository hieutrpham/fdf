/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:10:22 by trupham           #+#    #+#             */
/*   Updated: 2025/07/01 11:25:21 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	main_draw(mlx_image_t *g_img, char *str)
{
	t_list		*node;
	t_map		*map_data;
	int			*map;
	t_point2d	*point2d;

	node = build_list(str);
	if (!node)
		return ;
	map_data = get_map_data(node);
	if (!map_data)
		return ;
	map = build_map(node, map_data);
	if (!map)
		return ;
	point2d = convert_3d_to_2d(map, map_data);
	connect_lines(point2d, g_img, map_data);
	free(map_data);
	free(map);
	free(point2d);
	ft_lstclear(&node, free);
	return ;
}

int	main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;

	if (ac != 2)
		return (EXIT_FAILURE);
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42 FdF Isometric", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!g_img)
	{
		mlx_terminate(mlx);
		exit(EXIT_FAILURE);
	}
	main_draw(g_img, av[1]);
	mlx_image_to_window(mlx, g_img, 0, 0);
	mlx_key_hook(mlx, close_win, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
