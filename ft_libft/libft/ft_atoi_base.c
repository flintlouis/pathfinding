/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_base.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fhignett <fhignett@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/25 21:28:08 by FlintLouis     #+#    #+#                */
/*   Updated: 2019/03/18 11:40:46 by fhignett      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static	int		check_c(char str, int base)
{
	char	*upper;
	char	*lower;
	int		i;

	i = 0;
	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	while (upper[i] && upper[i] != str && lower[i] != str)
		i++;
	if (i < base)
		return (1);
	else
		return (0);
}

static	int		correct_base(char str)
{
	if (str >= 'a' && str <= 'f')
		return (str - 87);
	if (str >= 'A' && str <= 'F')
		return (str - 55);
	if (str >= '0' && str <= '9')
		return (str - '0');
	return (0);
}

int				ft_atoi_base(char *str, int base)
{
	long	n;
	int		neg;

	n = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (check_c(*str, base))
	{
		n = n * base + correct_base(*str);
		str++;
	}
	return (neg * n);
}
