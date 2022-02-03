/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:00:19 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/03 14:30:54 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_map_maker()
{
	char	**map;
	char	*map_line;
	int		lines;
	int		fd;
	int		i;

	i = 0;
	fd = open("./map2.ber", O_RDONLY);
	lines = line_ct();
	map = malloc((lines + 1) * sizeof(char **));
	if (!map)
		exit (0);
	while (i < lines)
	{
		map_line = get_next_line(fd);
		map[i] = map_line;
		i ++;
	}
	map[i] = 0;
	i = 0;
	return (map);
}

int	ft_map_size(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		i ++;
	}
	return (i);
}
