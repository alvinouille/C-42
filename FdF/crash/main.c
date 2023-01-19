/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:15:37 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/18 18:09:18 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*f_lstnew(int nb, int length, int width)
{
	t_list	*list;
    t_point c;

	list = NULL;
	list = malloc(sizeof(t_list));
	if (list)
	{
		list->nb = nb;
        list->c.x = length / 4;
        list->c.y = width/4;
        list->beside = NULL;
        list->next = NULL;
	}
	return (list);
}

void	*generator_map(t_list **lst, char *str, int length, int width)
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
                new = f_lstnew(str[i] - 48, length, width);
            else
            {
                f = i;
                while (str[i] >= '0' && str[i] <= '9')
                    i++;
                str[i] = '\0';
                new = f_lstnew(ft_atoi(&str[f]), length, width);    
            }
	        if (!new)
		        return (NULL);
	        ft_lstadd_back(lst, new);
        }
        i++;
    }
	return (lst);
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


void    beside_chaining(t_list **map, int dim[2])
{
    t_list  *head;
    int     x;
    int     y;
    
    y = 1;
    x = 0;
    head = *map;
    while (*map && y < dim[1])
    {
        (*map)->beside = ft_list_at(head, x + dim[0]);
        (*map) = (*map)->next;
        x++;
        if (x == dim[0])
            y++;
    }
    (*map) = head;
}

void    quadrillage(t_data img, int dim[2], t_list *map, int echelle)
{
    int x;
    int y;
    t_list  *head;
    t_list *prec;

    x = 0;
    y = 0;
    head = map;
    while (y < dim[1] -1)
    {
        while (x < dim[0])
        {
            if (x < dim[0])
                trace_line(img, map->c.x, map->c.y, echelle);
            if (map->beside)
                trace_col(img, map->c.x, map->c.y, echelle);
            printf("x = %d, y = %d\n", map->c.x, map->c.y);
            prec = map;
            map = map->next;
            map->c.x += echelle * x;
            map->c.y += echelle *y;
            x++;
            if (x == dim[0])
            {
                map = prec;
            }
        }
        x = 0;
        y++;
        map = map->next;
        // map->c.x = head->c.x;
        // map->c.y += echelle * y;
    }
}

int main(int ac, char **av)
{
    int     fd;
    char    *str;
    t_list  *map;
    int     dim[2];
        int length;
    int width;

    length = 1920;
    width = 1080;

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
        if (!generator_map(&map, str, length, width))
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
    beside_chaining(&map, dim);
    // print(map, dim);
    // int i = 1;
    // t_list *head = map;
    // while (i++ < dim[0])  //afficher dernier colonne
    //     map = map->next;
    // print2(map, dim);
    // map = head;
    t_vars vars;
    t_data  img;
    map->c.x = length / 4;
    map->c.y = width/4;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, length, width, "FdF to come");
    img.img = mlx_new_image(vars.mlx, length, width);
    vars.img = img;
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
    quadrillage(img, dim, map, 50);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    
    mlx_hook(vars.win, 2, 1L<<0, closing_key, &vars);
    mlx_hook(vars.win, 17, 1L<<5, closing_mouse, &vars);
    mlx_loop(vars.mlx);
    ft_lstclear(&map);
}