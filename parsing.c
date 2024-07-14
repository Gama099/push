#include "push_swap.h"

void error(int *arr, char **av, int free_av) {
    char **tmp;
    
    if (arr)
        free(arr); // Freeing arr if it's allocated
    if (free_av) {
        av++; // Move av to the next pointer in the array (assuming av[0] is program name)
        tmp = av; // Store av in tmp to free it later
        
        while (*av) // Loop until av points to NULL
            free(*av++); // Free each string pointed by av
        free(*av);
        //free(tmp); // Free the array of pointers (av)
    }
    
    write(2, "error\n", 6); // Write error message to stderr
    exit(EXIT_FAILURE); // Exit with failure status
}

void	cpy(int	*arr, char **av, int size)
{
	int i;

	i = 1;
	while (size)
	{
		*arr++ = ft_atoi(av[i++], av, 0);
		size--;
	}
}

void	long_arg(int *ac, char **av, int *free_av)
{
	char	**tmp;

	*free_av = 1;
	*ac = 1;
	tmp = ft_split(av[1], ' ');
    if (!tmp)
        error(NULL, av, *free_av);
	//free(av[1]);
	while (*tmp)
		av[(*ac)++] = *tmp++;
	av[*ac] = NULL;
}

int	*parsing(int *ac, char **av, int *free_av)
{
	//var that will track if we get ""
    int j;
    int i;
	int	*arr;

    i = 1;
	//check if the arg is "......"
	if (*ac == 2)
	{
		//funtion that will split and check if and chanch ac and av by refreence
		//what i should name it spliting
        //printf("%d\n", free_av); 
		long_arg(ac, av, free_av);
        //printf("%d\n", free_av);
		// so now we have the split and we shoul free av if we done
	}
	//now we check if it's numbers
	//if it's not it exit for atoi but we should clean the av if the ""
	while (i < *ac)
        j = ft_atoi(av[i++], av, *free_av);

    // intill here we check if the numbers are int and no max and min
	//so now i have to copy to the aray so now i have to 
	arr = malloc(sizeof(int) * (*ac - 1));
	//check if the input it's in the correct order
	if (!arr)
		error(arr, av, *free_av);
	cpy(arr, av, *ac - 1);
	if ((!check_ord(arr, *ac - 1)))
		error(arr, av, *free_av);
	//sort the arr
	sort(arr, (*ac - 1));
	//check the duplication
	if (!duplic(arr, *ac - 1))
		error(arr, av, *free_av);
	return (arr);
}
