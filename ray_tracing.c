/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:44 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/18 13:59:07 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	get_ray(float x, float y, t_scene *scene)
{
	t_vector	ray;

	ray = new_vector(x, y, -1);
	ray = multyply_by_look_at(scene->camera.origin,
						scene->camera.direction, ray);
	ray = vec_subtract(ray, scene->camera.origin);
	ray = vec_normalize(ray);
	return (ray);
}

void			ray_tracing(void *mlx, void *win, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x;
	float		y;
	t_vplane	view;

	mlx_y = 0;
	view = get_view_plane(scene->width, scene->hight, scene->camera.fov);
	y = (scene->hight / 2);
	while (y > (scene->hight / 2) * (-1))
	{
		x = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x < (scene->width / 2))
		{
			my_mlx_pixel_put(&scene->img, mlx_x, mlx_y, trace_ray(scene,
			get_ray(x * view.x_pix, y * view.y_pix, scene), scene->figures));
			x++;
			mlx_x++;
		}
		y--;
		mlx_y++;
	}
	mlx_put_image_to_window(mlx, win, scene->img.img, 0, 0);
}
