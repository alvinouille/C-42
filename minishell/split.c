/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:55:05 by alvina            #+#    #+#             */
/*   Updated: 2023/02/08 13:58:50 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**free_tab(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(tab[i]);
		i++;
	}
	return (NULL);
}

static int	length_words(char *str)
{
	int	i;

	i = 0;
    if (is_separator(str[i])
        return (is_separator(str[i])
	while ((str[i] != ' ' || str[i] != '<' || str[i] != '>'))
		i++;
	return (i);
}


void    wording(char *str, char ***tab, int j, int (*f)(char *))
{
    int k;
    int i;

    k = 0;
    i = 0;
    *tab[j] = malloc(sizeof(char) * (f(str) + 1));
    if (!*tab[j])
		return (free_tab(*tab, j));
	while (f(&str[i]) && str[i])
		*tab[j][k++] = str[i++];
	*tab[j][k] = '\0';
}

static char	**splitting(char **tab, char *str, int state)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (str[i])
	{
        state = changing_state(str[i], state);
        if (state == 0 && is_separator(&str[i]))
        {
            if (!is_space(&str[i]))
            {
                if (is_pipe(&str[i]))
                    wording(&str[i], &tab, j, is_pipe);
                else
                    wording(&str[i], &tab, j, is_red);
			    j++;
            }
        }
		if (str[i] != ' ' || state != 0)
		{
			tab[j] = malloc(sizeof(char) * (length_words(&str[i]) + 1));
			if (!tab)
				return (free_tab(tab, j));
			k = 0;
			while (str[i] != c && s[i])
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

char	**first_split(char *str)
{
	char	**tab;
    int     state;

    state = 0;
	if (count_words(str) == 0)
		return (NULL);
	tab = (char **) malloc(sizeof(char *) * (count_words(str) + 1));
	if (!tab)
		return (NULL);
	return (splitting(tab, str, state));
}

// int	changing_state(int state, int quote)
// {
// 	if (state == quote)
// 		return (0);
// 	if (state == 0)
// 		return (quote);
// }

// void	t_token_creator(char *str)
// {
// 	int	state;
// 	int	i;

// 	state = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 39)
// 			state = changing_state(state, 1);
// 		if (str[i] == '"')
// 			state = changing_state(state, 2);
// 		if (is_separator(&str[i]))
// 		{
// 			i += is_separator(&str[i]);
// 		else
// 			i++;
// 	}
// }

