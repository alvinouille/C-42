/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-sain <ale-sain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:40:40 by ale-sain          #+#    #+#             */
/*   Updated: 2022/11/16 14:04:26 by ale-sain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>
int    ft_putnbr_hex(unsigned long int nb, char *base)
{
    unsigned long int    n;

    n = nb;
    int i;
    
    i = 0;
    if (n == 0)
    {
        i = 1;
        ft_putchar_fd('0', 1);
        return (i);
    }
    if (n >= 16)
    {
        i += ft_putnbr_hex(n / 16, base);
        i += ft_putnbr_hex(n % 16, base);
    }
    else
    {
        i++;
        ft_putchar_fd(base[n], 1);
    }
    return (i);
}

static int	convers_print(void *ptr)
{
    unsigned long int nb = (unsigned long int) ptr;
    ft_putstr_fd("0x", 1);
    return (ft_putnbr_hex(nb, "0123456789abcdef") + 2);
}

int     ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int nb;
    int tmp;
    void    *p;

    va_start(args, (char *)format);
    i = 0;
    nb = 0;
    tmp = 0;
    while (format[i])
    {
        if (format[i] != '%')
        {
            ft_putchar_fd(format[i], 1);
            nb++;
        }
        else
        {
            if (format[i + 1] == 'd' || format[i + 1] == 'i')
            {
                tmp = va_arg(args, int);
                ft_putnbr_fd(tmp, 1);
                nb += ft_strlen(ft_itoa(tmp));
            }
            if (format[i + 1] == '%')
            {
                ft_putchar_fd('%', 1);
                nb++;
            }
            if (format[i + 1] == 'c')
            {
                unsigned char c = (unsigned char) va_arg(args, int); /*trouver pq int et pas char*/
                ft_putchar_fd(c, 1);
                nb++;
            }
            if (format[i + 1] == 's')
            {   
                char *s = (char *) va_arg(args, char *);
                if (s == NULL && format[i + 2] != '\n')
                {
                    ft_putstr_fd("(null)", 1);
                    nb += 6;
                }
                else if (s == NULL && format[i + 2] == '\n')
                    ft_putstr_fd(NULL, 1);
                else
                {
                    ft_putstr_fd(s, 1);
                    nb += ft_strlen(s);
                }
            }
            if (format[i + 1] == 'p')
            {
                p = va_arg(args, void *);
                if (p == NULL)
                {
                    ft_putstr_fd("(nil)", 1);
                    nb += 5;
                }
                else
                {
                    unsigned long int nb = (unsigned long int)p;
                    ft_putstr_fd("0x", 1);
                    nb += ft_putnbr_hex(nb, "0123456789abcdef") + 2;
                }     
            }
            if (format[i + 1] == 'u')
            {
                tmp = va_arg(args, unsigned int);
                nb += ft_putnbr_un(tmp);
            }
            if (format [i + 1] == 'x')
                nb += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789abcdef");
            if (format[i + 1] == 'X')
                nb += ft_putnbr_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
            i++;
        }
        i++;
    }
    va_end(args);
    return (nb);
}

#include <limits.h>
#include <stdio.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
int main()
{
    int a = 0;
    int a1 = 0;
    int a2 = 0;
    printf("\nBASE\n\n");
    a1 = ft_printf("%%d/i/d : les %d et %i petits chats et %d chiens\n", -3, -2147483647, 20000);
    a2 = printf("%%d/i/d : les %d et %i petits chats et %d chiens\n", -3, -2147483647, 20000);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("%%/c : les %% de chiens sont plus grands que les %c quarts\n", '3');
    a2 = printf("%%/c : les %% de chiens sont plus grands que les %c quarts\n", '3');
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("%%s : les %s \n", "trois petits chats");
    a2 = printf("%%s : les %s \n", "trois petits chats");
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("%%p : sont ici : %p\n", &a);
    a2 = printf("%%p : sont ici : %p\n", &a);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("%%u : les %u gros chiens\n", -3042);
    a2 = printf("%%u : les %u gros chiens\n", -3042);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("%%X : les %X gros chiens\n", -3042);
    a2 = printf("%%X : les %X gros chiens\n", -3042);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);  
    printf("\nTOUT A 0\n\n");
    a1 = ft_printf("les %d et %i petits chats et %d chiens\n", 0, 0, 0);
    a2 = printf("les %d et %i petits chats et %d chiens\n", 0, 0, 0);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("les %% de chiens sont plus grands que les %c quarts\n", 0);
    a2 = printf("les %% de chiens sont plus grands que les %c quarts\n", 0);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("les %s sont ici : %p\n", "\0", NULL);
    a2 = printf("les %s sont ici : %p\n", "\0", NULL);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("les %u gros chiens sont %X fois plus gros\n", 0, 0);
    a2 = printf("les %u gros chiens sont %X fois plus gros\n", 0, 0);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    printf("\nTOUT AU MAXIMUM\n\n");
    a1 = ft_printf("les %d et %i petits chats et %d chiens\n", INT_MAX, INT_MAX, INT_MIN);
    a2 = printf("les %d et %i petits chats et %d chiens\n", INT_MAX, INT_MAX, INT_MIN);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("les %% de chiens sont plus grands que les %c quarts\n", 131);
    a2 = printf("les %% de chiens sont plus grands que les %c quarts\n", 131);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("les %u gros chiens sont %X fois plus gros\n", UINT_MAX, -INT_MAX);
    a2 = printf("les %u gros chiens sont %X fois plus gros\n", UINT_MAX, -INT_MAX);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    printf("\nESSAI CRASH POINTEURS\n\n");
    char    *str = NULL;
    a1 = ft_printf("%s", str);    //OK : renvoit bien (null)
    a2 = printf("%s", str);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2); 
    a1 = ft_printf("%p", str);   //OK : renvoit bien (nil)
    a2 = printf("%p", str);  
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    a1 = ft_printf("%p\n", str);     //OK : renvoit bien (nil)
    a2 = printf("%p\n", str);
    if (a1 == a2)
        printf(ANSI_COLOR_GREEN     "OK!"     ANSI_COLOR_RESET "\n");
    else
        printf(ANSI_COLOR_RED       "KO!\tma fonction : %d\n   \tfonction de base : %d" ANSI_COLOR_RESET "\n", a1, a2);
    printf("\nDOIT SEGFAULT\n\n");
    
    printf("ma fct 2 = %d\n", ft_printf("%s\n", str));  //OK : seg fault si \n colle a la chaine null
    //printf("fct 2 = %d\n", printf("%s\n", str));  
} 
