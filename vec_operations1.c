/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:59 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:48:00 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vec_addition(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	return (res);
}

t_vector	vec_addition_secure(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
	if (res.x > 255)
		res.x = 255;
	if (res.y > 255)
		res.y = 255;
	if (res.z > 255)
		res.z = 255;
	if (res.x < 0)
		res.x = 0;
	if (res.y < 0)
		res.y = 0;
	if (res.z < 0)
		res.z = 0;
	return (res);
}

t_vector	vec_subtract(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return (res);
}

t_vector	vec_cross(t_vector v1, t_vector v2)
{
	t_vector	res;

	res = new_vector(v1.y * v2.z - v1.z * v2.y,
						v1.z * v2.x - v1.x * v2.z,
							v1.x * v2.y - v1.y * v2.x);
	return (res);
}

float		vec_len(t_vector vec)
{
	float	len;

	len = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return (len);
}
