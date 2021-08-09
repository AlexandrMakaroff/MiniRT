/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:48 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/17 20:58:59 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef struct		s_figure
{
	char			*type;
	float			radius;
	float			height;
	float			side_size;
	t_vector		center;
	t_vector		normal;
	t_vector		clr;
	t_vector		first;
	t_vector		second;
	t_vector		third;
}					t_figure;

typedef struct		s_camera
{
	t_vector		origin;
	t_vector		direction;
	float			fov;
}					t_camera;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_vplane
{
	float			width;
	float			hight;
	float			x_pix;
	float			y_pix;
}					t_vplane;

typedef struct		s_amb
{
	float			intensity;
	t_vector		color;
}					t_amb;

typedef struct		s_light
{
	float			intensity;
	t_vector		position;
	t_vector		color;
}					t_light;

typedef struct		s_scene
{
	t_camera		camera;
	t_amb			amb;
	t_list			*figures;
	t_list			*lights;
	int				width;
	int				hight;
	int				save;
	t_data			img;
}					t_scene;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	t_dlist			*cams;
	t_scene			scene;
}					t_vars;

typedef struct		s_bmp_header
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}					t_bmphead;

typedef struct		s_dib_header
{
	unsigned int	size;
	int				width;
	int				height;
	unsigned short	colplanes;
	unsigned short	bpp;
	unsigned int	compression;
	unsigned int	img_size;
	int				x_ppm;
	int				y_ppm;
	unsigned int	color_number;
	unsigned int	important_color;
}					t_dibhead;

#endif
