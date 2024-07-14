#include "push_swap.h"

int	main(int ac, char **av)
{
	int	free_av;
	int	*arr;
	t_list *stack_a;

	stack_a = NULL;
	free_av = 0;
	if (ac > 1)
	{
		arr = parsing(&ac, av, &free_av);
		if (!push(&stack_a, ac, av))
			error(arr, av, free_av);
		while (stack_a)
		{
			printf("%d\n", stack_a->num);
			stack_a = stack_a->next;
		}
	}
}
