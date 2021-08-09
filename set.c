/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:46 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/20 19:40:42 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	set_color(char *elem, char **elems)
{
	char		**rgb;
	t_vector	color;

	if (!(rgb = ft_split(elem, ',')))
		ft_errno("Memory allocation error");
	if ((elem[ft_strlen(elem) - 1] == ',') || count_elems(rgb) != 3 ||
	!is_int_str(rgb[0]) || !is_int_str(rgb[1]) || !is_int_str(rgb[2]))
	{
		wrapper(rgb);
		ft_error("Color must contain 3 integers", elems);
	}
	color.x = ft_atoi(rgb[0]);
	color.y = ft_atoi(rgb[1]);
	color.z = ft_atoi(rgb[2]);
	if (color.x > 255 || color.x < 0)
		ft_errno("ERROR: Invalid color value");
	if (color.y > 255 || color.y < 0)
		ft_errno("ERROR: Invalid color value");
	if (color.z > 255 || color.z < 0)
		ft_errno("ERROR: Invalid color value");
	wrapper(rgb);
	return (color);
}

t_vector	set_vector(char *elem, char **elems)
{
	t_vector	vector;
	char		**vec;

	vec = ft_split(elem, ',');
	if ((elem[ft_strlen(elem) - 1] == ',') || count_elems(vec) != 3 ||
	!is_float_str(vec[0]) || !is_float_str(vec[1]) || !is_float_str(vec[2]))
	{
		wrapper(vec);
		ft_error("Vector must contain 3 floats", elems);
	}
	vector.x = ft_atof(vec[0]);
	vector.y = ft_atof(vec[1]);
	vector.z = ft_atof(vec[2]);
	wrapper(vec);
	return (vector);
}

t_vector	set_normal(char *elem, char **elems)
{
	t_vector	normal;
	char		**norm;

	norm = ft_split(elem, ',');
	if ((elem[ft_strlen(elem) - 1] == ',') || count_elems(norm) != 3 ||
	!is_float_str(norm[0]) || !is_float_str(norm[1]) || !is_float_str(norm[2]))
	{
		wrapper(norm);
		ft_error("Normal must contain 3 floats", elems);
	}
	normal.x = ft_atof(norm[0]);
	normal.y = ft_atof(norm[1]);
	normal.z = ft_atof(norm[2]);
	if (normal.x > 1 || normal.x < -1)
		ft_errno("ERROR: Normalized \
orientation vector must have a value from -1 to 1");
	if (normal.y > 1 || normal.y < -1)
		ft_errno("ERROR: Normalized \
orientation vector must have a value from -1 to 1");
	if (normal.z > 1 || normal.z < -1)
		ft_errno("ERROR: Normalized \
orientation vector must have a value from -1 to 1");
	wrapper(norm);
	return (normal);
}

int			is_float_str(char *str)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')
			return (0);
		if (str[i] == '.')
		{
			if (!str[i + 1] || !ft_isdigit(str[i + 1]) || f == 1)
				return (0);
			f = 1;
		}
		i++;
	}
	return (1);
}
