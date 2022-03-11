/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:51:30 by msousa            #+#    #+#             */
/*   Updated: 2022/02/11 16:13:14 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_bool	ft_isnumber_u(char *str)
{
	if (!*str)
		return (FALSE);
	while (*str)
		if (!ft_isdigit(*str++))
			return (FALSE);
	return (TRUE);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
    printf("%s : %d\n", argv[1], ft_isnumber_u(argv[1]));
	else
		printf("Error: requires 1 argument.\n");
	return (0);
}
*/
