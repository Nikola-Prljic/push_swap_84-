/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprljic <nprljic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:03:25 by nprljic           #+#    #+#             */
/*   Updated: 2023/01/08 01:26:40 by nprljic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *lst, int len)
{
	if (lst == NULL)
		return ;
	while (len > 0)
	{
		ft_printf("%i ", lst->num);
		lst = lst->next;
		len--;
	}
}

void	print_all_stacks(t_data *data)
{
	ft_printf("\nstack a : ");
	print_stack(data->a, data->a_len);
	ft_printf("\nstack b : ");
	print_stack(data->b, data->b_len);
}

void	create_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->a_len = 0;
	data->b_len = 0;
	data->one_eighth = 0;
	data->one_quater = 0;
	data->three_eighth = 0;
	data->three_quater = 0;
	data->five_eighth = 0;
	data->median = 0;
	data->seven_eighth = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	create_data(data);
	if (argc > 1 && argv[1][0] != '\0')
	{
		argv_to_stack(data, argc, argv);
		meridian(data);
		if (is_sorted(data))
			sort(data);
	}
	free_stacks(data);
	return (0);
}
