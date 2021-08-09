/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:24 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/20 19:42:22 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_sp(char **elems, t_vars *all)
{
	t_figure	*sphere;

	if (count_elems(elems) != 4)
	{
		wrapper(elems);
		ft_errno("ERROR: Invalid number of information arguments");
	}
	if (!(sphere = (t_figure*)malloc(sizeof(t_figure))))
		ft_error("Memory allocation error", elems);
	if (!is_float_str(elems[2]))
		ft_error("Argument must be float", elems);
	*sphere = new_sphere(set_vector(elems[1], elems), ft_atof(elems[2]) / 2,
			set_color(elems[3], elems));
	if (sphere->radius <= 0)
	{
		wrapper(elems);
		ft_errno("ERROR: The sphere diameter can not be less or equal zero");
	}
	ft_lstadd_back(&all->scene.figures, ft_lstnew(sphere));
}

void	check_pl(char **elems, t_vars *all)
{
	t_figure	*plane;

	if (count_elems(elems) != 4)
	{
		wrapper(elems);
		ft_errno("ERROR: Invalid number of information arguments");
	}
	if (!(plane = (t_figure*)malloc(sizeof(t_figure))))
	{
		wrapper(elems);
		ft_errno("Memory allocation error");
	}
	*plane = new_plane(set_vector(elems[1], elems), set_normal(elems[2], elems),
			set_color(elems[3], elems));
	ft_lstadd_back(&all->scene.figures, ft_lstnew(plane));
}

void	check_sq(char **elems, t_vars *all)
{
	t_figure	*square;

	if (count_elems(elems) != 5)
	{
		wrapper(elems);
		ft_errno("ERROR: Invalid number of information arguments");
	}
	if (!(square = (t_figure*)malloc(sizeof(t_figure))))
	{
		wrapper(elems);
		ft_errno("Memory allocation error");
	}
	if (!is_float_str(elems[3]))
		ft_error("Argument must be float", elems);
	*square = new_square(set_vector(elems[1], elems),
							set_normal(elems[2], elems),
			ft_atof(elems[3]), set_color(elems[4], elems));
	if (square->side_size <= 0)
	{
		wrapper(elems);
		ft_errno("ERROR: The square side size can not be less or equal zero");
	}
	ft_lstadd_back(&all->scene.figures, ft_lstnew(square));
}

void	check_cy(char **elems, t_vars *all)
{
	t_figure	*cylinder;

	if (count_elems(elems) != 6)
	{
		wrapper(elems);
		ft_errno("ERROR: Invalid number of information arguments");
	}
	if (!is_float_str(elems[3]) || !is_float_str(elems[4]))
		ft_error("Argument must be float", elems);
	cylinder = (t_figure*)malloc(sizeof(t_figure));
	cylinder->type = "cy";
	cylinder->center = set_vector(elems[1], elems);
	cylinder->normal = set_normal(elems[2], elems);
	cylinder->radius = ft_atof(elems[3]) / 2;
	cylinder->height = ft_atof(elems[4]);
	cylinder->clr = set_color(elems[5], elems);
	if (cylinder->radius <= 0 || cylinder->height <= 0)
	{
		wrapper(elems);
		ft_errno("ERROR: The cylinder diameter \
and hight can't be less or equal zero");
	}
	ft_lstadd_back(&all->scene.figures, ft_lstnew(cylinder));
}

void	check_tr(char **elems, t_vars *all)
{
	t_figure	*triangle;

	if (count_elems(elems) != 5)
	{
		wrapper(elems);
		ft_errno("ERROR: Invalid number of information arguments");
	}
	if (!(triangle = (t_figure*)malloc(sizeof(t_figure))))
	{
		wrapper(elems);
		ft_errno("Memory allocation error");
	}
	*triangle = new_triangle(set_vector(elems[1], elems),
									set_vector(elems[2], elems),
			set_vector(elems[3], elems), set_color(elems[4], elems));
	ft_lstadd_back(&all->scene.figures, ft_lstnew(triangle));
}
