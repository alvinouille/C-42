/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:37 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/18 08:56:05 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "fdf.h"

t_list	*f_lstnew(int nb)
{
	t_list	*list;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->nb = nb;
        list->next = NULL;
	}
	return (list);
}

void	*generator_map(t_list **lst, char *str)
{
	t_list  *new;
    char    f;
    int     i;

    i = 0;
	while (str[i] && str[i] != '\n')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (str[i + 1] == '\n')
                new = f_lstnew(str[i] - 48);
            else
            {
                f = i;
                while (str[i] >= '0' && str[i] <= '9')
                    i++;
                str[i] = '\0';
                new = f_lstnew(ft_atoi(&str[f]));    
            }
	        if (!new)
		        return (NULL);
	        ft_lstadd_back(lst, new);
        }
        i++;
    }
	return (lst);
}

void    print(t_list *lst, int dim[2])
{
    int x;
    
    x = 0;
    printf("\n\n\t\tx = %d, y = %d\n", dim[0], dim[1]);
    printf("\n\n\t\t- - - - MY OWN - - - -\n\n");
    while (lst)
    {
        if (x != dim[0] -1)
        {
            if (lst->next->nb < 10)
                printf("%d  ", lst->nb);
            else
                printf("%d ", lst->nb);
        }
        else
        {
            printf("%d  ", lst->nb); //EOF
            printf("\n");
            x = -1;
        }
        lst = lst->next;
        x++;
    }
}

int ft_strlen_modif(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    if (!str)
        return (0);
    while (str[i] && str[i] != '\n')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            res++;
            while (str[i] >= '0' && str[i] <= '9')
                i++;
        }
        i++;
    }
    return (res);
}

int main(int ac, char **av)
{
    int     fd;
    char    *str;
    t_list  *map;
    int     dim[2];

    map = NULL;
    dim[1] = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == 0 || fd == -1)
        exit(1);
    printf("\n\t\t- - - - MODELE - - - -\n\n");
    while (1)
    {
        str = get_next_line(fd, 0);
        printf("%s", str);
        if (!str)
            break;
        dim[0] = ft_strlen_modif(str);
        if (!generator_map(&map, str))
		{
			if (!map)
				return (0);
			ft_lstclear(&map);
			return (0);
		}
        dim[1]++;
        free(str);
    }
    free(str);
    print(map, dim);
}