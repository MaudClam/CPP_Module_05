/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:53:10 by mclam             #+#    #+#             */
/*   Updated: 2022/08/11 12:53:10 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name( "noname" ), _grade( 75 ) {
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ) : _name( name ) {
	if (grade < 1)
		throw GradeTooHighExeption();
	if (grade > 150)
		throw GradeTooLowExeption();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureacrat) {
	*this = bureacrat;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &bureaucrat ) {
	if (this != &bureaucrat)
		this->_grade = bureaucrat._grade;
	return *this;
}

Bureaucrat::~Bureaucrat( void ) {
}

const std::string	Bureaucrat::getName( void ) const {
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade() {
	if (this->_grade <= 1)
		throw GradeTooHighExeption();
	this->_grade--;
}

void	Bureaucrat::decrementGrade() {
	if (this->_grade >= 150)
		throw GradeTooLowExeption();
	this->_grade++;
}

void	Bureaucrat::signForm( AForm &form ) {
	try {
		form.beSigned(*this);
	}
	catch (const std::exception &e) {
		std::cout 	<< this->_name << " couldn’t sign '"
					<< form.getName() << "' becouse "
					<< e.what() << std::endl;
		return ;
	}
	std::cout 	<< this->_name << " signed '"
				<< form.getName() << "'." << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout 	<< this->_name << " executed '"
					<< form.getName() << "'." << std::endl;
	}
	catch (std::exception &e) {
		std::cout 	<< this->getName() << " couldn’t execute '"
					<< form.getName() << "', becouse " << e.what() << std::endl;
	}
}

std::ostream	&operator<<( std::ostream &out, const Bureaucrat &bureaucrat ) {
	out		<< bureaucrat.getName() << ", bureaucrat grade "
			<< bureaucrat.getGrade();
	return out;
}
