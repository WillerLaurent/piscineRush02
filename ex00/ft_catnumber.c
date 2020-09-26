/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:42:22 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/26 16:30:29 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *to_find,char *model)
{
	int i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != model[i])
			return (0);
		i++;
		if (!to_find[i] && model[i] == ' ')
			return (1);
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

char	*ft_catnumber(char *str, char **tab)
{
	int ln_str;
	int i;
	char *result;

	ln_str = ft_strlen(str);
		
}

int main(int argc, char **argv)
{
	
}
