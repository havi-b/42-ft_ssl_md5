/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:09:00 by havi              #+#    #+#             */
/*   Updated: 2019/08/05 18:43:32 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_id			*parse_id(const char *restrict format, va_list args, int *i, \
				t_id *buff)
{
	if (!buff->dollar && !(format[*i] == '%'))
	{
		if (isflt_id(format[*i]))
		{
			if (buff->len & UL_LEN)
				buff->data.u_lf = va_arg(args, long double);
			else
				buff->data.f = va_arg(args, double);
		}
		else
			buff->data.data = va_arg(args, void *);
	}
	buff->id = format[*i];
	*i += 1;
	return (buff);
}

char			parse_len(const char *restrict format, int *i)
{
	char		len;

	len = 0;
	len |= (format[*i] == 'l' && format[*i + 1] != 'l') ? L_LEN : 0;
	len |= (format[*i] == 'l' && format[*i + 1] == 'l') ? LL_LEN : 0;
	len |= (format[*i] == 'h' && format[*i + 1] != 'h') ? H_LEN : 0;
	len |= (format[*i] == 'h' && format[*i + 1] == 'h') ? HH_LEN : 0;
	len |= (format[*i] == 'j') ? J_LEN : 0;
	len |= (format[*i] == 'z') ? Z_LEN : 0;
	len |= (format[*i] == 'L') ? UL_LEN : 0;
	*i += (len & HH_LEN || len & LL_LEN) ? 2 : 1;
	return (len);
}

char			parse_flags(const char *restrict format, int *i)
{
	char		flags;

	flags = 0;
	while (isflag(format[*i]))
	{
		flags |= (1 << ft_strchr_index("-0+# ", format[*i]));
		*i += 1;
		if (format[*i] == ' ')
		{
			while (format[*i] == ' ')
				*i += 1;
		}
	}
	return (flags);
}
