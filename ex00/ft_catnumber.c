/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:42:22 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/27 18:18:35 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_nbcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || (s2[i] != ' ' && s2[i] != ':'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		check_addon(char *nbr, char **dico, int i)
{
	int	j;

	j = 0;
	while (dico[j])
	{
		if (!ft_nbcmp(nbr, dico[j]))
		{
			if (nbr[0] == '1' && ft_strlen(nbr) > 2)
			{
				ft_aff("1", dico);
				write(1, " ", 1);
			}
			ft_aff(nbr, dico);
			if (ft_strlen(nbr) > 1 && i)
				write(1, " ", 1);
			return (1);
		}
		j++;
	}
	return (0);
}

void	for_aff(char *div, char nbr, char *cut, char **dico)
{
	cut[0] = '1';
	div[0] = nbr;
	div[1] = 0;
	ft_aff(div, dico);
	write(1, " ", 1);
	ft_aff(cut, dico);
	write(1, " ", 1);
}

void	ft_catnumber_2(char *nbr, char **dico, int i)
{
	int		j;
	char	*cut;
	char	div[2];

	if (nbr[i] != '0')
	{
		if (!check_addon(&nbr[i], dico, 0))
		{
			if (!(cut = malloc(sizeof(char) * (ft_strlen(nbr) + 1))))
				return ;
			cut[0] = nbr[i];
			j = 0;
			while (++j < ft_strlen(&nbr[i]))
				cut[j] = '0';
			cut[j] = '\0';
			if (!check_addon(cut, dico, 1))
				for_aff(div, nbr[i], cut, dico);
			free(cut);
		}
		else
			return ;
	}
}

void	ft_catnumber(char *nbr, char **dico)
{
	int		i;

	i = -1;
	while (nbr[++i])
	{
		ft_catnumber_2(nbr, dico, i);
	}
}
