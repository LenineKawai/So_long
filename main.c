/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:50:38 by mgolinva          #+#    #+#             */
/*   Updated: 2022/01/26 17:59:07 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include "so_long.h"

typedef struct	s_struct {
	void		*mlx;
	void		*win;
}				t_struct;

typedef struct	s_img {
	void	*img;
	int		x;
	int		y;
}				t_img;

typedef	struct	s_prog {
	t_struct	mlx;
	t_img		img;
	t_img		img2;
	t_img		img3;
	t_img		ground;
	t_img		wall;
	t_img		pickup;
	int 		anim;
}				t_prog;

int	move(int keycode, t_prog *param)
{
	printf("anim = %d\n", param->anim);
	mlx_clear_window(param->mlx.mlx, param->mlx.win);
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx.mlx, param->mlx.win);
		exit (0);
	}
	if (keycode == 0 /*&& param->img.x - 2 <  0 && param->img.y - 2 < 0*/)
		param->img.x -= 16;
	if (keycode == 1 /*&& param->img.x - 2 <  0 && param->img.y - 2 < 0*/)
		param->img.y += 16;
	if (keycode == 2 /*&& param->img.x - 2 <  0 && param->img.y - 2 < 0*/)
		param->img.x += 16;
	if (keycode == 13 /*&& param->img.x - 2 <  0 && param->img.y - 2 < 0*/)
		param->img.y -= 16;
	if (keycode == 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, param->img3.img, param->img.x, param->img.y);
	if (param->anim % 6 / 2 == 0 && keycode != 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, param->img.img, param->img.x, param->img.y);
	if (param->anim % 6 / 2 != 0 && keycode != 1)
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, param->img2.img, param->img.x, param->img.y);
	param->anim ++;
	return (0);
}

int	ft_display_map(char **map, t_prog *param)
{
	int			img_width;
	int			img_height;
	int			x;
	int			y;
	
	param->ground.x = 0;
	param->ground.y = 0;
	y = 0;
	param->ground.img = mlx_xpm_file_to_image(param->mlx.mlx, "road.xpm", &img_width, &img_height);
	while (map[y])
	{
		x = 0;
		printf("test\n");
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, param->ground.img, param->ground.x, param->ground.y);
			/*if (map[y][x]) == '0')
			  place_holrder*/
			x ++;
			param->ground.x += 64;
		}
		param->ground.x += 64;
		mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, param->ground.img, param->ground.x, param->ground.y);
		y ++;
		param->ground.y += 64;
		printf("y = %d\n", param->ground.y);
	}
	return (0);
}

int ft_sqr_check(char *map_line)
{
	int i;

	i = 0;
	if (!map_line)
		return (0);
	while (map_line[i])
		i ++;
	return (i);
}

int main ()
{
	t_prog		param;
	int			img_width;
	int			img_height;
	int			i;
	int square_check;
	int lines;
	char **map;
	char *map_line;
	int fd = open("./map.ber", O_RDONLY);

	lines = line_ct();
	map = malloc(lines * sizeof(char **));
	i = 0;
	while (i < lines)
	{
		map_line = get_next_line(fd);
		map[i] = map_line;
		i ++;
	}
	map[i] = 0;
	i = 1;
	square_check = ft_sqr_check(map[0]);
	while (map[i])
	{
		if (square_check != ft_sqr_check(map[i]))
		{
			printf("Error, map is not a square, did you skip geometry classes ?\n");
			exit (0);
		}
		i ++;
	}
	param.img.x = 0;
	param.img.y = 0;
	param.mlx.mlx = mlx_init();
	param.mlx.win = mlx_new_window(param.mlx.mlx, 64 *square_check, 64 *square_check, "Onsemmerde.com");
	param.img.img = mlx_xpm_file_to_image(param.mlx.mlx, "pingu2-64.xpm", &img_width, &img_height);
	param.img2.img = mlx_xpm_file_to_image(param.mlx.mlx, "pingu1-64.xpm", &img_width, &img_height);
	param.img3.img = mlx_xpm_file_to_image(param.mlx.mlx, "pingu3-64.xpm", &img_width, &img_height);


	mlx_put_image_to_window(param.mlx.mlx, param.mlx.win, param.img.img, param.img.x, param.img.y);
	ft_display_map(map, &param);
	mlx_hook(param.mlx.win, 2, 0, move, &param);

	param.ground.img = mlx_xpm_file_to_image(param.mlx.mlx, "road.xpm", &img_width, &img_height);
	mlx_put_image_to_window(param.mlx.mlx, param.mlx.win, param.ground.img, param.ground.x, param.ground.y);
	mlx_loop(param.mlx.mlx);
	ft_free_char(map);
	return (0);
}
