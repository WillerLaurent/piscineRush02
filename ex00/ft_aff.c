/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:29:57 by alferran          #+#    #+#             */
/*   Updated: 2020/09/27 15:12:12 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_aff_letters(char *str)
{
	int j;
	int len;

	j = 0;
	len = ft_strlen(str);
	len--;
	while (str[len] == ' ')
		len--;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	while (str[j] == ' ')
		j++;
	if (str[j] == ':')
		j++;
	while (str[j] == ' ')
		j++;
	write(1, &str[j], len - j + 1);
	return ;
}

void	ft_aff(char *nbr, char **dico)
{
	int i;

	i = 0;
	while (dico[i])
	{
		if (!ft_nbcmp(nbr, dico[i]))
			ft_aff_letters(dico[i]);
		i++;
	}
}

void	ft_aff_sep(int nb_zeros, char *sep, char **dico)
{
	int j;

	j = 1;
	sep[0] = '1';
	while (j < nb_zeros + 1)
	{
		sep[j] = '0';
		j++;
	}
	sep[j] = '\0';
	write(1, " ", 1);
	ft_aff(sep, dico);
	write(1, " ", 1);
}

void	ft_aff_all(char **tab, char **dico, int size)
{
	int		i;
	int		nb_zeros;
	char	*sep;

	i = 0;
	while (i < size)
	{
		if (ft_atoi(tab[i]) != 0)
		{
			ft_catnumber(tab[i], dico);
			if (i < size - 1)
			{
				nb_zeros = 3 * (size - i - 1);
				if (!(sep = (char *)malloc(sizeof(char) * (nb_zeros + 2))))
					return ;
				ft_aff_sep(nb_zeros, sep, dico);
				free(sep);
			}
		}
		i++;
	}
}
