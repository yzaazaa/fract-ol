/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:45:41 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/01/05 04:37:21 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/math.h"

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled_num / old_max + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.real = z1.real + z2.real;
	res.imaginary = z1.imaginary + z2.imaginary;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
	res.imaginary = 2 * z.real * z.imaginary;
	return (res);
}

int	check_sign(char **s)
{
	int	sign;

	sign = 1;
	if (*(*s) == '+')
		(*s)++;
	else if (*(*s) == '-')
	{
		sign = -1;
		(*s)++;
	}
	return (sign);
}
