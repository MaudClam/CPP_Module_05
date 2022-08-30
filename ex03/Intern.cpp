/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:02:18 by mclam             #+#    #+#             */
/*   Updated: 2022/08/16 01:02:18 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {
	this->_formName[0] = "shrubbery creation";
	this->_formName[1] = "robotomy request";
	this->_formName[2] = "presidential pardon";
	this->ptrMakeFunctions[0] = &Intern::_makeShrubberyCreationForm;
	this->ptrMakeFunctions[1] = &Intern::_makeRobotomyRequestForm;
	this->ptrMakeFunctions[2] = &Intern::_makePresidentialPardonForm;
}

Intern::Intern( const Intern &intern ) {
	*this = intern;
}

Intern	&Intern::operator=(const Intern &intern) {
	for (int i = 0; i < 3; i++) {
		this->_formName[i] = intern._formName[i];
		this->ptrMakeFunctions[i] = intern.ptrMakeFunctions[i];
	}
	return *this;
}

Intern::~Intern( void ) {
}

AForm	*Intern::_makeShrubberyCreationForm( const std::string &target ) {
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::_makeRobotomyRequestForm( const std::string &target ) {
	return new RobotomyRequestForm(target);
}

AForm	*Intern::_makePresidentialPardonForm( const std::string &target ) {
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm( const std::string &formName, const std::string &target ) {
	int			i = 0;
	
	while (i < 3 && _formName[i] != toLowerStr(formName))
		i++;
	if (i == 3) {
		std::cout << "Couldn't create '" << formName << "'." << std::endl;
		return NULL;
	}
	else {
		std::cout << "Intern creates '" << formName << "'." << std::endl;
		return (this->*ptrMakeFunctions[i])(target);
	}
}

std::string	toLowerStr(const std::string src)
{
	std::string	dst;

	for (unsigned int i = 0; i < src.size(); i++)
		dst += tolower(src[i]);
	return (dst);
}
