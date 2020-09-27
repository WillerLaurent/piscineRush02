/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsedict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:45:53 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/27 17:58:10 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_parsedict_2(char **dico, char *ref_i)
{
	int j;

	j = 0;
	while (dico[j] && ft_linecmp(ref_i, dico[j]))
		j++;
	if (!dico[j])
		return (0);
	return (1);
}

void	freefile(char **file)
{
	int i;

	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}

int		ft_parsedict(char **dico)
{
	int		i;
	char	**ref;

	ref = ft_readfile("ref.dict");
	i = 0;
	while (ref[i])
	{
		if (!ft_parsedict_2(dico, ref[i]))
		{
			freefile(ref);
			return (0);
		}
		i++;
	}
	freefile(ref);
	return (1);
}
