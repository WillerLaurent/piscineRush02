/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alferran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 19:29:57 by alferran          #+#    #+#             */
/*   Updated: 2020/09/26 19:54:43 by alferran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_nbcmp(char *s1,char *s2);
int ft_strlen(char *str);

void ft_aff(char *nbr, char **dico)
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

