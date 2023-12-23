/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:30:16 by luicasad          #+#    #+#             */
/*   Updated: 2023/12/22 21:04:02 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

void	test(int num, const char *fmt, ...)
{
	int	yo;
	int	el;
	va_list	args;

	va_start(args, fmt);
	printf("Its test %2d.->", num);
	el = printf(fmt, args);
	printf("<\n");

	printf("My  test %2d.->", num);
	yo = ft_printf(fmt, args);
	printf( "< EL %d YO %d ", el, yo);
	printf( (el != yo) ? "<\033[1;91mKO": "<\033[1;92mOK\n");
	printf("\033[0m\n");
	va_end(args);
}

int	main(void)
{	
	char *test_str = "Luis MIguel";
	unsigned int	u;
	int				num;
	int				*pint;
	char			*s = "@@@";
	char			*s2 = NULL;


    setbuf(stdout, NULL);	
	printf("============== testing %%       ====================\n");
	test(1," %% ");
	test(2," %%%% ");
	test(3," %% %% %% ");
	test(4," %%  %%  %% ");
	test(5, " %%   %%   %% ");
	test(6,"%%");
	test(7, "%% %%");

	printf("============== testing ONLY c ====================\n");
	test(8, "%c", '0');
	test(9, " %c ", '0');
	test(10, " %c", '0' - 256);
	test(11, "%c ", '0' + 256);
	test(12, " %c %c %c ", '0', 0, '1');
	test(13, " %c %c %c ", ' ', ' ', ' ');
	test(14, " %c %c %c ", '1', '2', '3');
	test(15, " %c %c %c ", '2', '1', 0);
	test(16, " %c %c %c ", 0, '1', '2');
	printf("============== testing s and c ====================\n");
	test(17, "EL %%> Mi nombre es %s y mi letra es %c.", test_str, 'L');
	test(18, "EL %%> Mi nombre es %s y mi letra es %c.", "Alfonso", 'A');
	test(19, "EL %%> @@@ es %s y mi letra es %c.", s, 'A');
	test(20, "EL %%> NULL es %s y mi letra es %c.", s2, 'A');
	test(21, "EL %%> NULL es %s y letra null es %c.", s2, '\0');
	printf("============== testing i           ====================\n");
	test(22, "%i|%i|%i", num, 0, 0x7FFFFFFF);
	test(23, "0 is %i", 0);
	test(24, "-2 is %i", num);
	test(25, "negative %i", num);
	test(26, "positive %i", num);
	test(27, "two is  %i", num);
	printf("============== testing u           ====================\n");
	test(28, "-10 is %u", -10);
	u = 2;
	test(29, "-2 is %u", u);
	u = -2147483647;
	test(30, "negative %u", u);
	u = 2147483647;
	test(31, "positive %u", u);
	u = 2;
	test(32, "two is  %u", u);
	printf("-------------- frontier cases --------------------\n");
	printf("============== testing p      ====================\n");

	num = -10;
	pint = &num;
	test(33, "two is  %p", pint);
	test(34, " %p ", -1);
	test(35, " %p ", 15);
	test(36, " %p %p ", LONG_MIN, LONG_MAX);
	test(37, " %p %p ", INT_MIN, INT_MAX);
	test(38, " %p %p ", ULONG_MAX, -ULONG_MAX);


	//c = 'a';
//	d = 'b';
//	num = 0x7FFFFFFF;
//	u = 0xFFFFFFFF;
	// //uncomment for bonus
	// el = printf("printf : a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&c, d, u, s, num, 0, u, u);
	// yo = ft_printf("ftprint: a%pbc%%de%5cfg%-20.15uhij%2sk%-+20.15dlm% inop%#20.15Xq%#xr\n", (void *)&c, d, u, s, num, 0, u, u);
	// printf(" EL %d, YO %d\n", el , yo);
	// el = printf("%.3d\n", -1234);
	// yo = ft_printf("%.3d\n", -1234);
	// printf(" EL %d, YO %d\n", el , yo);
	// el = printf("%-9sScience!\n", "Aperture");
	// yo = ft_printf("%-9sScience!\n", "Aperture");
	// printf(" EL %d, YO %d\n", el , yo);
	// el = printf("%8p-%8s\n", NULL, s2);
	// yo = ft_printf("%8p-%8s\n", NULL, s2);
	// printf(" EL %d, YO %d\n", el , yo);
	test(39, "%p %p ", NULL, NULL);
	test(40, "%5%");
	return (0);
}
