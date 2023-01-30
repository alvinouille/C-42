/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:13:44 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/30 16:50:08 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int action_key(int keycode, t_vars *vars)
{
    static int a = 1;

	if (keycode == 65307)
        such_a_quitter(vars, 0);
    else if (keycode == XK_w)
        a += move_up(vars, a);
    else if (keycode == XK_a)
        a += move_left(vars, a);
    else if (keycode == XK_s)
        a += move_down(vars, a);
    else if (keycode == XK_d)
        a += move_right(vars, a);
    return (1);
}

void    mlx_destroyer(t_vars *vars)
{
    if (vars->img.player)
        mlx_destroy_image(vars->mlx, vars->img.player);
    if (vars->img.border)
        mlx_destroy_image(vars->mlx, vars->img.border);
    if (vars->img.background)
        mlx_destroy_image(vars->mlx, vars->img.background);
    if (vars->img.exit)
        mlx_destroy_image(vars->mlx, vars->img.exit);
    if (vars->img.collec)
        mlx_destroy_image(vars->mlx, vars->img.collec);
    if (vars->win)
    {
        mlx_clear_window(vars->mlx, vars->win);
        mlx_destroy_window(vars->mlx, vars->win);
    }
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
    }
}

void    such_a_quitter(t_vars *vars, int flag)
{
    int y;

	y = 0;
    if (vars->tab)
	{
        while (vars->tab[y])
	    {
		    free(vars->tab[y]);
		    y++;
	    }
	    free(vars->tab);
    }
    mlx_destroyer(vars);
    if (flag == 3)
            ft_putstr_fd("Mlx failed !\n", 2);
	exit(flag);
}

int closing_mouse(t_vars *vars)
{
    such_a_quitter(vars, 0);
    return (0);
}

int     width(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void    game_init(t_vars *vars)
{
    int a;

    vars->img.player = mlx_xpm_file_to_image(vars->mlx, "img/p.xpm", &a, &a);
    if (!vars->img.player)
        such_a_quitter(vars, 3);
    vars->img.border = mlx_xpm_file_to_image(vars->mlx, "img/b.xpm", &a, &a);
    if (!vars->img.border)
        such_a_quitter(vars, 3);
    vars->img.background = mlx_xpm_file_to_image(vars->mlx, "img/bg.xpm", &a, &a);
    if (!vars->img.background)
        such_a_quitter(vars, 3);
    vars->img.exit = mlx_xpm_file_to_image(vars->mlx, "img/e.xpm", &a, &a);
    if (!vars->img.exit)
        such_a_quitter(vars, 3);
    vars->img.collec = mlx_xpm_file_to_image(vars->mlx, "img/c.xpm", &a, &a);
    if (!vars->img.collec)
        such_a_quitter(vars, 3);

}

void    display_img(char c, int x, int y, t_vars *vars)
{
    if (c == '1')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.border, x, y);
    if (c == '0')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.background, x, y);
    if (c == 'E')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit, x, y);
    if (c == 'P')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player, x, y);
    if (c == 'C')
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img.collec, x, y);
}

void    display_game(char **tab, t_vars *vars)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    
    while (tab[j])
    {
        while (tab[j][i])
        {
            display_img(tab[j][i], x, y, vars);
            x += 60;
            i++;
        }
        x = 0;
        i = 0;
        j++;
        y += 60;
    }
}

t_vars  initializing(char **tab)
{
    t_vars vars;

    vars.img.player = NULL;
    vars.img.border = NULL;
    vars.img.background = NULL;
    vars.img.exit = NULL;
    vars.img.collec = NULL;
    vars.win = NULL;
    vars.mlx = NULL;
    vars.tab = tab;
    vars.width = width(tab) * 60;
    vars.length = ft_strlen(tab[0]) * 60;
    return (vars);
}

void	mlx(char **tab)
{
    t_vars vars;

    vars = initializing(tab);
    vars.mlx = mlx_init();
    if (!vars.mlx)
        such_a_quitter(&vars, 3);
    vars.win = mlx_new_window(vars.mlx, vars.length, vars.width, "Pacman game");
    if (!vars.win)
        such_a_quitter(&vars, 3);
    game_init(&vars);
    display_game(vars.tab, &vars);
    mlx_hook(vars.win, 2, 1L<<0, action_key, &vars);
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

void    free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

static int     arg_check(int ac, char **av)
{
    int fd;

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
    return (fd);
}

static void    clean_leaving_gnl(char *tmp, char *str, int fd)
{
    free(tmp);
    free(str);
    get_next_line(fd, 1);
    close(fd);
    ft_putstr_fd("Error\nInvalid map !\n", 2);
    exit(3);
}

static char    *gnl(int fd)
{
    char    *str;
    char    *tmp;

    str = NULL;
    while (1)
    {
        tmp = get_next_line(fd, 0);
        if (!tmp)
            break;
        if (tmp[0] == '\n')
            clean_leaving_gnl(tmp, str, fd);
        str = ft_strjoin(str, tmp);
        if (!str)
        {
            free(tmp);
            ft_putstr_fd("Malloc failed !\n", 2);
            exit(2);
        }
    }
    if (!tmp && !str)
        exit(1);
    free(tmp);
    return (str);
}

static void    freeer(char **tab, char **tmp, char *str, int fd)
{
       free(str);
       free_tab(tmp);
       if (fd < 0)
       {
            fd = -fd;
            free_tab(tab);
            close(fd);
            ft_putstr_fd("Error\nInvalid map !\n", 2);
            exit(3);
       }
       close(fd);
}

int main(int ac, char **av)
{
    int     fd;
    char     **tab;
    char    *str;
    char **tmp;

    str = NULL;
    fd = arg_check(ac, av);
    str = gnl(fd);
    tab = ft_split(str, '\n');
    if (!tab)
    {
        free(str);
        close(fd);
        ft_putstr_fd("Malloc failed !", 2);
        exit(2);
    }
    tmp = ft_split(str, '\n');
    if (is_ok(tab, tmp) == 0)
        freeer(tab, tmp, str, -fd);
    freeer(tab, tmp, str, fd);
	mlx(tab);
    free_tab(tab);
	return (0);
}
