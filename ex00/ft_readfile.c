/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:10:11 by alferran          #+#    #+#             */
/*   Updated: 2020/09/27 16:16:19 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	**ft_readfile(char *name)
{
	char	file[11];
	int		nb;
	int		count;
	char	*ret;
	int		fd;

	nb = 1;
	count = 0;
	fd = open(name, O_RDONLY);
	while (nb)
	{
		nb = read(fd, file, 10);
		count += nb;
	}
	close(fd);
	if (!(ret = (char *)malloc(sizeof(char) * (count + 1))))
		return (0);
	fd = open(name, O_RDONLY);
	read(fd, ret, count);
	ret[count] = 0;
	return (ft_split(ret, "\n"));
}

int		ft_linecmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] != ' ' && s1[i] != ':' && s1[i] != 0) ||
			(s2[i] != ' ' && s2[i] != ':' && s2[i] != 0))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		check_dico(char **dico)
{
	int i;
	int j;

	i = 0;
	while (dico[i])
	{
		j = 0;
		while (dico[i][j] >= '0' && dico[i][j] <= '9')
			j++;
		while (dico[i][j] == ' ')
			j++;
		if (dico[i][j] == ':')
			j++;
		while (dico[i][j] == ' ')
			j++;
		while (dico[i][j] >= 32 && dico[i][j] <= 126)
			j++;
		if (dico[i][j] != 0)
			return (0);
		i++;
	}
	return (1);
}

int		checkdict(char **dico)
{
	int		i;
	int		j;

	i = 0;
	while (dico[i + 1])
	{
		j = i + 1;
		while (dico[j])
		{
			if (ft_linecmp(dico[i], dico[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (!ft_parsedict(dico))
		return (0);
	if (check_dico(dico))
		return (1);
	return (0);
}
