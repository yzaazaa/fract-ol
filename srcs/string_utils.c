/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:26 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/01/03 15:47:32 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/string.h"

int	ft_strcmp(char *s1, char *s2)
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

void	ft_putendl_fd(char *str, int fd)
{
	if (!str || fd < 0)
		return ;
	while (*str)
		write(fd, str++, 1);
	write(fd, "\n", 1);
}

void	ft_error(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

double	ft_atod(char *s)
{
	long	int_part;
	double	fractional_part;
	double	pow;
	int		sign;

	int_part = 0;
	fractional_part = 0;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	sign = check_sign(&s);
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

int	is_double(char *s)
{
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (*s == '\0')
		return (0);
	while (*s && *s >= '0' && *s <= '9')
		s++;
	if (*s == '.')
		s++;
	while (*s && *s >= '0' && *s <= '9')
		s++;
	return (*s == '\0');
}
