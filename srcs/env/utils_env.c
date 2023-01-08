/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinhosujo <ratinhosujo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:07:19 by dmendonc          #+#    #+#             */
/*   Updated: 2023/01/08 15:07:46 by ratinhosujo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*add_estr(t_data *data, int index)
{
	int		i;
	int		len;
	char	*string;

	i = -1;
	len = len_str(data->envp[index]);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len] = '\0';
	while (data->envp[index][++i])
		string[i] = data->envp[index][i];
	return (string);
}

char	*add_str( char *str)
{
	int		i;
	int		len;
	char	*string;

	i = -1;
	len = len_str(str);
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len] = '\0';
	while (str[++i])
		string[i] = str[i];
	return (string);
}

int	equal(t_data *data, char *string, int index)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (string[i] != data->envp[index][i])
			return (0);
	}
	return (1);
}

int	is_dot_cmd(char *str)
{
	int		i;
	char	*ptr1;

	ptr1 = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			ptr1 = &str[i];
		i++;
	}
	if (ptr1 == NULL)
		return (1);
	i = 0;
	while (ptr1[i])
	{
		if (ptr1[i] == '/' && i == 0 && ptr1[i])
			i++;
		if (ptr1[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
