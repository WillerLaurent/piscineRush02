/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:30:24 by astucky           #+#    #+#             */
/*   Updated: 2020/09/27 14:05:06 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_splitnbr(char *nbr, char **dico)
{
	char	**splitted;
	int		size;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(nbr);
	if (len % 3 == 0)
		size = len / 3;
	else
		size = len / 3 + 1;
	if (!(splitted = (char **)malloc(sizeof(char *) * size)))
		return ;
	i = 0;
	j = 0;
	while (i < size)
	{
		if (ft_strlen(&nbr[j]) % 3 == 0)
		{
			splitted[i] = ft_strdup(&nbr[j], 3);
			j += 3;
		}
		else
		{
			splitted[i] = ft_strdup(&nbr[j], ft_strlen(&nbr[j]) % 3);
			j += ft_strlen(&nbr[j]) % 3;
		}
		i++;
	}
	ft_aff_all(splitted, dico, size);
	i = 0;
	while (i < size)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
