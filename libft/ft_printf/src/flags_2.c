/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 05:09:03 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 18:38:01 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*init_hash(char *s, char id)
{
	char	*temp;

	temp = s;
	if (id == 'p' || id == 'P')
		s = (id == 'p') ? ft_strjoin("0x", temp) : ft_strjoin("0X", temp);
	else if (id == 'x' || id == 'X')
		s = (id == 'x') ? ft_strjoin("0x", temp) : ft_strjoin("0X", temp);
	else if (id == 'o')
		s = ft_strjoin("0", temp);
	free(temp);
	return (s);
}

void		check_hash(t_id *buff)
{
	if (is_valid_hash(buff) && !buff->size->prcsn)
		buff->s = init_hash(buff->s, buff->id);
	else if (ispntr_id(buff->id) && buff->size->prcsn < buff->size->width \
	&& !(ft_strchr(buff->s, 'x') || ft_strchr(buff->s, 'X')))
		buff->s = init_hash(buff->s, buff->id);
}

char		*init_space(char *s)
{
	char	*temp;

	temp = s;
	s = ft_strjoin(" \0", temp);
	free(temp);
	return (s);
}

void		check_space(t_id *buff)
{
	if (isint_id(buff->id) && \
	!(buff->flags & POS_NEG) && buff->flags & SPACE && \
	!(buff->size && buff->size->width >= (int)ft_strlen(buff->s)) && \
	buff->s[0] != '-')
		buff->s = init_space(buff->s);
	else if (buff->flags & PADDING && buff->flags & SPACE && \
	buff->size && buff->size->width && buff->s[0] == '0')
		buff->s[0] = ' ';
}
