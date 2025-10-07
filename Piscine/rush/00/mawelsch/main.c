/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:04:59 by mawelsch          #+#    #+#             */
/*   Updated: 2025/08/02 13:49:40 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//forward declaration of the rush function so the function can be called,
//without being explicitly included or defined in the same file.
void	rush(int lenght, int hight);

//the main function so the rush function can
//be tested and evaluated effectively.
int	main(int argument_count, char *argument_values[1])
{
	rush(3, 5);
	return (0);
}
