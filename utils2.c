/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:58 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/22 14:09:20 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	multyply_by_look_at(t_vector orig, t_vector dir, t_vector ray)
{
	t_vector	right;
	t_vector	up;
	t_vector	new_ray;

	dir.x = -dir.x;
	dir.y = -dir.y;
	up = new_vector(0, 1, 0);
	right = vec_cross(new_vector(1, 0, 0), dir);
	if (!(dir.y == 1 || dir.y == -1))
		right = vec_cross(up, dir);
	up = vec_cross(dir, right);
	new_ray = new_vector(0, 0, 0);
	new_ray.x = (ray.x * right.x) + (ray.y * up.x) + (ray.z * dir.x) + orig.x;
	new_ray.y = (ray.x * right.y) + (ray.y * up.y) + (ray.z * dir.y) + orig.y;
	new_ray.z = (ray.x * right.z) + (ray.y * up.z) + (ray.z * dir.z) + orig.z;
	return (new_ray);
}

t_vector	int_light(t_vector color, t_light svet, float i, t_list **lights)
{
	t_vector	vec;

	if (i > 1)
		i = 1;
	vec = new_vector(svet.color.x / 255, svet.color.y / 255,
	svet.color.z / 255);
	vec = vec_dot_secure(i, vec_dot_secure(svet.intensity, vec));
	color = vec_addition_secure(color, vec);
	*lights = (*lights)->next;
	return (color);
}

t_vector	int_amb(t_vector color, t_amb amb, t_vector fig_clr)
{
	t_vector	vec;

	vec = new_vector(amb.color.x / 255, amb.color.y / 255, amb.color.z / 255);
	vec = vec_dot_secure(amb.intensity, vec);
	color = vec_addition_secure(color, vec);
	color = new_vector(color.x * fig_clr.x, color.y * fig_clr.y,
						color.z * fig_clr.z);
	if (color.x >= 255)
		color.x = 255;
	if (color.y >= 255)
		color.y = 255;
	if (color.z >= 255)
		color.z = 255;
	return (color);
}

int			check_shadows(t_scene *scene, t_vector p, t_vector l)
{
	t_list		*figures;
	t_figure	*fig;
	float		t;

	t = 0;
	figures = (scene->figures);
	while (figures)
	{
		fig = figures->content;
		if (!(ft_strncmp(fig->type, "sp", 2)))
			t = sphere_inter(p, l, *fig);
		else if (!(ft_strncmp(fig->type, "pl", 2)))
			t = plane_inter(p, l, *fig);
		else if (!(ft_strncmp(fig->type, "tr", 2)))
			t = triangle_inter(p, l, *fig);
		else if (!(ft_strncmp(fig->type, "sq", 2)))
			t = square_inter(p, l, *fig);
		else if (!(ft_strncmp(fig->type, "cy", 2)))
			t = cylinder_inter(p, l, *fig);
		if (t > 0 && t < 0.9999)
			return (1);
		figures = figures->next;
	}
	return (0);
}

int			is_int_str(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}
