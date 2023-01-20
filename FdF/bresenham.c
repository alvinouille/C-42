#include <stdio.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_data  img;
}				t_vars;

typedef struct s_point
{
    double x;
    double y;
}   t_point;

void	img_pixel_put(t_data *img, double x, double y, int color)
{
	char	*px;

	px = img->addr + (int)round((y * img->line_length + x * (img->bits_per_pixel / 8)));
	*(unsigned int*)px = color;
}

void    bresenham(t_data img, t_point curr, t_point next)
{
    int dy = next.y - curr.y;
    int dx = next.x - curr.x;
    int x = curr.x;
    int y = curr.y;
    printf("x = %d, y = %d\n", x, y);
    float e = 0.0;
    float pente;
    if (dx != 0)
        pente = (float)dy / (float)dx;
    else
        pente = 0;
    float ajust = - 1.0;
    printf("pente = %f\n", pente);
    if (pente >= 0)
    {
        //      AU DESSUS AXE ABSCISSE (X)
        //      OCTET 2 ET 1 (A DROITE AXE ORDONNE (Y))
        if (x < next.x)    
        {
            while (x <= next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e >= 0.5)
                {
                    y++;
                    e += ajust;
                }
                x++;
            }
        }
        //      SUR AXE ORDONNE
        else if (x == next.x)
        {
            if (y <= next.y)
            {
                while (y <= next.y)
                {
                    img_pixel_put(&img, x, y, 0x00FFFFFF);
                    y++;
                }
            }
            else
            {
                while (y >= next.y)
                {
                    img_pixel_put(&img, x, y, 0x00FFFFFF);
                    y--;
                }
            }
        }
        //      OCTANT 4 ET 3 (A GAUCHE AXE ORDONNE (Y))
        else
        {
            while (x > next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e >= 0.5)
                {
                    y--;
                    e -= ajust;
                }
                x--;
            }
        }
    }
    //  AU DESSOUS AXE ABSCISSE (X)
    else
    {
        //      OCTANT 8 ET 7 (A DROITE AXE ORDONNE (Y))
        if (x < next.x)
        {
            while (x < next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e <= -0.5)
                {
                    y--;
                    e -= ajust;
                }
                x++;
            
            }
        }
        //      OCTANT 6 ET 5 (A GAUCHE AXE ORDONNE (Y))
        else
        {
            while (x > next.x)
            {
                img_pixel_put(&img, x, y, 0x00FFFFFF);
                e += pente;
                if (e <= 0.5)
                {
                    y++;
                    e -= ajust;
                }
                x--;
                printf("x = %d, y = %d\n",x, y);
            }
        }
    }
}

void    tracing(t_data img, t_point **tab, int length, int width)
{
    t_point curr;
    t_point next;
    int i = 0;
    int j = 0;

    while (j < width)
    {
        while (i + 1 < length)
        {
            bresenham(img, tab[j][i], tab[j][i + 1]);
            // img_pixel_put(&img, tab[j][i].x, tab[j][i].y, 0x00FFFFFF);
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
    while (i < length)
    {
        while (j + 1 < width)
        {
            bresenham(img, tab[j][i], tab[j + 1][i]);
            // img_pixel_put(&img, tab[j][i].x, tab[j][i].y, 0x00FFFFFF);
            j++;
        }
        j = 0;
        i++;
    }

}

t_point **create(int length, int width)
{
    int i;

    i = 0;
    t_point **tab = malloc(sizeof (t_point *) * width);
    while (i < width)
    {
        tab[i] = malloc(sizeof(t_point) * length);
        i++;
    }
    tab[0][0].x = 30;
    tab[0][0].y = 5;
    tab[0][1].x = 50;
    tab[0][1].y = 20;
    tab[1][0].x = 10;
    tab[1][0].y = 20;
    tab[1][1].x = 30;
    tab[1][1].y = 40;
    return (tab);
}

int main()
{
    t_vars vars;
    t_data  img;
    t_point p1;
    t_point p2;
    t_point **tab;

    tab = create(2, 2);
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "FdF to come");
	
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    tracing(img, tab, 2, 2);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

    mlx_loop(vars.mlx);
}

