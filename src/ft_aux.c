#include "fdf.h"

int	ft_isbelowzero(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

int ft_isbigger(int first, int second)
{
	if (first > second)
		return (first);
	else
		return (second);
}
