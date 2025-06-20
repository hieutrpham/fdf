/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:50:08 by trupham           #+#    #+#             */
/*   Updated: 2025/06/20 11:50:11 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int parser(char *av)
{
	int fd;

	fd = open(av, O_RDONLY);
	if (!fd)
		return EXIT_FAILURE;
	char *line;
	int map_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break;
		ft_printf(line);
		map_height++;
		free(line);
	}
	return 1;
}
