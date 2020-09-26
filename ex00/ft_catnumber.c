/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:42:22 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/26 19:49:48 by alferran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_aff(char *nbr, char **dico);

#include <stdlib.h>

int	ft_nbcmp(char *s1, char *s2)
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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_addon(char *nbr, char **dico)
{
	int	j;

	j = 0;
	while (dico[j])
	{
		if (!ft_nbcmp(nbr, dico[j]))
		{
			ft_aff(nbr, dico);
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_catnumber(char *nbr, char **dico)
{
	int		ln_str;
	int		i;
	char	*cut;
	int		j;
	char	div[2];

	ln_str = ft_strlen(nbr);
	while (nbr[i])
	{
		j = 0;
		if (!check_addon(&nbr[i], dico))
		{
			if (!(cut = (char *)malloc(sizeof(char) * (ln_str + 1))))
				return ;
			cut[0] = nbr[i];
			j = 1;
			while (j < ft_strlen(&nbr[i]))
			{
				cut[j] = '0';
				j++;
			}
			cut[j] = '\0';
			j = 0;
			if (!check_addon(cut, dico))
			{
				cut[0] = '1';
				div[0] = nbr[i];
				div[1] = 0;
				ft_aff(div, dico);
				ft_aff(cut, dico);
			}
			free(cut);
			i++;
		}
		else
			return ;
	}

}
