/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:20 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/18 20:12:21 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	key_right(t_vars *vars)
{
	t_camera	*cam;
	t_scene		scene;

	scene = vars->scene;
	if (vars->cams->next)
		(vars->cams) = (vars->cams)->next;
	cam = (vars->cams)->content;
	mlx_clear_window(vars->mlx, vars->win);
	scene.camera = *cam;
	scene.img.img = mlx_new_image(vars->mlx, scene.width, scene.hight);
	scene.img.addr = mlx_get_data_addr(scene.img.img, &scene.img.bits_per_pixel,
						&scene.img.line_length, &scene.img.endian);
	ray_tracing(vars->mlx, vars->win, &scene);
}

static void	key_left(t_vars *vars)
{
	t_camera	*cam;
	t_scene		scene;

	scene = vars->scene;
	if (vars->cams->next)
		(vars->cams) = (vars->cams)->previous;
	cam = (vars->cams)->content;
	mlx_clear_window(vars->mlx, vars->win);
	scene.camera = *cam;
	scene.img.img = mlx_new_image(vars->mlx, scene.width, scene.hight);
	scene.img.addr = mlx_get_data_addr(scene.img.img, &scene.img.bits_per_pixel,
						&scene.img.line_length, &scene.img.endian);
	ray_tracing(vars->mlx, vars->win, &scene);
}

int			change_cam(int key, t_vars *vars)
{
	if (key == ESC)
		ft_close(vars);
	if (key == RIGHT)
		key_right(vars);
	if (key == LEFT)
		key_left(vars);
	return (0);
}
