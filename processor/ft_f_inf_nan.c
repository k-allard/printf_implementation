/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_inf_nan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/11 11:11:18 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_f_inf_nan(va_list* argptr, t_format* argformat)
{
	if (argptr == NULL)
	{
		argformat = NULL;
		return ERROR;
	}
	return OK;
}