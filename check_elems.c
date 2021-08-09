/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:22 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/22 14:23:59 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		check_rotation(char **elems, t_vars *all, int *nec)
{
	static int	r;
	int			x;
	int			y;

	r += 1;
	if (count_elems(elems) > 3)
		ft_error("ERROR: Invalid number of information arguments", elems);
	mlx_get_screen_size(&x, &y);
	if (!is_int_str(elems[1]) || !is_int_str(elems[2]))
		ft_error("Argument must be integer", elems);
	if (r > 1)
		ft_error("ERROR: One or more required arguments are missing", elems);
	if ((all->scene.width = ft_atoi(elems[1])) <= 0)
		ft_error("ERROR: The resolution cannot be negative or null", elems);
	if ((all->scene.hight = ft_atoi(elems[2])) <= 0)
		ft_error("ERROR: The resolution cannot be negative or null", elems);
	if (all->scene.save != 1)
	{
		if (all->scene.width > x)
			all->scene.width = x;
		if (all->scene.hight > y)
			all->scene.hight = y;
	}
	(*nec)++;
}

void		check_ambient(char **elems, t_vars *all, int *nec)
{
	static int	r;

	r += 1;
	if (r > 1)
		ft_error("One or more required arguments are missing", elems);
	if (count_elems(elems) != 3)
		ft_error("Invalid number of information arguments", elems);
	if (!is_float_str(elems[1]))
		ft_error("Argument must be float", elems);
	all->scene.amb.intensity = ft_atof(elems[1]);
	if (all->scene.amb.intensity > 1 || all->scene.amb.intensity < 0)
		ft_error("Ambient lighting must have a value from 0 to 1", elems);
	all->scene.amb.color = set_color(elems[2], elems);
	(*nec)++;
}

void		check_camera(char **elems, t_vars *all, int *nec)
{
	static int	r;
	t_camera	*cam;

	if (count_elems(elems) != 4)
		ft_error("Invalid number of information arguments", elems);
	if (!is_float_str(elems[3]))
		ft_error("FOV must be float", elems);
	if (!(cam = (t_camera*)malloc(sizeof(t_camera))))
		ft_error("Memory allocation error", elems);
	*cam = new_camera(set_vector(elems[1], elems), set_normal(elems[2], elems),
			ft_atof(elems[3]));
	if (cam->fov < 0 || cam->fov > 180)
		ft_error("FOV must have a value from 0 to 180", elems);
	ft_dlst_add(&all->cams, ft_dlst_new(cam));
	if (!r)
	{
		r++;
		(*nec)++;
	}
}

void		check_light(char **elems, t_vars *all)
{
	t_light	*light;

	if (count_elems(elems) != 4)
		ft_error("Invalid number of information arguments", elems);
	if (!(light = (t_light*)malloc(sizeof(t_light))))
		ft_error("Memory allocation error", elems);
	*light = new_light(ft_atof(elems[2]), set_vector(elems[1], elems),
			set_color(elems[3], elems));
	if (light->intensity < 0 || light->intensity > 1)
		ft_error("The light brightness have a ratio from 0 to 1", elems);
	ft_lstadd_back(&all->scene.lights, ft_lstnew(light));
}

void		check_valid_line(char *line, t_vars *all, int *nec)
{
	char	**elems;

	if (!ft_strncmp(line, "", 1) || !ft_strncmp(line, " ", 1))
		return ;
	if (!(elems = ft_split(line, ' ')))
		ft_error("Memory allocation error", elems);
	if (!ft_strncmp(elems[0], "R", 2))
		check_rotation(elems, all, nec);
	else
		check_valid_line_2(elems, all, nec);
	wrapper(elems);
}
