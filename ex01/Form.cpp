/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:24:34 by mclam             #+#    #+#             */
/*   Updated: 2022/08/12 13:24:34 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() :
_name( "noname" ),
_signed( false ),
_signGrade( 75 ),
_execGrade( 75 ) {}

Form::Form( const std::string &name, const int sGrade, int eGrade ) :
_name(name),
_signed( false ),
_signGrade( sGrade ),
_execGrade( eGrade ) {
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &form) :
_name( form._name ),
_signed( form._signed ),
_signGrade(form._signGrade),
_execGrade( form._execGrade ) {
	*this = form;
}

Form	&Form::operator=(const Form &form) {
	(void)form;
	return *this;
}

Form::~Form( void ) {
}

const std::string Form::getName( void ) const {
	return this->_name;
}

bool Form::getSigned( void ) const {
	return this->_signed;
}

int	Form::getSignGrade( void ) const {
	return this->_signGrade;
}

int	Form::getExecGrade( void ) const {
	return this->_execGrade;
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<( std::ostream &out, const Form &form ) {
	out 	<< "Form: " << form.getName()
			<< "\nSigned: " << (form.getSigned() ? "Yes" : "No")
			<< "\nSign Grade: " << form.getSignGrade()
			<< "\nExecute Grade: " << form.getExecGrade()
			<< std::endl;
	return out;
}
