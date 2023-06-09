/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:58:17 by dajeon            #+#    #+#             */
/*   Updated: 2023/05/30 18:13:34 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror_malloc(char *name)
{
	ft_putstr_fd(name, 2);
	ft_putendl_fd(": Mallocation failed", 2);
}

void	ft_perror_var(char *name, int nbr)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": Need exactly 4 variables. You: ", 2);
	ft_putnbr_fd(nbr, 2);
	ft_putendl_fd("", 2);
}

void	ft_strs_lfree(char **strs, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
			free(strs[i++]);
	}
	else
	{
		while (strs[i])
			free(strs[i++]);
	}
	free(strs);
}

void	ft_strss_lfree(char ***strss, int len)
{
	int	i;

	i = 0;
	if (len > 0)
	{
		while (i < len)
			ft_strs_lfree(strss[i++], 0);
	}
	else
	{
		while (strss[i])
			ft_strs_lfree(strss[i++], 0);
	}
	free(strss);
}

void	ft_perror(char *name1, char *name2)
{
	ft_putstr_fd(name1, 2);
	ft_putstr_fd(": ", 2);
	perror(name2);
}
