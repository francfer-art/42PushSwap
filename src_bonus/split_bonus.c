/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francfer <francfer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:11:35 by francfer          #+#    #+#             */
/*   Updated: 2024/02/27 18:13:25 by francfer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*stringcpy(char *str, char *s, int len)
{
	int	i;

	i = -1;
	while (++i < len && s[i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

int	word_count(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			k++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (k);
}

static char	**spliting(char *str, char **new)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		j = i;
		while (str[i] && str[i] != ' ')
			i++;
		if (i > j)
		{
			new[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!new)
				return (NULL);
			stringcpy(new[k++], &str[j], i - j);
		}
	}
	new[k] = NULL;
	return (new);
}

char	**ft_split(char *str)
{
	char	**new;

	new = malloc(sizeof(char *) * word_count(str) + 1);
	if (!new)
		return (NULL);
	new = spliting(str, new);
	return (new);
}

int	splited_size(char **words)
{
	int	size;

	size = 0;
	while (*words)
	{
		words++;
		size++;
	}
	return (size);
}
