/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:32:56 by francfer          #+#    #+#             */
/*   Updated: 2024/02/22 11:33:48 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

// int	nbstr_cmp(const char *s1, const char *s2)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = i;
//	if (s1[i] == '+')
//	{
//		if (s2[j] != '+')
//			i++;
//	}
//	else
//	{
//		if (s2[j] == '+')
//			j++;
//	}
//	while (s1[i] == '0' && s1[i])
//		i++;
//	while (s2[j] == '0' && s2[j])
//		j++;
//	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
//	{
//		i++;
//		j++;
//	}
//	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
//}

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
