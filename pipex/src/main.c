/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:26:33 by ale-sain          #+#    #+#             */
/*   Updated: 2022/12/21 02:50:56 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_env(char **env)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (!env || !*env)
		return (NULL);
	while (env[i] && (ft_strncmp(env[i], "PATH=", 5) != 0))
		i++;
	if (ft_strncmp(env[i], "PATH=", 5) == 0)
	{
		while (env[i][j] != '/')
			j++;
		return (ft_split(&env[i][66], ':'));
	}
	else
		return (NULL);
}

char	*ft_whereis(char *cmd, char **e)
{
	int		i;
	char	*path;
	char	*p;

	i = 0;
	if (access (cmd, X_OK) == 0 && ft_strlen(cmd) > 10)
		return (ft_strdup(cmd));
	if (!e)
		return (NULL);
	if (!cmd)
		return (NULL);
	while (e[i])
	{
		p = ft_strjoin(e[i], "/");
		path = ft_strjoin(p, cmd);
		free(p);
		if (access (path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	*generator_cmd(t_list **lst, int ac, char **av, char **env)
{
	t_list		*new;
	static int	i = 2;

	if (ft_strnstr(av[1], "here_doc", 9) == av[1] && i == 2)
		i++;
	new = ft_lstnew(ac, av, env, i);
	if (!new)
		return (NULL);
	if (!(*lst))
		new->head = new;
	else
		new->head = *lst;
	i++;
	return (ft_lstadd_back(lst, new));
}

int	verif_arg(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("\tusage: ./pipex infile cm1 cm2 outfile\n", 1);
		return (0);
	}
	else
		return (1);
}

int	main(int ac, char **av, char **env)
{
	int		statuscode;
	int		i;
	t_list	*cmd;

	if (ft_strnstr(av[1], "here_doc", 9) == av[1])
		i = 2;
	else
		i = 1;
	statuscode = 0;
	cmd = NULL;
	if (verif_arg(ac) == 0)
		return (0);
	while (i++ < ac - 2)
	{
		if (!generator_cmd(&cmd, ac, av, env))
		{
			if (!cmd)
				return (0);
			ft_lstclear(&cmd->head, cleanator);
			return (0);
		}
	}
	statuscode = pipex(cmd, cleanator);
	ft_lstclear(&cmd->head, cleanator);
	exit(statuscode);
}
