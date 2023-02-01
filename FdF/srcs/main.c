/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/01 20:32:42 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
# define LENGTH 1920
# define WIDTH 1080

int     arg_check(int ac, char **av)
{
    int fd;

    if (ac == 1 || ac > 2)
    {
        ft_putstr_fd("  usage: ./fdf <map>\n", 2);
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

char    *gnl(int fd)
{
    char    *str;
    char    *tmp;

    str = NULL;
    while (1)
    {
        tmp = get_next_line(fd, 0);
        if (!tmp)
            break;
        str = ft_strjoin(str, tmp);
        if (!str)
        {
            get_next_line(fd, 1);
            close(fd);
            ft_putstr_fd("Malloc failed !\n", 2);
            exit(2);
        }
    }
    if (!tmp && !str)
    {
        close(fd);
        exit(1);
    }
    free(tmp);
    close(fd);
    return (str);
}

int main(int ac, char **av)
{
    int     fd;
    char    *str;
    t_vars  vars;
    int     flag;

    str = NULL;
    fd = arg_check(ac, av);
    str = gnl(fd);
    flag = split_tab(str, '\n', &vars);
	if (str)
        free(str);
    vars.win = NULL;
    vars.mlx = NULL;
    vars.img.img = NULL;
    if (!flag || flag == 2)
            such_a_quitter(&vars, 2);
	mlx(vars);
	return (0);
}
