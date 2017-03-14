/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:28:23 by asoroka           #+#    #+#             */
/*   Updated: 2016/12/09 21:05:55 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	unsigned char	c1;

	c1 = (unsigned char)c;
	write(1, &c1, 1);
}