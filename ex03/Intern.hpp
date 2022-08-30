/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:01:50 by mclam             #+#    #+#             */
/*   Updated: 2022/08/16 01:01:50 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Form;

class Intern
{
private:
	std::string	_formName[3];
	AForm	*(Intern::*ptrMakeFunctions[3])( const std::string& );
	AForm	*_makeShrubberyCreationForm( const std::string &target );
	AForm	*_makeRobotomyRequestForm( const std::string &target );
	AForm	*_makePresidentialPardonForm( const std::string &target );

public:
			Intern( void );
			Intern(const Intern &intern);
	Intern	&operator=(const Intern &intern);
			~Intern( void );
	AForm	*makeForm( const std::string &formName, const std::string &target);
};

std::string	toLowerStr(const std::string src);

#endif
