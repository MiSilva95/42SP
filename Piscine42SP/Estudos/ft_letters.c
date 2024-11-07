/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:23:46 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/29 11:16:47 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_letters(char *str)
{
    int i = 0;
    char letters;

    while (str[i] != '\0')
    {
        letters = str[i];
        if (letters >= 'a' && letters <= 'z')
        {
            letters = letters - 'a' + 'A';
        }
        else if (letters >= 'A' && letters <= 'Z')
        {
            letters = letters - 'A' + 'a';
        }
        write(1, &letters, 1);
        i++;
    }
    write(1, "\n", 1);
}

int main()
{
    char str[13] = "i lOVE cUSCUZ";
    ft_letters(str);
    return 0;
}
