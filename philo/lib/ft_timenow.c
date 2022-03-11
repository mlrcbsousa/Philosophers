/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timenow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:15:34 by msousa            #+#    #+#             */
/*   Updated: 2022/03/11 00:46:23 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

long	ft_timenow(void)
{
	long			time_ms;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_ms);
}
