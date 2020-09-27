/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:55:45 by astucky           #+#    #+#             */
/*   Updated: 2020/09/27 16:39:30 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_parsedict(char **dico)
{
	int		i;
	int		j;
	char	**ref;

	ref = ft_readfile("ref.dict");
	i = 0;
	while (ref[i])
	{
		j = 0;
		while (dico[j] && ft_linecmp(ref[i], dico[j]))
			j++;
		if (!dico[j])
		{
			i = 0;
			while (ref[i])
			{
				free(ref[i]);
				i++;
			}
			free(ref);
			return (0);
		}
		i++;
	}
	i = 0;
	while (ref[i])
	{
		free(ref[i]);
		i++;
	}
	free(ref);
	return (1);
}
