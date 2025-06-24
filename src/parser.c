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

/* read each line from fd and create a new node for each line
 * @param the path to the file
 * @return the head of the linked list
 */
t_list *build_list(char *av)
{
	int fd;
	t_list *head;
	char *line;
	t_list *new;

	head = NULL;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		new = ft_lstnew(line);
		if (!new)
			return (ft_lstclear(&head, free), free(line), NULL);
		ft_lstadd_back(&head, new);
	}
	close(fd);
	return head;
}

/* walk through the list to get the map data
 * @return t_map includes height, width
 */
t_map *build_map(t_list *head)
{
	t_map *map;
	unsigned int width;

	map = malloc(sizeof(t_map));
	if (!map)
		return NULL;
	map->height = ft_lstsize(head);
	map->width = ft_count_word(head->content, ' ');
	while (head)
	{
		width = ft_count_word(head->content, ' ');
		if (map->width != width)
			return (ft_putendl_fd("invalid map", 2), NULL);
		head = head->next;
	}
	return map;
}
