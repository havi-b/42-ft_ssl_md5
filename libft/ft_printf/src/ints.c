/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ints.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:18:43 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 18:37:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_int_format(t_id *buff)
{
	int		w;
	int		l;

	w = (buff->size) ? buff->size->width : 0;
	l = ft_strlen(buff->s);
	if (buff->size)
	{
		if (buff->size && buff->size->prcsn > l)
		{
			init_prcsn(buff);
			l = ft_strlen(buff->s);
		}
		if (w > l)
			init_width(buff);
	}
	if (buff->flags & POS_NEG)
		check_pos_neg(buff);
	if (buff->flags & SPACE)
		check_space(buff);
}

char		*init_int_len(char len, intmax_t i)
{
	char	*s;

	s = NULL;
	if (len & H_LEN)
		s = ft_itoa((short)i);
	else if (len & HH_LEN)
		s = ft_itoa((char)i);
	else if (len & L_LEN)
		s = ft_itoa((long)i);
	else if (len & LL_LEN)
		s = ft_itoa((long long)i);
	else if (len & J_LEN)
		s = ft_itoa((intmax_t)i);
	else if (len & Z_LEN)
		s = ft_itoa((size_t)i);
	return (s);
}

void		make_int_str(t_id *buff)
{
	if (buff->size && !buff->size->prcsn && buff->size->dot && \
	(intmax_t)buff->data.data == 0)
		buff->s = ft_strjoin("", "\0");
	else if (buff->id == 'D')
		buff->s = ft_itoa((long)buff->data.data);
	else
		buff->s = (buff->len && !(buff->len & UL_LEN)) ? \
		init_int_len(buff->len, (intmax_t)buff->data.data) : \
		ft_itoa((int)buff->data.data);
	init_int_format(buff);
}
