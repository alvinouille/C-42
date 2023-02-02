/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:21 by ale-sain          #+#    #+#             */
/*   Updated: 2023/02/02 18:02:44 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	format(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 4)
		return (0);
	if (ft_strnstr(&str[size - 4], ".fdf", 4) != 0)
		return (1);
	else
		return (0);
}

int	arg_check(int ac, char **av)
{
	int	fd;

	if (ac == 1 || ac > 2)
	{
		ft_putstr_fd("  usage: ./fdf <map>\n", 2);
		exit(1);
	}
	if (format(av[1]) == 0)
	{
		ft_putstr_fd("Error\nInvalid format\n", 2);
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

char	*gnl(int fd)
{
	char	*str;
	char	*tmp;

	str = NULL;
	while (1)
	{
		tmp = get_next_line(fd, 0);
		if (!tmp)
			break ;
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

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	t_vars	vars;
	int		flag;

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
