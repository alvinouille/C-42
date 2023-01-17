/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:37 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/17 16:04:35 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line/get_next_line/get_next_line.h"
#include "fdf.h"

t_list	*f_lstnew(int nb, int flag)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->nb = nb;
		list->eof = flag;
        list->next = NULL;
	}
	return (list);
}

void	*generator_map(t_list **lst, char *str)
{
	t_list  *new;
    int     i;

    i = 0;
	while (str[i] && str[i] != '\n')
    {
        if (str[i] != ' ')
        {
            if (str[i + 1] == '\n')
                new = f_lstnew(ft_atoi(str[i]), 1);
            else
                new = f_lstnew(ft_atoi(str[i]), 0);
	        if (!new)
		        return (NULL);
	        ft_lstadd_back(lst, new);
        }
        i++;
    }
	return (lst);
}

void    print(t_list *lst)
{
    printf("here\n");
    while (lst)
    {
        if (!(lst->eof))
            printf("%d ", lst->nb);
        else
            printf("\n");
        lst = lst->next;
    }
}

int main(int ac, char **av)
{
    int     fd;
    char    *str;
    t_list  *map;

    map = NULL;
    str = NULL;
    fd = open(av[1], O_RDONLY);
    if (fd == 0 || fd == -1)
        exit(1);
    while (1)
    {
        str = get_next_line(fd, 0);
        if (!str)
            break;
        if (!generator_map(&map, str))
		{
			if (!map)
				return (0);
			ft_lstclear(&map);
			return (0);
		}
        free(str);
    }
    free(str);
    print(map);
}