/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astucky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:39:10 by astucky           #+#    #+#             */
/*   Updated: 2020/09/27 16:56:33 by astucky          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_nbcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_aff(char *nbr, char **dico);
int		ft_atoi(char *str);
void	ft_catnumber(char *nbr, char **dico);
char	**ft_split(char	*str, char *charset);
char	**ft_readfile(char *name);
int		checkdict(char **dico);
void	ft_splitnbr(char *nbr, char **dico);
char	*ft_strdup(char *src, int nbc);
void	ft_aff_all(char **tab, char **dico, int size);
int		ft_linecmp(char *s1, char *s2);
int		ft_parsedict(char **dico);
int		check_addon(char *nbr, char **dico, int i);

#endif
