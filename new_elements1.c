/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elements1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:38 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:51:37 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	new_vector(float x, float y, float z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

t_figure	new_sphere(t_vector center, float radius, t_vector clr)
{
	t_figure	figure;

	figure.type = "sp";
	figure.radius = radius;
	figure.height = 0;
	figure.side_size = 0;
	figure.center = center;
	figure.clr = clr;
	return (figure);
}

t_figure	new_plane(t_vector center, t_vector normal, t_vector clr)
{
	t_figure	figure;

	figure.type = "pl";
	figure.radius = 0;
	figure.height = 0;
	figure.side_size = 0;
	figure.center = center;
	figure.normal = normal;
	figure.clr = clr;
	return (figure);
}

t_figure	new_triangle(t_vector first, t_vector second,
							t_vector third, t_vector clr)
{
	t_figure	figure;

	figure.type = "tr";
	figure.radius = 0;
	figure.height = 0;
	figure.side_size = 0;
	figure.first = first;
	figure.second = second;
	figure.third = third;
	figure.clr = clr;
	return (figure);
}

t_figure	new_square(t_vector center, t_vector normal,
						float side_size, t_vector clr)
{
	t_figure	figure;

	figure.type = "sq";
	figure.radius = 0;
	figure.height = 0;
	figure.side_size = side_size;
	figure.center = center;
	figure.normal = normal;
	figure.clr = clr;
	return (figure);
}
