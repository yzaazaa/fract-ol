/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:56:51 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/01/03 15:47:43 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "math.h"

int			ft_strcmp(char *s1, char *s2);
void		ft_putendl_fd(char *str, int fd);
void		ft_error(char *s);
double		ft_atod(char *s);
int			is_double(char *s);

#endif