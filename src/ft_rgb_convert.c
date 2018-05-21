/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:14:29 by avolgin           #+#    #+#             */
/*   Updated: 2018/04/26 12:58:12 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	rgb_conv(unsigned char c1, unsigned char c2, unsigned char c3)
{
	unsigned int	ret;

	ret = c3;
	ret <<= 8;
	ret = ret | c2;
	ret <<= 8;
	ret = ret | c1;
	return (ret);
}
