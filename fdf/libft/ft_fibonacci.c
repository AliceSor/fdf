/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoroka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:44:32 by asoroka           #+#    #+#             */
/*   Updated: 2016/10/01 19:15:47 by asoroka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	else
	{
		if (index == 0 || index == 1)
		{
			return (index);
		}
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	}
}
