/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:30 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:47:31 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	discriminant(t_vector dir, t_figure sphere, t_vector oc)
{
	float		a;
	float		b;
	float		c;

	a = vec_dot(dir, dir);
	b = 2 * vec_dot(oc, dir);
	c = vec_dot(oc, oc) - (sphere.radius * sphere.radius);
	return ((b * b) - (4 * a * c));
}

static float	calc_d(float *d2, float disc, t_vector dir, t_vector oc)
{
	float	a;
	float	b;

	a = vec_dot(dir, dir);
	b = 2 * vec_dot(oc, dir);
	*d2 = ((-b) + sqrt(disc)) / (2 * a);
	return (((-b) - sqrt(disc)) / (2 * a));
}

float			sphere_inter(t_vector orig, t_vector dir, t_figure sphere)
{
	float		d1;
	float		d2;
	float		disc;
	t_vector	oc;

	d1 = 0;
	d2 = 0;
	oc = vec_subtract(orig, sphere.center);
	disc = discriminant(dir, sphere, oc);
	if (disc < 0)
		return (0);
	d1 = calc_d(&d2, disc, dir, oc);
	if (d1 > 0 && d2 > 0)
		return ((d1 > d2) ? d2 : d1);
	return ((d1 > d2) ? d1 : d2);
}
