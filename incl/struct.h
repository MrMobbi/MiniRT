
#ifndef STRUCT_H
# define STRUCT_H

//  all data
typedef struct s_minirt {
	struct s_matrice	*matrice;
}						t_minirt;

//  Matrice proto
typedef struct s_matrice {
	bool				a;
	bool				c;
	bool				l;
	bool				duplicate;
	struct s_al			*ambient;	
	struct s_l			*light;
	struct s_c			*camera;
	struct s_pl			*plane;
	struct s_list_sp	*sphere;
	struct s_list_cy	*cylinder;
}						t_matrice;

//  Ambient Light proto
typedef struct s_al {
	struct s_rgb	*rgb;
	float			ratio;
}					t_al;

//  Light proto
typedef struct s_l {
	struct s_3v		*position;
	struct s_rgb	*rgb;
	float			ratio;
}					t_l;

//  Camera proto
typedef struct s_c {
	struct s_3v	*position;
	struct s_3v	*vector;
	float		fov;
}				t_c;

//  Plane proto
typedef struct s_pl {
	struct s_3v		*position;
	struct s_3v		*vector;
	struct s_rgb	*rgb;
}					t_pl;

//  Sphere proto
typedef struct s_list_sp {
	struct s_3v			*position;
	struct s_rgb		*rgb;
	float				diameter;
	struct s_list_sp	*next;
}						t_list_sp;

//  Cylinder proto
typedef struct s_list_cy {
	struct s_3v			*position;
	struct s_3v			*vector;
	struct s_rgb		*rgb;
	float				diameter;
	float				height;
	struct s_list_cy	*next;
}						t_list_cy;

//  Position in 3D proto
typedef struct s_3v {
	float	x;
	float	y;
	float	z;
}			t_3v;

//  RGB proto
typedef struct s_rgb {
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
}					t_rgb;

#endif
