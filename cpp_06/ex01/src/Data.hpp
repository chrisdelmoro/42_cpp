/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:34:38 by ccamargo          #+#    #+#             */
/*   Updated: 2024/01/13 15:12:36 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

struct Data {
    Data(void);
    Data(std::string publicData, std::string privateData, int privateNumber);
    ~Data(void);
    Data(Data const &source);
    Data &operator=(Data const &source);
    
    std::string publicData;
    
    std::string getPrivateData(void) const;
    int         getPrivateNumber(void) const;
private:
    std::string privateData;
    int         privateNumber;
};

#endif