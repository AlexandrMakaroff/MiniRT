/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:40 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/19 14:32:53 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amb		new_amb(float intensity, t_vector color)
{
	t_amb	amb;

	amb.intensity = intensity;
	amb.color = color;
	return (amb);
}

t_light		new_light(float intensity, t_vector position, t_vector color)
{
	t_light	light;

	light.intensity = intensity;
	light.position = position;
	light.color = color;
	return (light);
}

t_camera	new_camera(t_vector origin, t_vector direction, float fov)
{
	t_camera	new_cam;

	direction.z = -direction.z;
	new_cam.origin = origin;
	new_cam.direction = direction;
	new_cam.fov = fov;
	return (new_cam);
}
