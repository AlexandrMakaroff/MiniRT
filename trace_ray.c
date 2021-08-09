/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:54 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/21 03:56:21 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	inter(t_scene *scene, t_vector ray, t_figure *fig, t_vector *n)
{
	float		t;

	t = 0.0;
	if (!(ft_strncmp(fig->type, "pl", 2)))
	{
		t = plane_inter(scene->camera.origin, ray, *fig);
		*n = vec_normalize((*fig).normal);
	}
	else if (!(ft_strncmp(fig->type, "tr", 2)))
	{
		t = triangle_inter(scene->camera.origin, ray, *fig);
		*n = triangle_norm((*fig).first, (*fig).second, (*fig).third);
	}
	else if (!(ft_strncmp(fig->type, "sq", 2)))
	{
		t = square_inter(scene->camera.origin, ray, *fig);
		*n = vec_normalize((*fig).normal);
	}
	else if (!(ft_strncmp(fig->type, "cy", 2)))
	{
		t = cylinder_inter(scene->camera.origin, ray, *fig);
		*n = vec_normalize(cylinder_norm(vec_addition(scene->camera.origin,
								vec_dot_const(t * 0.99999, ray)), *fig));
	}
	return (t);
}

static float	inter_sp(t_scene *scene, t_vector ray,
							t_figure *fig, t_vector *n)
{
	float		t;

	t = 0.0;
	t = sphere_inter(scene->camera.origin, ray, *fig);
	*n = vec_normalize(vec_subtract(vec_addition(scene->camera.origin,
					vec_dot_const(t * 0.99999, ray)), (*fig).center));
	return (t);
}

int				trace_ray(t_scene *scene, t_vector ray, t_list *figures)
{
	float		t;
	t_figure	*fig;
	t_vector	n;
	t_vector	color;
	float		min;

	min = 999999;
	while (figures)
	{
		fig = figures->content;
		if (!(ft_strncmp(fig->type, "sp", 2)))
			t = inter_sp(scene, ray, fig, &n);
		else
			t = inter(scene, ray, fig, &n);
		if (t > 0 && vec_len(vec_subtract(vec_addition(scene->camera.origin,
				vec_dot_const(t * 0.99999, ray)), scene->camera.origin)) < min)
		{
			min = vec_len(vec_subtract(vec_addition(scene->camera.origin,
					vec_dot_const(t * 0.99999, ray)), scene->camera.origin));
			color = compute_light(scene, vec_addition(scene->camera.origin,
			vec_dot_const(t * 0.99999, ray)), n, *fig);
		}
		figures = figures->next;
	}
	return (vec_to_int(color.x, color.y, color.z));
}
