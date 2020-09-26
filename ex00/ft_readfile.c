/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:33:02 by astucky           #+#    #+#             */
/*   Updated: 2020/09/26 14:48:54 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_readfile(char *name)
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
	printf("%s", ret);
	return (ret);
}