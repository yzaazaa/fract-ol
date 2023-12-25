/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:26 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/25 22:26:55 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int ft_strcmp(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (0);
    while (*s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return ((int)*s1 - (int)*s2);
}

void    ft_putendl_fd(char *str, int fd)
{
    if (!str || fd < 0)
        return ;
    while (*str)
        write(fd, str++, 1);
    write(fd, "\n", 1);
}

void    malloc_error(void)
{
    perror("Malloc error");
    exit(EXIT_FAILURE);
}

double  ft_atod(char *s)
{
    long    int_part;
    double  fractional_part;
    double  pow;
    int     sign;

    int_part = 0;
    fractional_part = 0;
    sign = 1;
    pow = 1;
    while ((*s >= 9 && *s <= 13) || *s == 32)
        s++;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else if (*s == '+')
    {
        sign = 1;
        s++;
    }
    while (*s != '.' && *s)
        int_part = (int_part * 10) + (*s++ - '0');
    if (*s == '.')
        s++;
    while (*s)
    {
        pow /= 10;
        fractional_part = fractional_part + (*s++ - '0') * pow;
    }
    return ((int_part + fractional_part) * sign);
}
