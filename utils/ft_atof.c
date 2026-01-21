/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralamair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:30:50 by ralamair          #+#    #+#             */
/*   Updated: 2026/01/21 14:14:58 by ralamair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_sign(char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static double	get_number(char *s, int i)
{
	double	res;
	double	dec;

	res = 0;
	dec = 0.1;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			res += (s[i++] - '0') * dec;
			dec *= 0.1;
		}
	}
	return (res);
}

double	ft_atof(char *s)
{
	int		i;
	int		sign;

	i = 0;
	sign = get_sign(s, &i);
	return (get_number(s, i) * sign);
}
