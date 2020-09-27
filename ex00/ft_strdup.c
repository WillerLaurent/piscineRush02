/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:57:08 by astucky           #+#    #+#             */
/*   Updated: 2020/09/27 12:00:10 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strdup(char *src, int nbc)
{
	char	*ret;
	int		i;

	if (!(ret = (char *)malloc(sizeof(src) * (nbc + 1))))
		return (0);
	i = 0;
	while (src[i] && i < nbc)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}
