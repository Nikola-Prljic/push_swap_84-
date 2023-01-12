/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:58:42 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:23:21 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quater_to_b(t_data *data, int eighth)
{
	int	len;

	len = data->a_len;
	while (len > 0)
	{
		bigger_median(data, eighth);
		len--;
	}
}

void	sort_big(t_data *data)
{
	int	eighth;

	eighth = 1;
	while (eighth < 9)
	{
		quater_to_b(data, eighth);
		move_to_a(data);
		eighth++;
	}
}
