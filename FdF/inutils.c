/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:04:31 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/18 16:20:01 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print2(t_list *lst, int dim[2])
{
    int x = 0;

    while (lst)
    {
        printf("%d\n", lst->nb);
        lst = lst->beside;
    }
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