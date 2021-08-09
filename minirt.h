/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeorgan <fgeorgan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:47:36 by fgeorgan          #+#    #+#             */
/*   Updated: 2021/03/22 14:01:29 by fgeorgan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "structures.h"

# define ESC 53
# define RIGHT 124
# define LEFT 123

t_vector	new_vector(float x, float y, float z);
t_figure	new_sphere(t_vector center, float radius, t_vector clr);
t_figure	new_plane(t_vector center, t_vector normal, t_vector clr);
t_figure	new_triangle(t_vector first, t_vector second, t_vector third,
							t_vector clr);
t_figure	new_square(t_vector center, t_vector normal, float side_size,
							t_vector clr);
t_amb		new_amb(float intensity, t_vector color);
t_light		new_light(float intensity, t_vector position, t_vector color);
t_camera	new_camera(t_vector origin, t_vector direction, float fov);
t_scene		new_scene(t_camera camera, t_list *figures, t_list *lights,
							float width, float hight, t_amb amb);

t_vector	vec_addition(t_vector v1, t_vector v2);
t_vector	vec_addition_secure(t_vector v1, t_vector v2);
t_vector	vec_subtract(t_vector v1, t_vector v2);
t_vector	vec_cross(t_vector v1, t_vector v2);
float		vec_len(t_vector vec);
t_vector	vec_normalize(t_vector vec);
float		vec_dot(t_vector v1, t_vector v2);
t_vector	vec_dot_const(float c, t_vector v);
t_vector	vec_dot_secure(float c, t_vector v);
int			vec_to_int(int r, int g, int b);

float		sphere_inter(t_vector orig, t_vector dir, t_figure sphere);
float		triangle_inter(t_vector orig, t_vector dir, t_figure triangle);
t_vector	triangle_norm(t_vector p1, t_vector p2, t_vector p3);
float		cylinder_inter(t_vector orig, t_vector dir, t_figure cylinder);
t_vector	cylinder_norm(t_vector p, t_figure fig);
float		plane_inter(t_vector r, t_vector l, t_figure plane);
float		square_inter(t_vector orig, t_vector dir, t_figure square);

void		ray_tracing(void *mlx, void *win, t_scene *scene);
int			trace_ray(t_scene *scene, t_vector ray, t_list *figures);
int			ft_close(t_vars *vars);
int			change_cam(int key, t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			ft_close(t_vars *vars);
t_vplane	get_view_plane(float width, float hight, float fov);
t_vector	int_light(t_vector color, t_light svet, float i, t_list **lights);
t_vector	int_amb(t_vector color, t_amb amb, t_vector fig_clr);
void		save(t_vars *all);
int			count_elems(char **elems);
void		ft_errno(char *error);
t_vector	multyply_by_look_at(t_vector orig, t_vector dir, t_vector ray);
int			check_shadows(t_scene *scene, t_vector p, t_vector l);
int			change_cam(int key, t_vars *vars);
t_vector	compute_light(t_scene *scene, t_vector p, t_vector n, t_figure fig);
void		wrapper(char **elems);
void		ft_error(char *error, char **elems);
int			is_int_str(char *str);
int			is_float_str(char *str);

void		check_valid_line(char *line, t_vars *all, int *nec);
void		check_valid_line_2(char	**elems, t_vars *all, int *nec);
void		check_rotation(char **elems, t_vars *all, int *nec);
void		check_ambient(char **elems, t_vars *all, int *nec);
void		check_camera(char **elems, t_vars *all, int *nec);
void		check_light(char **elems, t_vars *all);
void		check_sp(char **elems, t_vars *all);
void		check_pl(char **elems, t_vars *all);
void		check_sq(char **elems, t_vars *all);
void		check_cy(char **elems, t_vars *all);
void		check_tr(char **elems, t_vars *all);

t_vector	set_color(char *elem, char **elems);
t_vector	set_vector(char *elem, char **elems);
t_vector	set_normal(char *elem, char **elems);

#endif
