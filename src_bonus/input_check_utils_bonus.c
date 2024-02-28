/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:32:56 by francfer          #+#    #+#             */
/*   Updated: 2024/02/27 18:12:17 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

void	skipzeros(const char **s)
{
	while (**s == '0')
		(*s)++;
}

int	determinesign(const char **s)
{
	int	sign;

	sign = 1;
	if (**s == '-')
	{
		sign = -1;
		(*s)++;
	}
	else if (**s == '+')
		(*s)++;
	return (sign);
}

int	length(const char *s, int sign)
{
	int	len;

	len = 0;
	while (s[len] >= '0' && s[len] <= '9')
		len++;
	return (len * sign);
}
