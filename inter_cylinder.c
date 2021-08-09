/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:26 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/18 20:11:58 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		cylinder_norm(t_vector p, t_figure fig)
{
	t_vector	op;
	t_vector	normal;

	op = vec_subtract(p, fig.center);
	normal = vec_subtract(op, vec_dot_const(vec_dot(op, fig.normal),
														fig.normal));
	normal = vec_normalize(normal);
	return (normal);
}

static float	calc_t(t_vector orig, t_vector dir,
						t_figure cylinder, float *t2)
{
	float		a;
	float		b;
	t_vector	dir_norm;
	t_vector	co_norm;
	float		discr;

	dir_norm = vec_cross(dir, cylinder.normal);
	co_norm = vec_cross(vec_subtract(orig, cylinder.center),
											cylinder.normal);
	a = vec_dot(dir_norm, dir_norm);
	b = 2 * vec_dot(dir_norm, co_norm);
	discr = b * b - (4 * a * (vec_dot(co_norm, co_norm)
	- (cylinder.radius * cylinder.radius) *
	vec_dot(cylinder.normal, cylinder.normal)));
	if (discr < 0)
		return (0);
	a = 2 * a;
	discr = sqrt(discr);
	*t2 = (-b + discr) / a;
	return ((-b - discr) / a);
}

static float	restriction(t_vector orig, t_vector dir,
								t_figure cylinder, float t)
{
	t_vector	p;
	float		h;

	p = vec_addition(orig, vec_dot_const(t, dir));
	h = vec_dot(cylinder.normal, vec_subtract(p, cylinder.center));
	if (-cylinder.height / 2 <= h && h <= cylinder.height / 2 && t > 0)
		return (t);
	return (0);
}

float			cylinder_inter(t_vector orig, t_vector dir, t_figure cylinder)
{
	float		t1;
	float		t2;

	t1 = 0;
	t2 = 0;
	t1 = calc_t(orig, dir, cylinder, &t2);
	if (restriction(orig, dir, cylinder, t1))
		return (t1);
	if (restriction(orig, dir, cylinder, t2))
		return (t2);
	return (0);
}
