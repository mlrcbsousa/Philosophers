/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <msousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:50:39 by msousa            #+#    #+#             */
/*   Updated: 2022/02/11 16:13:48 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

t_bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
