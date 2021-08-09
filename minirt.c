/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:34 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/22 14:16:04 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		parse_lights(t_scene *scene, t_vector p,
							t_vector n, t_vector *color)
{
	t_list		*lights;
	t_light		*light;
	t_vector	l;
	float		i;
	float		diff;

	lights = (scene->lights);
	while (lights)
	{
		light = lights->content;
		i = scene->amb.intensity / 10;
		l = vec_subtract((*light).position, p);
		if (check_shadows(scene, p, l))
		{
			*color = int_light(*color, (*light), i, &lights);
			continue;
		}
		if ((diff = vec_dot(n, l)) < 0)
			diff = -diff;
		if (diff > 0)
			i += (*light).intensity * diff / (vec_len(n) * vec_len(l));
		*color = int_light(*color, (*light), i, &lights);
	}
}

t_vector		compute_light(t_scene *scene, t_vector p,
								t_vector n, t_figure fig)
{
	t_vector	color;

	color = new_vector(0, 0, 0);
	parse_lights(scene, p, n, &color);
	color = int_amb(color, scene->amb, fig.clr);
	return (color);
}
