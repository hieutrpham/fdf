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
	// mlx_t* mlx;
	// mlx_image_t* g_img;
	//
	//    mlx = mlx_init(WIDTH, HEIGHT, "MLX42 FdF Isometric", true);
	//    if (!mlx)
	//        exit(EXIT_FAILURE);
	//    g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	//    if (!g_img)
	//    {
	//        mlx_terminate(mlx);
	//        exit(EXIT_FAILURE);
	//    }
	//    mlx_image_to_window(mlx, g_img, 0, 0);
	//    mlx_loop(mlx);
	//    mlx_terminate(mlx);
	if (ac != 2)
		return EXIT_FAILURE;
	t_list *node = build_list(av[1]);
	t_map *map = build_map(node);
	ft_printf("%i, %i\n", map->width, map->height);
	free(map);
	ft_lstclear(&node, free);
    return (EXIT_SUCCESS);
}
