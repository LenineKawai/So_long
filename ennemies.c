/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:08:00 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/03 15:13:48 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_ennemy_set(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (map[i][j] == 'A')
			{
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
						co.x, co.y);
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blk1.i_ref,
						co.x, co.y);
			}	
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}	
}

static void ft_ennemy_left(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (map[i][j] == 'A')
			{
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
						co.x, co.y);
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blk2.i_ref,
						co.x, co.y);
			}	
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}	
}

static void ft_ennemy_right(char **map, t_prg *prg, int i, int j)
{
	t_coo	co;

	ft_init(&co.x, &co.y);
	while (map [i])
	{
		ft_init(&j, &co.x);
		while (map[i][j])
		{
			if (map[i][j] == 'A')
			{
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
						co.x, co.y);
				mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blk1.i_ref,
						co.x, co.y);
			}	
			ft_scotch(&j, &co.x);
		}
		ft_scotch(&i, &co.y);
	}	
}

void	ft_anim_ennemy(t_prg *prg)
{
	if (prg->anim_en_an == 1000)
	{
		if (prg->anim_stat_a == 0)
		{
			ft_ennemy_set(prg->map, prg, 0, 0);
			prg->anim_stat_a = 1;
		}
		else if (prg->anim_stat_a == 1)
		{
			ft_ennemy_left(prg->map, prg, 0, 0);
			prg->anim_stat_a = 2;
		}
		else if (prg->anim_stat_a == 2)
		{
			ft_ennemy_right(prg->map, prg, 0, 0);
			prg->anim_stat_a = 0;
		}
		prg->anim_en_an = 0;
	}
	prg->anim_en_an ++;
}

void	ft_move_ennemy(t_prg *prg)
{
	static int	i;
	static int	j;

	if (i >= prg->win.hgt - 1 || j < 0)
		i = 0;
	if (prg->anim_a == 5000)
	{
		while (prg->map[i])
		{
			if (j >= prg->win.wid || j < 0)
				j = 0;
			while (prg->map[i][j] && prg->en_stat == 0)
			{
				if (prg->map[i][j] == 'A' && prg->map[i][j + 1] == '0')
				{
					mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blk1.i_ref,
							(j + 1) * 64, i * 64);
					mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
							j  * 64, i * 64);
					prg->map[i][j] = '0';
					prg->map[i][j + 1] = 'A';
					if (prg->map[i][j + 2] != '0')
						prg->en_stat = 1;
					break;
				}
				j ++;
			}
			while (prg->map[i][j] && prg->en_stat == 1)
				{
					if (prg->map[i][j] == 'A' && prg->map[i][j - 1] == '0')
					{
						mlx_put_image_to_window(prg->mlx, prg->win.win, prg->blkr.i_ref,
							(j - 1) * 64, i * 64);
						mlx_put_image_to_window(prg->mlx, prg->win.win, prg->grd.i_ref,
							j  * 64, i * 64);
						prg->map[i][j] = '0';
						prg->map[i][j - 1] = 'A';
						if (prg->map[i][j - 2] != '0')
							prg->en_stat = 0;
						break;
					}
					j ++;
				}
			i ++;
		}
		prg->anim_a = 0;
	}
	prg->anim_a ++;
}
