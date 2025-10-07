/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spostica <spostica@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:44:52 by spostica          #+#    #+#             */
/*   Updated: 2025/07/31 23:08:20 by spostica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_is_negative(int n)
{
    if(n >= 0) 
    {
        write(1,"P",1);
    }
    else
    {
        write(1,"N",1);
    }
        
}

/*int main(void)
{
    ft_is_negative(-4);
    return (0);
}
*/
	












int main()
{ft_is_negative(2);
}
