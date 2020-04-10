/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:43:01 by youlee            #+#    #+#             */
/*   Updated: 2020/04/02 15:20:26 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

static void put_zero(t_type *t1, t_form *f1)
{
    char        *str;
    int         zero;

    zero = (int)(f1 -> pre) - (int)(t1 -> size);
    while (zero--)
    {
        str = ft_strjoin((const char*)"0", (const char *)t1 -> ans);
        free(t1 -> ans);
        t1 -> ans = str;
    }
}

static void left_copy(char *dest, t_type *t1, t_form *f1)
{
    size_t      idx;
    size_t      idx2;

    idx2 = 0;
    idx = 0;
    if (f1 -> flag[3] > 0)
        dest[idx++] = f1 -> neg == true ? '-' : '+';
    else if (f1 -> flag[4] > 0)
        dest[idx++] = f1 -> neg == true ? '-' : ' ';
    else if (f1 -> neg)
        dest[idx++] = '-';
    while (t1 -> ans[idx2] != '\0')
        dest[idx++] = t1 -> ans[idx2++];
    while (idx < f1 -> width)
        dest[idx++] = ' ';
    dest[idx] = '\0';
    print_str(dest, t1);
    free(t1 -> ans);
}

static void right_copy(char *dest, t_type *t1, t_form *f1)
{
    size_t      idx;

    idx = 0;
    if (f1 -> flag[3] > 0 || f1 -> flag[4] > 0)
        (t1 -> size)++;
    if (f1 -> exis[2] && f1 -> flag[1] > 0)
        f1 -> flag[1] = 0;
    if (f1 -> flag[1] > 0)
        right_put_sign_zero(dest, f1, &idx, t1);
    else
        right_put_sign_notzero(dest, f1, &idx, t1);
    print_str(dest, t1);
    free(t1 -> ans);
}

void        print_dec(t_form *f1, va_list *ap, t_type *t1, size_t *index)
{
    int             num;
    char            *str;

    if (t1 -> format[*index] == 'x' || t1 -> format[*index] == 'X' || \
    t1 -> format[*index] == 'u')
        print_unsigned(f1, ap, t1, index);
    else
    {
        num = va_arg(*ap, int);
        if (num < 0)
        {
            f1 -> neg = true;
            num *= -1;
        }
        t1 -> ans = ft_itoa(num);
        t1 -> size = ft_strlen((const char*)t1 -> ans);
        if (ft_strlen((const char *)t1 -> ans) < f1 -> pre)
            put_zero(t1, f1);
        t1 -> size = ft_strlen((const char *)t1 -> ans);
        if (t1 -> size >= f1 -> width)
            print_str(t1 -> ans, t1);
        else
        {
            str = (char*)malloc(sizeof(char) * (f1 -> width));
            f1 -> flag[2] > 0 ? left_copy(str, t1, f1) : right_copy(str, t1, f1);
        }
    }
}