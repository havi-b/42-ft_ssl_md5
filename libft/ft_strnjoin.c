/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 20:06:13 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 17:51:01 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(const char *s1, const char *s2, \
				size_t s1_l, size_t s2_l)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (s1_l + s2_l))))
		return (NULL);
	ft_strncpy_u(ret, s1, s1_l);
	ft_strncpy_u((ret + s1_l), s2, s2_l);
	return (ret);
}
