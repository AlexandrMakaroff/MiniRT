/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chec_elems2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 20:08:37 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/20 20:09:13 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_valid_line_2(char **elems, t_vars *all, int *nec)
{
	if (!ft_strncmp(elems[0], "A", 2))
		check_ambient(elems, all, nec);
	else if (!ft_strncmp(elems[0], "c", 2))
		check_camera(elems, all, nec);
	else if (!ft_strncmp(elems[0], "l", 2))
		check_light(elems, all);
	else if (!ft_strncmp(elems[0], "sp", 3))
		check_sp(elems, all);
	else if (!ft_strncmp(elems[0], "pl", 3))
		check_pl(elems, all);
	else if (!ft_strncmp(elems[0], "tr", 3))
		check_tr(elems, all);
	else if (!ft_strncmp(elems[0], "sq", 3))
		check_sq(elems, all);
	else if (!ft_strncmp(elems[0], "cy", 3))
		check_cy(elems, all);
	else if (ft_strncmp(elems[0], "#", 1))
		ft_error("Not valid identifier", elems);
}
