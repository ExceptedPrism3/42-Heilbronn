/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 23:19:53 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/09 15:54:27 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
** parse_clues
** Takes a string containing 16 digits (1–4) separated by spaces.
** Fills the clues[] array with these values.
** Returns 1 if successful, 0 otherwise.
*/
int    parse_clues(char *s, int clues[16])
{
    int    i;
    int    idx;

    if (!s)
        return (0);
        
    i = 0;
    idx = 0;
    
    while (s[i] && idx < 16)
    {
        if (s[i] >= '1' && s[i] <= '4')
            clues[idx++] = s[i] - '0';
        else if (s[i] != ' ')
            return (0);
        i++;
    }
    return (idx == 16);
}

/*
** print_error
** Writes "Error" followed by a newline to standard output.
*/
void    print_error(void)
{
    write(1, "Error\n", 6);
}

/*
** print_board
** Prints the 4×4 board as numbers separated by spaces,
** followed by a newline at the end of each row.
Also since we know it will always going to be 4 x 4 so 16 in generale
*/
void    print_board(int board[4][4])
{
    int        r;
    int        c;
    char    ch;

    r = 0;
    while (r < 4)
    {
        c = 0;
        while (c < 4)
        {
            ch = board[r][c] + '0';
            write(1, &ch, 1);
            if (c != 3)
                write(1, " ", 1);

            c++;
        }
        write(1, "\n", 1);
        r++;
    }
}

/* ========================= */
/*   Missing Functions       */
/* ========================= */

/*
** visible_left
** Counts visible towers from left (row or column as int[4]).
*/
int    visible_left(int a[4])
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	while (i < 4)
	{
		if (a[i] > max)
		{
			max = a[i];
			seen++;
		}
		i++;
	}
	return (seen);
}


/*
**visible_right
**Counts visible towers from right (row or column as int[4]).
*/
int    visible_right(int a[4])
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	while (i < 4)
	{
		if (a[i] > max)
		{
			max = a[i];
			seen++;
		}
		i++;
	}
	return (seen);
}



/*


    SARA

*/







int    main(int argc, char **argv)
{
    int    clues[16];
    int    board[4][4] = {{0}};

    if (argc != 2 || !parse_clues(argv[1], clues))
    {
        printf("Meow 1\n");
        printf("Checking: %d\n", argc != 2 || !parse_clues(argv[1], clues));
        printf("Checking argc != 2: %d\n", argc != 2);
        printf("Checking !parse_clues(argv[1], clues): %d\n", !parse_clues(argv[1], clues));
        printf("Checking both conditions: %d | %d\n", argc != 2, !parse_clues(argv[1], clues));
        print_error();
        return (0);
    }
    
    

    
    return (0);
}
