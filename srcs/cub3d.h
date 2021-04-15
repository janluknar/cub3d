/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jluknar- <jluknar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:09:15 by jluknar-          #+#    #+#             */
/*   Updated: 2020/07/02 10:44:26 by jluknar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <math.h>
# include <mlx.h>
# include "../ft_printf/ft_printf.h"

# define LEFT_CLICK     1
# define RIGHT_CLICK    2
# define MIDDLE_CLICK   3
# define SCROLL_UP      4
# define SCROLL_DOWN    5
# define KEY_1          18
# define KEY_2          19
# define KEY_3          20
# define KEY_4          21
# define KEY_Q          12
# define KEY_W          13
# define KEY_E          14
# define KEY_R          15
# define KEY_Y          16
# define KEY_A          0
# define KEY_S          1
# define KEY_D          2
# define KEY_I          34
# define KEY_O          31
# define KEY_P          35
# define KEY_J          38
# define KEY_K          40
# define KEY_L          37
# define KEY_M          46
# define KEY_LEFT       123
# define KEY_RIGHT      124
# define KEY_FORWARD    126
# define KEY_BACKWARD   125
# define KEY_TAB    48
# define KEY_MAJ    257
# define KEY_ESC    53
# define KEY_TAB    48
# define RES_H  900
# define RES_W  1600
# define X_EVENT_KEY_PRESS      2
# define X_EVENT_KEY_RELEASE    3
# define X_EVENT_MOUSE_PRESS    4
# define X_EVENT_MOUSE_RELEASE  5
# define X_EVENT_MOUSE_MOVE     6
# define X_EVENT_EXIT           17
# define BLACK  0
# define WHITE  0x00FFFFFF
# define PINK   0x00ffaacc
# define LIME   0x00d5ff61
# define RED    0x00e33642
# define EAST   0x008cba51
# define WEST   0x006e5773
# define NORTH  0x004a69bb
# define SOUTH  0x0021bf73
# define SPEED  0.05
# define ROT    -0.04
# define SCALE  9
# define TEXW   64
# define TEXTURES 5

typedef struct	s_map
{
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	int		floor;
	int		ceiling;
	char	*mapstr;
	int		rows;
	int		collumns;
	char	**strarr;
	int		**maparray;
	int		posy;
	int		posx;
	char	spawn;
	int		spawnflag;
	int		numsprites;
	int		red;
	int		green;
	int		blue;
	int		info_count;
	int		fc_flag;
	int		invalmap_flag;
	int		save_flag;
	int		col;
}				t_map;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_line;
	int			bpp;
	int			endian;

}				t_img;

typedef struct	s_mflags
{
	int		left_fl;
	int		right_fl;
	int		forward_fl;
	int		backward_fl;
	int		turn_l;
	int		turn_r;
	int		paintmap;
}				t_mflags;

typedef struct	s_mov
{
	double	speed;
	double	posx;
	double	posy;
	double	sum_x;
	double	sum_y;

}				t_mov;

typedef	struct	s_sp
{
	double	x;
	double	y;
	double	dist;
	int		tex;
}				t_sp;

typedef struct	s_rayc
{
	double	dir_x;
	double	old_dirx;
	double	dir_y;
	double	planex;
	double	oldplanex;
	double	planey;
	double	camerax;
	double	cameray;
	double	raydir_x;
	double	raydir_y;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	t_sp	*sprites;
	double	*zbuffer;
	int		*sp_order;
	double	*sp_dist;
	double	sp_x;
	double	sp_y;
	double	invdet;
	double	transformx;
	double	transformy;
	int		sp_screenx;
	int		v_movescreen;
	int		sp_height;
	int		drawstart_y;
	int		drawend_y;
	int		sp_width;
	int		drawstart_x;
	int		drawend_x;
}				t_rayc;

typedef	struct	s_tex
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size;
	int		endian;
	int		texnum;
	int		tex_x;
	int		tex_y;
	int		color;
	double	wallx;
	double	step;
	double	texpos;
}				t_tex;

typedef	struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_mov		mov;
	t_map		*map;
	t_img		img;
	t_mflags	mflags;
	t_rayc		rayc;
	t_tex		tex[TEXTURES];
}				t_mlx;

int				read_cub_file(t_map *map, char *path);
int				read_cub_file2(t_map *map, char *path);
int				rgb_int(int red, int green, int blue);
void			handle_texres(t_map *map, char *line, int i);
void			get_res(t_map *map, char *line, int i);
void			get_texpath(t_map *map, char *line, int i);
void			get_colors(t_map *map, char *line, int i);
void			break_eof(t_map *map);
void			map_in_string(t_map *map, char *line);
void			get_rows_collumns(t_map *map);
void			uniarr_to_array(t_map *map);
void			str_to_array(t_map *map);
void			get_spawn(t_map *map, int y, int x);
void			convert_spawn(t_map *map, int x, int y);
void			check_res(t_mlx *mlx);
int				check_map_bounds(t_mlx *mlx);
int				check_map_info(t_mlx *mlx);
void			fill_plane(t_map *map);
void			paint_map(int x, int y, t_mlx *mlx, int scale);
void			paint_pos(t_mlx *mlx, int scale);
int				paint_everything(t_mlx *mlx);
void			save_bmp(t_mlx *mlx);
int				key_press(int key, t_mlx *mlx);
int				key_release(int key, t_mlx *mlx);
int				exit_game(void);
void			movement(t_mlx *mlx);
void			check_mov_fb(t_mlx *mlx);
void			check_mov_lr(t_mlx *mlx);
void			check_mov_lrw(t_mlx *mlx);
void			ray(t_mlx *mlx, int y, int x, int color);
void			ray_sp(t_mlx *mlx, int y, int x, int color);
void			paint_walls(t_mlx *mlx, int h, int x);
void			paint_rays(t_mlx *mlx, int x, int drawstart, int drawend);
void			init_variables(t_mlx *mlx, int x);
void			init_variables2(t_mlx *mlx);
void			perform_dda(t_mlx *mlx);
void			calc_draw_sections(t_mlx *mlx);
void			texture_calc(t_mlx *mlx);
void			sprite_calc(t_mlx *mlx, int i);
void			sprite_calc2(t_mlx *mlx);
void			paint_sprite(t_mlx *mlx, int y, int stripes);
void			paint_sprites(t_mlx *mlx);
void			raycasting(t_mlx *mlx, int x);
void			spritecasting(t_mlx *mlx, int i);
int				raycaster(t_mlx *mlx);
void			facing_init(t_mlx *mlx);
void			init_west(t_mlx *mlx);
int				load_textures(t_mlx *mlx);
int				get_sprite_data(t_mlx *mlx);
void			set_sprite_pos(t_mlx *mlx, int x, int y, int sprite);
void			sort_sprites(t_mlx *mlx);
int				initalize_variables(t_mlx *mlx);
int				initalize_velocity(t_mlx *mlx);
int				initalize_map(t_mlx *mlx, char **argv);
int				initalize_sprites(t_mlx *mlx, int argc, char **argv);
int				numlen(int nb);

#endif
