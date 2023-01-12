/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:58:15 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:01:54 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(t_data *data, char *str)
{
	int				i;
	long long int	num;
	long long int	min;

	i = -1;
	min = 1;
	num = 0;
	if (str[++i] == '-')
		min *= -1;
	else
		i--;
	while (str[++i])
		num = num * 10 + (str[i] - 48);
	if (min == -1)
		num *= min;
	if (num > 2147483647 || num < -2147483648)
	{
		free(str);
		push_swap_error(data);
	}
	return (0);
}

int	is_minus_or_num(char *str, int x)
{
	int	i;

	i = 0;
	if (str[x] == '-')
	{
		i++;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		i++;
		x++;
	}
	return (i);
}

void	extract_number(t_data *data, char **str, int y)
{
	int		x;
	int		start;
	int		len;
	char	*substr;

	x = 0;
	start = 0;
	while (str[y][x])
	{
		while (str[y][x] == ' ')
		{
			start++;
			x++;
		}
		if (str[y][x] == '\0')
			return ;
		len = is_minus_or_num(str[y], x);
		x += len;
		substr = ft_substr(str[y], start, len);
		is_int(data, substr);
		addstack_end(&data->a, atoi(substr));
		free(substr);
		data->a_len++;
		start += len;
	}
}
