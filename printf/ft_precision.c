/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:15:07 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 15:58:31 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

void                check_precision(t_type *t1, size_t *idx, t_form *f1, va_list *ap)
{
    long num;

    num = 0;
    if (t1 -> format[*idx] == '.')
    {
        (*idx)++;
        if (t1 -> format[*idx] == '*')
        {
            num = va_arg(*ap, int);
            if (num < 0)
                f1 -> flag[5] = (int)num;
            else
                f1 -> pre = (size_t)num;
            f1 -> exis[3] = true;
            f1 -> exis[2] = true;
            (*idx)++;
            return ;
        }
        while (t1 -> format[*idx] >= '0' && t1 -> format[*idx] <= '9')
        {
            f1 -> exis[2] = true;
            num *= 10;
            if ((num + (long)(t1 -> format[*idx] - '0')) > 2147483647)
                t1 -> error = true;
            num += t1 -> format[*idx] - '0';
            (*idx)++;
        }
        f1 -> pre = (int)num;
    }
}