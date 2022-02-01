/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_ct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:30:29 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/26 15:41:14 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int line_ct()
{
	int fd;
	int ct;
	char nl[BUFFER_SIZE];

	ct = 0;
	fd = open("./map.ber", O_RDONLY);
	while (read(fd, nl, BUFFER_SIZE) != 0)
	{
		if (ft_strchr(nl, '\n') != NULL)
			ct ++;
	}
	close (fd);
	return (ct);
}
