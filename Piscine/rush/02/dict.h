/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-cad <aben-cad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:22:56 by aben-cad          #+#    #+#             */
/*   Updated: 2025/08/16 08:54:40 by aben-cad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DICT_H

#define MAX_LINES 1000
#define MAX_FIELD 128

typedef struct {
    char key[MAX_FIELD];
    char value[MAX_FIELD];
} Entry;

extern Entry dict[MAX_LINES];
extern int dict_count;

int load_dict(const char *filename);
const char *lookup_word(const char *key);
void debug_print_dict(void);

#endif
