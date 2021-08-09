/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:43 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/20 16:11:21 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_valid_scene(char **scene, t_vars *all)
{
	int		i;
	int		nec;

	i = 0;
	nec = 0;
	while (scene[i])
	{
		check_valid_line(scene[i], all, &nec);
		i++;
	}
	if (nec < 3)
		ft_errno("ERROR: One or more required arguments are missing");
}

char	**init_scene(t_list **head, int size)
{
	char	**scene;
	int		i;
	t_list	*tmp;

	if (!(scene = ft_calloc(size + 1, sizeof(char*))))
		ft_errno("Memory allocation error");
	i = 0;
	tmp = *head;
	while (tmp)
	{
		scene[i++] = tmp->content;
		tmp = tmp->next;
	}
	return (scene);
}

void	third_part(t_vars *all)
{
	mlx_hook(all->win, 2, 1L << 0, change_cam, all);
	mlx_hook(all->win, 17, 1L << 0, ft_close, all);
	mlx_loop(all->mlx);
}

void	second_part(t_vars *all, int fd, char *line, t_list *head)
{
	char	**scene;

	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(line));
	scene = init_scene(&head, ft_lstsize(head));
	check_valid_scene(scene, all);
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, all->scene.width,
						all->scene.hight, "Window");
	all->scene.img.img = mlx_new_image(all->mlx, all->scene.width,
						all->scene.hight);
	all->scene.img.addr = mlx_get_data_addr(all->scene.img.img,
						&all->scene.img.bits_per_pixel,
						&all->scene.img.line_length, &all->scene.img.endian);
	all->scene.camera = *((t_camera*)all->cams->content);
	ray_tracing(all->mlx, all->win, &all->scene);
	if (all->scene.save == 1)
		save(all);
	third_part(all);
}

int		main(int argc, char *argv[])
{
	int		fd;
	t_vars	*all;
	char	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	if (argc < 2 || argc > 3)
		ft_errno("ERROR: Wrong number of arguments");
	if (ft_strrncmp(argv[1], ".rt", 3))
		ft_errno("Not valid the second argument");
	if (!(all = (t_vars*)malloc(sizeof(t_vars))))
		ft_errno("Memory allocation error");
	all->cams = NULL;
	fd = open(argv[1], 0, O_RDONLY);
	all->scene.save = 0;
	if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			ft_errno("Invalid third argument");
		all->scene.save = 1;
	}
	second_part(all, fd, line, head);
	return (0);
}
