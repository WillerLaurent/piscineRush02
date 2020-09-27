/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:29:57 by alferran          #+#    #+#             */
/*   Updated: 2020/09/27 14:15:23 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_aff(char *nbr, char **dico)
{
	int i;
	int j;
	int len;

	i = 0;
	while(dico[i])
	{
		if (!ft_nbcmp(nbr,dico[i]))
		{
			j = 0;
			len = ft_strlen(dico[i]);
			len--;
			while(dico[i][len] == ' ')
				len--;
			while (dico[i][j] >= '0' && dico[i][j] <= '9')
				j++;
			while (dico[i][j] == ' ')
				j++;
			if (dico[i][j] == ':')
				j++;
			while (dico[i][j] == ' ')
				j++;
			write(1, &dico[i][j], len - j + 1);
			return ;
		}
		i++;
	}
}

void	ft_aff_all(char **tab, char **dico, int size)
{
	int		i;
	int		j;
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
				free(sep);
			}
		}
		i++;
	}

}
