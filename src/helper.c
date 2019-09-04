/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 04:01:53 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/30 16:39:41 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_md5.h"

void					encode(unsigned char *output, uint32_t *input, \
						unsigned int len)
{
	unsigned int		i;
	unsigned int		j;

	j = 0;
	i = 0;
	while (j < len)
	{
		output[j] = (unsigned char)(input[i] & 0xff);
		output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
		output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
		output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
		i++;
		j += 4;
	}
}

void					print_hash(uint32_t *state, uint8_t len)
{
	unsigned char		digest[len];
	unsigned int		i;

	encode(digest, state, len);
	i = 0;
	while (i < len)
		ft_printf("%02x", digest[i++]);
}

uint64_t				ssl_validate_file(char *file)
{
	struct stat			stat;

	if (!(lstat(file, &stat) == 0))
		ssl_error(file, ERRNO);
	if ((S_ISDIR(stat.st_mode)))
		return (0);
	else
		return ((uint64_t)stat.st_size);
}

t_ssl					*init_ssl(void)
{
	t_ssl				*ssl;

	if (!(ssl = (t_ssl *)malloc(sizeof(t_ssl))))
		ssl_error("", MALL_ERR);
	ssl->mode = 0;
	ssl->flags = 0;
	ssl->m = NULL;
	ssl->len = 0;
	ssl->l = 0;
	return (ssl);
}
