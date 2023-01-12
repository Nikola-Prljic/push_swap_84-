/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:02:22 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/05 16:01:19 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_data *data)
{
	if (data->b == NULL)
		return ;
	ad_top(&data->a, data->b->num);
	rm_top(&data->b);
	data->b_len--;
	data->a_len++;
	if (data->b_len == 0)
		data->b = NULL;
	write(1, "pa\n", 3);
}

//pb Take the first element at the top of a and put it at the top of b. 
//Do nothing if a is empty
void	ft_pb(t_data *data)
{
	if (data->a == NULL)
		return ;
	ad_top(&data->b, data->a->num);
	rm_top(&data->a);
	data->b_len++;
	data->a_len--;
	if (data->a_len == 0)
		data->a = NULL;
	write(1, "pb\n", 3);
}

int	lst_swap(t_stack *lst, char stack)
{
	int	tmp;

	tmp = lst->num;
	lst->num = lst->next->num;
	lst->next->num = tmp;
	if (stack == 'a')
		write(1, "sa\n", 3);
	if (stack == 'b')
		write(1, "sb\n", 3);
	return (0);
}

void	sa_sb_ss(t_data *data, char stack)
{
	if (stack == 'a' && data->a)
		lst_swap(data->a, stack);
	else if (stack == 'b' && data->b)
		lst_swap(data->b, stack);
	else if (stack == 's' && data->a && data->b)
	{
		lst_swap(data->a, stack);
		lst_swap(data->b, stack);
		write(1, "ss\n", 3);
	}
}
