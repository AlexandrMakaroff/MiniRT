/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:56 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/20 19:39:26 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		ft_errno(char *error)
{
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(0);
}

int			count_elems(char **elems)
{
	int i;

	i = 0;
	while (elems[i])
		i++;
	return (i);
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

t_vplane	get_view_plane(float width, float hight, float fov)
{
	t_vplane	view;
	float		asp_ratio;

	asp_ratio = width / hight;
	view.width = tan(fov / 2 * M_PI / 180) * 2;
	view.hight = view.width / asp_ratio;
	view.x_pix = view.width / width;
	view.y_pix = view.hight / hight;
	return (view);
}
