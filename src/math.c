/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:28:51 by lhumbert          #+#    #+#             */
/*   Updated: 2022/04/04 22:28:58 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}
