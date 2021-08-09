/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_pl_sq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:28 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:47:29 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float		plane_inter(t_vector r, t_vector l, t_figure plane)
{
	float		t;
	float		d;
	t_vector	n;

	n = plane.normal;
	n = vec_normalize(n);
	d = -vec_dot(plane.center, n);
	t = -((vec_dot(r, n) + d) / (vec_dot(l, n)));
	if (t > 0)
		return (t);
	return (0);
}

float		square_inter(t_vector orig, t_vector dir, t_figure square)
{
	float		a;
	float		b;
	float		t1;
	float		t2;
	t_vector	d;

	a = vec_dot(vec_subtract(orig, square.center), square.normal);
	b = vec_dot(dir, square.normal);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t1 = -(a / b);
	d = vec_subtract(vec_addition(vec_dot_const(t1, dir), orig), square.center);
	t2 = square.side_size / 2;
	if (fabs(d.x) > t2 || fabs(d.y) > t2 || fabs(d.z) > t2)
		return (0);
	if (t1 > 0)
		return (t1);
	return (0);
}
