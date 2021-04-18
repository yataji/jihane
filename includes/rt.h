/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiqarbac <jiqarbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:22:16 by yataji            #+#    #+#             */
/*   Updated: 2021/04/18 16:01:49 by jiqarbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# define MAXWIDTH 900
# define MAXHEIGHT 900
# define SPHERE 0
# define CYLINDER 1
# define CONE 2
# define PLANE 3
# define PARAPLOID 4
# define MAXRF 3

typedef struct s_var
{
	int				x;
	int				y;
	double			t;
	double			near;
}					t_var;

typedef struct s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef t_vect		t_point;
typedef t_vect		t_color;
typedef t_vect		t_rot;

typedef struct s_obj
{
	int				type;
	double			angle;
	double			radius;
	t_vect			v;
	t_vect			normal;
	t_color			color;
	t_rot			rot;
	t_point			trs;
	t_point			center;
	int				ref;
	struct s_obj	*next;
}					t_obj;

typedef struct s_ray
{
	t_point			org;
	t_vect			dir;
	t_vect			hit;
	int				maxrf;
}					t_ray;

typedef struct s_math
{
	double			a;
	double			b;
	double			c;
	double			delta;
}					t_math;

typedef struct 			s_sol
{
	double				tmin;
	double				tmax;
}						t_sol;


// typedef struct s_mlx
// {
// 	void			*ptr;
// 	void			*win_ptr;
// 	void			*img_ptr;
// 	int				*dtadd;
// 	int				bpp;
// 	int				szln;
// 	int				end;
// }					t_mlx;

typedef struct s_cam
{
	t_point			lokat;
	t_point			lokfrm;
	t_vect			v;
	t_vect			u;
	t_vect			w;
	double			fov;
	double			plnw;
	double			plnh;
	struct s_cam	*next;
}					t_cam;

typedef struct s_lights
{
	double			intensity;
	t_color			color;
	t_point			pos;
	struct s_lights	*next;
}					t_lights;

typedef struct s_rt
{
	// t_mlx			mlx;
	t_obj			*obj;
	t_obj			*tmpo;
	t_ray			ray;
	t_cam			*cam;
	t_cam			*tmpc;
	t_lights		*lights;
	t_lights		*tmpl;
	t_sol			t;
	t_math			calc;
	// unsigned char	*ptr;
	double			dot1;
	char			*str;
	int				fd;
	int				ck;
	// int				color;
	SDL_Window		*win;
	SDL_Renderer	*rend;
}					t_rt;

t_color				multi_color(t_color c1, double scal);
t_color				multi_tcolor(t_color c1, t_color c2);
t_color				add_color(t_color c1, t_color c2);
t_vect				rotation_xyz(t_vect v, t_vect a);
t_ray				initray(t_cam *cam, int x, int y);
// t_mlx				init(void);
double				max(double v1, double v2);
double				dot(t_vect a, t_vect b);
double				multidbl(double v1, double v2, double v3);
t_sol				checkt(t_math calc);
t_sol				intersect(t_obj *object, t_ray ray);
t_sol				sphrintr(t_obj *sphere, t_ray ray);
t_sol				cyldintr(t_obj *cyld, t_ray ray);
t_sol				coneintr(t_obj *cone, t_ray ray);
t_sol				paraploid(t_obj *para, t_ray r);
t_sol				planiter(t_obj *cone, t_ray ray);
int					keypress(int key, void *param);
int					ft_exit(t_rt *rt);
void				setnormal(t_obj *close, t_ray *ray, double t);
void				initcamera(t_cam *cam);
void				draw(t_rt rt);
void				ft_free(t_obj **obj, t_lights **lights, t_cam **cam);
t_vect				plus(t_vect v1, t_vect v2);
t_vect				moins(t_vect v1, t_vect v2);
t_vect				multi(t_vect v1, double v2);
t_vect				normalize(t_vect v1);
t_vect				normsphr(t_ray *ray, t_obj *obj, double t);
t_vect				normcyld(t_ray *ray, t_obj *obj, double t);
t_vect				normcone(t_ray *ray, t_obj *obj, double t);
t_vect				crosspro(t_vect v1, t_vect v2);
t_lights			*initlights(void);
t_obj				*initobj(void);
t_cam				*initcam(void);
t_vect				stk(char **value);
size_t				ft_strlend(char **s);
t_color				checkcolorvalue(char **value);
int					parse(t_rt*rt);
int				sphere(t_obj *obj, char *str, int fd);
int				plane(t_obj *obj, char *str, int fd);
int				cylinder(t_obj *obj, char *str, int fd);
int				cone(t_obj *obj, char *str, int fd);
int					lights(t_lights *lights, char *str, int fd);
int					camera(t_cam *cam, char *str, int fd);
int					ck(char *str, char *check, int len);
int					chkone(char *str, int len);
int					ft_plane(t_rt *rt, char *str);
int					ft_cone(t_rt *rt, char *str);
int					ft_cylinder(t_rt *rt, char *str);
int					ft_sphere(t_rt *rt, char *str);
int					ft_lights(t_rt *rt, char *str);
int					ft_cam(t_rt *rt, char *str);


void				init_sdl(t_rt *rt);
void				sdl_error(char *message);
void				loop_program(t_rt *rt);

#endif