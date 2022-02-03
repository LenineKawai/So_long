/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adversaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:43:42 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/02 12:07:47 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_black_blocks
{
	int		x;
	int		y;
	void	*a_ref;
	void	*next;
}				t_bb;

t_bb	*ft_lstnew(int y, int x, t_prg *prg)
{
	t_bb	*block;
	int		h;
	int		w;

	block = malloc(sizeof(t_bb));
	if (!block)
		return (0);
	block->x = x;
	block->y = y;
	block->a_ref = mlx_xpm_to_image(prg->mlx, BB1, &w, &h);
	block->next == NULL;
	return (block);
}

void	ft_add_back(t_bb **alpha, t_bb *newb)
{
	t_bb *tmp;

	if (!alpha || !newb)
		return ;
	else if (!*alpha)
	{
		*alpha = newb;
		return ;
	}
	else
	{
		tmp = ft_last(*alpha);
		tmp->next = newb;
	}

}

void	ft_black_block_maker(int y, int x, t_prg *prg)
{
	t_bb	block;

	block = ft_lstnew(y, x, prg);
	ft_add_back(prg->&Alist, &block);
}
