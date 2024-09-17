/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:32:27 by sadoming          #+#    #+#             */
/*   Updated: 2024/09/10 18:32:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **args)
{
    int i, j;

    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    else
    {
        i = -1;
        while (args[++i])
        {
            j = -1;
            while (args[i][++j])
                if (args[i][j] >= 'a' && args[i][j] <= 'z')
                    args[i][j] = args[i][j] - 32;
            std::cout << args[i];
        }
        std::cout << std::endl;
    }
    return (0);
}