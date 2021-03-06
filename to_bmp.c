/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:51 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:47:52 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fatal(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(0);
}

static void	transfer(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void	bmp_hdr(t_vars *all, int file_size, int fd)
{
	unsigned char	btr[54];

	ft_bzero(btr, 54);
	btr[0] = (unsigned char)('B');
	btr[1] = (unsigned char)('M');
	transfer(file_size, btr + 2);
	btr[10] = (unsigned char)(54);
	btr[14] = (unsigned char)(40);
	transfer(all->scene.width, btr + 18);
	transfer(all->scene.hight, btr + 22);
	btr[26] = (unsigned char)(1);
	btr[28] = (unsigned char)(24);
	write(fd, btr, 54);
}

static void	get_pxl(t_vars *all, int fd)
{
	int	i;
	int	j;
	int	cvet;

	i = all->scene.hight - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < all->scene.width)
		{
			cvet = *(int*)(all->scene.img.addr + (i * all->scene.img.line_length
			+ j * (all->scene.img.bits_per_pixel / 8)));
			write(fd, &cvet, 3);
		}
		i--;
	}
}

void		save(t_vars *all)
{
	int	fd;
	int	limb;

	while (all->scene.width % 4 != 0)
		all->scene.width--;
	limb = 54 + (4 * all->scene.hight * all->scene.width);
	if (!(fd = open("screen.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, 0666)))
		fatal("bad open");
	bmp_hdr(all, limb, fd);
	get_pxl(all, fd);
	close(fd);
	exit(0);
}
