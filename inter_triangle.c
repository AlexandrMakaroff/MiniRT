/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:32 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:47:33 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	calc_u(t_vector orig, t_vector dir, t_figure triangle)
{
	t_vector	e1;
	t_vector	e2;
	float		det;
	t_vector	t_vec;
	t_vector	p_vec;

	e1 = vec_subtract(triangle.second, triangle.first);
	e2 = vec_subtract(triangle.third, triangle.first);
	t_vec = vec_subtract(orig, triangle.first);
	p_vec = vec_cross(dir, e2);
	det = vec_dot(e1, p_vec);
	if (det > -0.0001 && det < 0.0001)
		return (0);
	return (vec_dot(t_vec, p_vec) * (1 / det));
}

static float	calc_v(t_vector orig, t_vector dir, t_figure triangle)
{
	t_vector	e1;
	t_vector	e2;
	float		det;
	t_vector	q_vec;

	e1 = vec_subtract(triangle.second, triangle.first);
	e2 = vec_subtract(triangle.third, triangle.first);
	q_vec = vec_cross(vec_subtract(orig, triangle.first), e1);
	det = vec_dot(e1, vec_cross(dir, e2));
	if (det > -0.0001 && det < 0.0001)
		return (0);
	return (vec_dot(dir, q_vec) * (1 / det));
}

static float	calc_t(t_vector orig, t_vector dir, t_figure triangle)
{
	t_vector	e1;
	t_vector	e2;
	float		det;
	t_vector	q_vec;

	e1 = vec_subtract(triangle.second, triangle.first);
	e2 = vec_subtract(triangle.third, triangle.first);
	q_vec = vec_cross(vec_subtract(orig, triangle.first), e1);
	det = vec_dot(e1, vec_cross(dir, e2));
	if (det > -0.0001 && det < 0.0001)
		return (0);
	return (vec_dot(e2, q_vec) * (1 / det));
}

float			triangle_inter(t_vector orig, t_vector dir, t_figure triangle)
{
	t_vector	e1;
	t_vector	e2;
	float		t;
	float		u;
	float		v;

	e1 = vec_subtract(triangle.second, triangle.first);
	e2 = vec_subtract(triangle.third, triangle.first);
	u = calc_u(orig, dir, triangle);
	if (u < 0 || u > 1)
		return (0);
	v = calc_v(orig, dir, triangle);
	if (v < 0 || u + v > 1)
		return (0);
	t = calc_t(orig, dir, triangle);
	return (t);
}

t_vector		triangle_norm(t_vector p1, t_vector p2, t_vector p3)
{
	t_vector	normal;
	t_vector	v1;
	t_vector	v2;

	v1 = vec_subtract(p2, p1);
	v2 = vec_subtract(p3, p2);
	normal = vec_cross(v1, v2);
	normal = vec_normalize(normal);
	return (normal);
}
