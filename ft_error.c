/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 19:24:28 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/18 19:25:32 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_error(char *error, char **elems)
{
	wrapper(elems);
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit(0);
}
