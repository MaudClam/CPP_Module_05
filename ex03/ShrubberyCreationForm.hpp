/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:25:01 by mclam             #+#    #+#             */
/*   Updated: 2022/08/15 13:25:01 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
		const std::string	_target;
public:
							ShrubberyCreationForm( void );
							ShrubberyCreationForm( const std::string &target );
							ShrubberyCreationForm( const ShrubberyCreationForm &form );
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &form);
							~ShrubberyCreationForm( void );

	void					execute(Bureaucrat const &executor) const;

	//exceptions
	class FailedToOpenFileException : public std::exception
	{
	public:
		const char	*what() const throw() {
			return "failed to open file!";
		}
	};
};

#endif
