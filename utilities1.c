/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:20:39 by sel-hadd          #+#    #+#             */
/*   Updated: 2024/07/14 16:00:53 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
//new each you if i should free the av[1] if it located
//ft_atoi(av[i++], av, free_av);
long	ft_atoi(const char *str, char **av, int free_av)
{
	long	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			error(NULL, av, free_av);
		result = result * 10 + (*str - '0');
		str++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		error(NULL, av, free_av);
	return (result * sign);
}

void	sort(int *ptr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (ptr[i] > ptr[i + 1])
		{
			tmp = ptr[i];
			ptr[i] = ptr[i + 1];
			ptr[i + 1] = tmp;
		}
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		if (ptr[i] > ptr[i + 1])
		{
			sort(ptr, size);
			break ;
		}
		i++;
	}
}

int	duplic(int *arr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		tmp = arr[i + 1];
		if (arr[i] == tmp)
			return (0);
		i++;
	}
	return (1);
}

int	check_ord(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	clean_node(t_list *stack)
{
	t_list	*tmp;

	while(stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	push(t_list **stack, int ac, char **av)
{
	int		i;
	t_list	*new;
	t_list	*tmp;

	i = 1;
	while (i < ac)
	{
		new = create_node(ft_atoi(av[i++], av, 0));
		// free the all node
		if (!new)
			return (clean_node(*stack), 0);
		if (!*stack)
		{
			new->prev = NULL;
			*stack = new;
		}
		else
		{
			tmp = last_node(*stack);
			tmp->next = new;
			new->prev = tmp;
		}
	}
	return (1);
}

t_list	*create_node(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = value;
	new->next = NULL;
	return (new);
}

t_list	*last_node(t_list *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}