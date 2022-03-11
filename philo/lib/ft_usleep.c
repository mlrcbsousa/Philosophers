/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:00:23 by msousa            #+#    #+#             */
/*   Updated: 2022/03/10 19:00:56 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_usleep(int ms)
{
	long	time;

	time = ft_timenow();
	while ((ft_timenow() - time) < ms)
		usleep(ms);
}
