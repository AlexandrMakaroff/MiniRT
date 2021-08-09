/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:48:02 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/19 19:12:19 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	vec_normalize(t_vector vec)
{
	t_vector	norm;
	float		len;

	len = vec_len(vec);
	norm = new_vector(vec.x / len, vec.y / len, vec.z / len);
	return (norm);
}

float		vec_dot(t_vector v1, t_vector v2)
{
	float	res;

	res = (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
	return (res);
}

t_vector	vec_dot_const(float c, t_vector v)
{
	t_vector	res;

	res.x = v.x * c;
	res.y = v.y * c;
	res.z = v.z * c;
	return (res);
}

t_vector	vec_dot_secure(float c, t_vector v)
{
	t_vector	res;

	if (255 < (res.x = v.x * c))
		res.x = 255;
	else if ((res.x = v.x * c) < 0)
		res.x = 0;
	if (255 < (res.y = v.y * c))
		res.y = 255;
	else if ((res.y = v.y * c) < 0)
		res.y = 0;
	if (255 < (res.z = v.z * c))
		res.z = 255;
	else if ((res.z = v.z * c) < 0)
		res.z = 0;
	return (res);
}

int			vec_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b << 0);
}
