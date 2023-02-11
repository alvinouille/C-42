/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:53:47 by alvina            #+#    #+#             */
/*   Updated: 2023/02/11 19:39:17 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

typedef struct s_token
{
	char            *value;
    int             type;
	struct s_token	*next;
}	t_token;

int	is_pipe(char *str);
int	is_red(char *str);
int is_space(char *str);
int is_separator(char *str);
int	changing_state(char c, int state);
int	count_words(char *str);
void	ft_putstr_fd(char *s, int fd);

t_token	*ft_lstlast(t_token *lst);
t_token	*ft_lstnew(char *str);
t_token	*ft_lstadd_back(t_token **lst, t_token *new);

#endif