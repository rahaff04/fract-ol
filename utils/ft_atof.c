/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <ralamair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:54:50 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/12 15:00:08 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h" 

static int get_sign(char **s)
{
    int sign;

    sign = 1;
    while (**s == ' ' || (**s >= 9 && **s <= 13))
        (*s)++;
    if (**s == '-' || **s == '+')
    {
        if (**s == '-')
            sign = -1;
        (*s)++;
    }
    return (sign);
}

static double get_number(char **s)
{
    double r;
    double d;

    r = 0;
    d = 1;
    while (**s >= '0' && **s <= '9')
        r = r * 10 + (*(*s)++ - '0');
    if (**s == '.')
    {
        (*s)++;
        while (**s >= '0' && **s <= '9')
        {
            d /= 10;
            r += (*(*s)++ - '0') * d;
        }
    }
    return (r);
}
double ft_atof(char *str)
{
    int sign;

    sign = get_sign(&str);
    return (get_number(&str) * sign);
}
