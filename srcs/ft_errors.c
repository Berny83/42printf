/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 10:42:12 by aagrivan          #+#    #+#             */
/*   Updated: 2020/07/29 10:42:12 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_errors(int i)
{
	if (i == 1)
		ft_putendl("You can't use this flag with %s.");
	else if (i == 2)
		ft_putendl("You can't use length modifier with %s.");
	else if (i == 3)
		ft_putendl("You can't use this flag with %c.");
	else if (i == 4)
		ft_putendl("You can't use length modifier with %c.");
	else if (i == 5)
		ft_putendl("You can't use precision with %c.");
	else if (i == 6)
		ft_putendl("You can't use this flag with %p.");
	else if (i == 7)
		ft_putendl("You can't use length modifier with %p.");
	else if (i == 8)
		ft_putendl("You can't use precision with %p.");
	exit(0);
}