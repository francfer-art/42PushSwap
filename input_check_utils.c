/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:32:56 by francfer          #+#    #+#             */
/*   Updated: 2024/02/16 12:19:20 by francfer         ###   ########.fr       */
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

//int	nbstr_cmp(const char *s1, const char *s2)
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
int nbstr_cmp(const char *s1, const char *s2)
{
	int sign1;
	int	sign2;
	int len1;
	int len2;

	sign1 = 1;
	sign2 = 1;
	len1 = 0;
	len2 = 0;
    while (*s1 == '0')
		s1++;
    while (*s2 == '0')
		s2++;
    if (*s1 == '-')
	{
        sign1 = -1;
        s1++;
    } else if (*s1 == '+')
        s1++;
    if (*s2 == '-') {
        sign2 = -1;
        s2++;
    } else if (*s2 == '+') {
        s2++;
    }
    while (*s1 == '0')
		s1++;
    while (*s2 == '0')
		s2++;
    while (s1[len1] >= '0' && s1[len1] <= '9')
		len1++;
    while (s2[len2] >= '0' && s2[len2] <= '9')
		len2++;
    len1 *= sign1;
    len2 *= sign2;
    if (len1 != len2)
		return (len1 > len2) ? 1 : -1;
    while (*s1 == *s2 && *s1 != '\0')
	{
        s1++;
        s2++;
    }
    if (*s1 == '\0')
		return 0;
    return (*s1 > *s2) ? 1 : -1;
}
