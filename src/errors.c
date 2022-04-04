/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:31:47 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/04 22:32:06 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise_error(int errcode)
{
	ft_putstr_fd("Error\n", 1);
	exit(errcode);
}
