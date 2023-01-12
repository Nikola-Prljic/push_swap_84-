/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:47:28 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/07 00:39:19 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_list(t_stack *lst, int len)
{
	t_stack	*temp;

	if (lst == NULL)
		return ;
	temp = lst;
	while (len > 0)
	{
		lst = lst->next;
		free(temp);
		temp = lst;
		len--;
	}
}

void	free_stacks(t_data *data)
{
	destroy_list(data->a, data->a_len);
	destroy_list(data->b, data->b_len);
	free(data);
}

void	push_swap_error(t_data *data)
{
	write(2, "Error\n", 6);
	free_stacks(data);
	exit(-1);
}
