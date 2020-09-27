/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:47:59 by astucky           #+#    #+#             */
/*   Updated: 2020/09/27 17:00:34 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		testnbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	char	**file;
	int		i;
	char	*nbr;

	if (ac == 2 && testnbr(av[1]))
	{
		file = ft_readfile("numbers.dict");
		nbr = av[1];
	}
	else if (ac == 3 && testnbr(av[2]))
	{
		file = ft_readfile(av[1]);
		nbr = av[2];
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!checkdict(file))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!ft_atoi(nbr))
	{
		ft_aff("0",file);
		write(1, "\n", 1);
		return (0);
	}
	if (!check_addon(nbr, file, 0))
		ft_splitnbr(nbr, file);
	write(1, "\n", 1);
	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
}
