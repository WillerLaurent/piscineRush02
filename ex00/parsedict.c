/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:45:53 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/27 17:46:15 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_parsedict_2(char **dico, char *ref_i, int i)
{
	int j;
	j = 0;
	while (ft_linecmp(ref[i], dico[j]) && dico[j])
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
	return (i);
}

int		ft_parsedict(char **dico)
{
	int		i;
	int		j;
	char	**ref;

	ref = ft_readfile("ref.dict");
	i = 0;
	while (ref[i])
	{
	/*	j = 0;
		while (ft_linecmp(ref[i], dico[j]) && dico[j])
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
		}*/
		i = ft_parsedict_2(dico, ref[i], i);
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
