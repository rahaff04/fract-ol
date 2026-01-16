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

static int get_sign(char *s)
{
    int sign;
    int i;

    sign = 1;
    i= 0;
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    return (sign);
}

static double get_number(char *s)
{
    double res;
    double dec;
    unsigned int i;

    res = 0;
    dec = 1;
    i = 0;
    while ((s[i] >= '0' && s[i] <= '9'))
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] == '.')
    {
        i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            res += (s[i] - '0') * dec;
            dec /= 10;
            i++;
        }
    }
    return (res);
}
double ft_atof(char *str)
{
    int sign;

    sign = get_sign(str);
    return (get_number(str) * sign);
}
