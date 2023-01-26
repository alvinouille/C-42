/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvina <alvina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:34:30 by ale-sain          #+#    #+#             */
/*   Updated: 2023/01/26 18:25:15 by alvina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*ft_line(char *keep);
char	*ft_keep_memory(char *keep);
char	*ft_strjoin_modif(char *keep, char *buff);
char	*loopin(int fd, char **keep);
char	*get_next_line(int fd, int flag);

#endif
