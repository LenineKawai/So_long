/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_set_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolinva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:19:54 by mgolinva          #+#    #+#             */
/*   Updated: 2022/02/03 16:01:51 by mgolinva         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_texture_set_up(t_prg *prg)
{
	int w;
	int h;

	prg->grd.i_ref = mlx_xpm_file_to_image(prg->mlx, R, &w, &h);
	prg->rdS.i_ref = mlx_xpm_file_to_image(prg->mlx, ERS, &w, &h);
	prg->cNW.i_ref = mlx_xpm_file_to_image(prg->mlx, CNW, &w, &h);
	prg->cNE.i_ref = mlx_xpm_file_to_image(prg->mlx, CNE, &w, &h);
	prg->cSE.i_ref = mlx_xpm_file_to_image(prg->mlx, CSE, &w, &h);
	prg->cSW.i_ref = mlx_xpm_file_to_image(prg->mlx, CSW, &w, &h);
	prg->rdN.i_ref = mlx_xpm_file_to_image(prg->mlx, ERN, &w, &h);
	prg->wal.i_ref = mlx_xpm_file_to_image(prg->mlx, W, &w, &h);
	prg->wlW.i_ref = mlx_xpm_file_to_image(prg->mlx, WLW, &w, &h);
	prg->wlE.i_ref = mlx_xpm_file_to_image(prg->mlx, WLE, &w, &h);
	prg->col.i_ref = mlx_xpm_file_to_image(prg->mlx, C, &w, &h);
	prg->ext.i_ref = mlx_xpm_file_to_image(prg->mlx, E, &w, &h);
	prg->per.fac = mlx_xpm_file_to_image(prg->mlx, PF, &w, &h);
	prg->per.faL = mlx_xpm_file_to_image(prg->mlx, PFL, &w, &h);
	prg->per.faR = mlx_xpm_file_to_image(prg->mlx, PFR, &w, &h);
	prg->per.bck = mlx_xpm_file_to_image(prg->mlx, PB, &w, &h);
	prg->per.bks = mlx_xpm_file_to_image(prg->mlx, PBS, &w, &h);
	prg->per.lft = mlx_xpm_file_to_image(prg->mlx, PL, &w, &h);
	prg->per.lfI = mlx_xpm_file_to_image(prg->mlx, PIL, &w, &h);
	prg->per.rgt = mlx_xpm_file_to_image(prg->mlx, PR, &w, &h);
	prg->per.rgI = mlx_xpm_file_to_image(prg->mlx, PIR, &w, &h);
}

void	ft_anim_set_up(t_prg *prg)
{
	int w;
	int h;
	prg->cga.i_ref = mlx_xpm_file_to_image(prg->mlx, ACGT, &w, &h);
	prg->cga2.i_ref = mlx_xpm_file_to_image(prg->mlx, A2CGT, &w, &h);
	prg->extA.i_ref = mlx_xpm_file_to_image(prg->mlx, EA, &w, &h);
	prg->coA.i_ref = mlx_xpm_file_to_image(prg->mlx, CA1, &w, &h);
	prg->coA2.i_ref = mlx_xpm_file_to_image(prg->mlx, CA2, &w, &h);
	prg->blk1.i_ref = mlx_xpm_file_to_image(prg->mlx, BB1, &w, &h);
	prg->blkr.i_ref = mlx_xpm_file_to_image(prg->mlx, BBR, &w, &h);
	prg->blk2.i_ref = mlx_xpm_file_to_image(prg->mlx, BB2, &w, &h);
	prg->blk3.i_ref = mlx_xpm_file_to_image(prg->mlx, BB3, &w, &h);
	prg->los.i_ref = mlx_xpm_file_to_image(prg->mlx, L, &w, &h);
}
