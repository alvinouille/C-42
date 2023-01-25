/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:13:44 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/25 21:02:07 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int action_key(int keycode, t_vars *vars)
{
    int y;
    static int nb;

	y = 0;
	if (keycode == 65307)
    {
        mlx_clear_window(vars->mlx, vars->win);
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
    else if (keycode == XK_w)
    {
        move_up(vars);
        (nb)++;
    }
    else if (keycode == XK_a)
    {
        move_left(vars);
        (nb)++;
    }
    else if (keycode == XK_s)
    {
        move_down(vars);
        (nb)++;
    }
    else if (keycode == XK_d)
    {
        move_right(vars);
        (nb)++;
    }
    printf("%d", nb);
    return (0);
}

int closing_mouse(t_vars *vars)
{
    int y;

	y = 0;
	mlx_clear_window(vars->mlx, vars->win);
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

int     width(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void    game_init(t_adr *img, t_vars *vars)
{
    int a;
    int b;

    img->player = mlx_xpm_file_to_image(vars->mlx, "img/p.xpm", &a, &a);
    img->border = mlx_xpm_file_to_image(vars->mlx, "img/b.xpm", &a, &a);
    img->background = mlx_xpm_file_to_image(vars->mlx, "img/bg.xpm", &a, &a);
    img->exit = mlx_xpm_file_to_image(vars->mlx, "img/e.xpm", &a, &a);
    img->collec = mlx_xpm_file_to_image(vars->mlx, "img/c.xpm", &a, &a);

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
        printf("\n");
        x = 0;
        i = 0;
        j++;
        y += 60;
    }
}

void	mlx(char **tab)
{
    t_vars vars;
    t_adr img;

    vars.tab = tab;
    vars.width = width(tab) * 60;
    vars.length = ft_strlen(tab[0]) * 60;
    vars.mlx = mlx_init();
    vars.tab = tab;

    vars.win = mlx_new_window(vars.mlx, vars.length, vars.width, "Pacman game");
    game_init(&img, &vars);
    vars.img = img;

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
            free(tmp);
            free(str);
            get_next_line(fd, 1);
            close(fd);
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
        close(fd);
        return (0);
    }
	free(tmp);
	// print(tab);
    tmtab = ft_split(str, '\n');
    if (is_ok(tab, tmtab) == 0)
    {
        free(str);
        free_tab(tab);
        free_tab(tmtab);
        close(fd);
        printf("Error\nInvalid map !\n");
        return (0);
    }
    free(str);
    free_tab(tmtab);
    printf("OK !\n");
	mlx(tab);
    free_tab(tab);
    close(fd);
	return (0);
}
