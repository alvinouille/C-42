/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   main.c	 :+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: ale-sain <ale-sain@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2023/01/25 13:13:44 by ale-sain	  #+#	#+#	 */
/*   Updated: 2023/02/02 09:18:55 by ale-sain	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(char **tab)
{
	int	change;

	change = 1;
	while (change > 0)
	{
		change = 0;
		change = changing(tab);
	}
	if (char_check(tab, 'C', 'E'))
		return (0);
	return (1);
}

int	format(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 4)
		return (0);
	if (ft_strnstr(&str[size - 4], ".ber", 4) != 0)
		return (1);
	else
		return (0);
}

int	arg_check(int ac, char **av)
{
	int	fd;

	if (ac == 1 || ac > 2)
	{
		ft_putstr_fd("  usage: ./so_long <map>\n", 2);
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

char	*gnl(int fd, char *str, char *tmp)
{
	while (1)
	{
		tmp = get_next_line(fd, 0);
		if (!tmp)
			break ;
		if (tmp[0] == '\n')
			clean_leaving_gnl(tmp, str, fd);
		str = ft_strjoin(str, tmp);
		if (!str)
		{
			close(fd);
			get_next_line(fd, 1);
			ft_putstr_fd("Error\nMalloc failed !\n", 2);
			exit(2);
		}
	}
	close(fd);
	if (!tmp && !str)
	{
		ft_putstr_fd("Error\nEmpty map or repository !\n", 2);
		exit(1);
	}
	free(tmp);
	return (str);
}

int	main(int ac, char **av)
{
	int		fd;
	char	**tab;
	char	*str;
	char	*t;
	char	**tmp;

	str = NULL;
	t = NULL;
	fd = arg_check(ac, av);
	str = gnl(fd, str, t);
	tab = ft_split(str, '\n');
	if (!tab)
		free_machine(NULL, NULL, str);
	tmp = ft_split(str, '\n');
	if (!tmp)
		free_machine(tab, NULL, str);
	if (is_ok(tab, tmp) == 0)
		free_machine(tab, tmp, str);
	free_machine(NULL, tmp, str);
	mlx(tab);
	free_tab(tab);
	return (0);
}
