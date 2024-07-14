/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salah <salah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 22:44:08 by sel-hadd          #+#    #+#             */
/*   Updated: 2024/07/14 15:54:55 by salah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h> //remove

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int	*parsing(int *ac, char **av, int *free_av);
void	error(int *arr, char **av, int free_av);
void	sort(int *ptr, int size);
int	duplic(int *arr, int size);
int check_ord(int *arr, int size);
long	ft_atoi(const char *str, char **av, int free_av);
char	**ft_split(char const *s, char c);
int	push(t_list **stack, int ac, char **av);
void	clean_node(t_list *stack);

t_list	*create_node(int value);
t_list	*last_node(t_list *head);

#endif
