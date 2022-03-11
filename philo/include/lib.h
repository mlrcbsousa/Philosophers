/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:02:10 by msousa            #+#    #+#             */
/*   Updated: 2022/03/10 21:12:45 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# include "ft_boolean.h"

int		ft_atoi(const char *str);
t_bool	ft_isdigit(int c);
t_bool	ft_isnumber_u(char *str);
t_bool	ft_isspace(char c);
long	ft_timenow(void);
void	ft_usleep(int ms);

#endif
