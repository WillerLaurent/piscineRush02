/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:44:42 by astucky           #+#    #+#             */
/*   Updated: 2020/09/26 15:45:01 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_cw(char *str, char *charset)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		while (is_in_charset(str[i], charset) && str[i])
			i++;
		if (!(is_in_charset(str[i], charset)) && str[i])
		{
			ret++;
			while (!(is_in_charset(str[i], charset)) && str[i])
				i++;
		}
	}
	return (ret);
}

char	*make_tab(char *str, char *charset, int current)
{
	int		i;
	int		j;
	char	*ret;

	i = current;
	j = 0;
	while (!(is_in_charset(str[i], charset)) && str[i])
	{
		i++;
		j++;
	}
	if (!(ret = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	j = 0;
	i = current;
	while (!(is_in_charset(str[i], charset)) && str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = 0;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		cw;

	i = 0;
	j = 0;
	cw = ft_cw(str, charset);
	if (!(result = (char **)malloc(sizeof(char *) * (cw + 1))))
		return (0);
	while (str[i])
	{
		while (is_in_charset(str[i], charset))
			i++;
		if (!(is_in_charset(str[i], charset)) && str[i])
		{
			result[j] = make_tab(str, charset, i);
			j++;
			while (!(is_in_charset(str[i], charset)) && str[i])
				i++;
		}
	}
	result[j] = 0;
	return (result);
}
