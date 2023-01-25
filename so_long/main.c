/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:13:44 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/25 15:02:19 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
# define LENGTH 1500
# define WIDTH 1000

int closing_key(int keycode, t_vars *vars)
{
    int y;

	y = 0;
	if (keycode == 65307)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_image(vars->mlx, vars->img.img);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
		while (vars->tab[y])
		{
			free(vars->tab[y]);
			y++;
		}
		free(vars->tab);
		exit(0);
    }
    return (0);
}

int closing_mouse(t_vars *vars)
{
    int y;

	y = 0;
	mlx_clear_window(vars->mlx, vars->win);
    mlx_destroy_image(vars->mlx, vars->img.img);
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
	while (vars->tab[y])
	{
		free(vars->tab[y]);
		y++;
	}
	free(vars->tab);
	exit(0);
}

void	mlx(char **tab)
{
    t_vars vars;
    t_data img;


    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, LENGTH, WIDTH, "FdF to come");
	img.img = mlx_new_image(vars.mlx, LENGTH, WIDTH);
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
    vars.tab = tab;
    vars.img = img;

    mlx_hook(vars.win, 2, 1L<<0, closing_key, &vars);
    mlx_hook(vars.win, 17, 1L<<5, closing_mouse, &vars);
    mlx_loop(vars.mlx);
}

void	print(char **tab)
{
	printf("\n\nMAP : \n\n");
	int j = 0;
	while (tab[j])
	{
		printf("%s\n", tab[j]);
		j++;
	}
}

int main(int ac, char **av)
{
    
    int     fd;
    char     **tab;
    char    *str;
    char *tmp;
    char **tmtab;
    t_vars  vars;
    int     size;

    str = NULL;
    size = 0;
    if (ac == 1 || ac > 2)
    {
        ft_putstr_fd("  usage: ./so_long <map>\n", 2);
        exit(1);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == 0 || fd == -1)
    {
        ft_putstr_fd(av[1], 2);
        perror(" ");
        exit(1);
    }
	while (1)
    {
        tmp = get_next_line(fd, 0);
        if (!tmp)
            break;
        if (tmp[0] == '\n')
        {
            printf("KO !");
            return (0);
        }
        str = ft_strjoin(str, tmp);
        if (!str)
            exit(1);
		size++;
    }
    tab = ft_split(str, '\n');
    if (!tab)
    {
        printf("KO !");
        return (0);
    }
	free(tmp);
	print(tab);
    if (is_ok(tab) == 1)
        printf("OK !");
    else
        printf("KO !");
    tmtab = ft_split(str, '\n');
    if (!is_valid(tmtab))
    {
        printf("KO !");
        return (0);
    }
    free(str);
	// mlx(tab);
	return (0);
}
