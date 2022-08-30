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

#include "AForm.hpp"

AForm::AForm() :
_name( "noname" ),
_signed( false ),
_signGrade( 75 ),
_execGrade( 75 ) {}

AForm::AForm( const std::string &name, const int sGrade, int eGrade ) :
_name(name),
_signed( false ),
_signGrade( sGrade ),
_execGrade( eGrade ) {
	if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &form) :
_name( form._name ),
_signed( form._signed ),
_signGrade(form._signGrade),
_execGrade( form._execGrade ) {
	*this = form;
}

AForm	&AForm::operator=(const AForm &form) {
	(void)form;
	return *this;
}

AForm::~AForm( void ) {
}

const std::string AForm::getName( void ) const {
	return this->_name;
}

bool AForm::getSigned( void ) const {
	return this->_signed;
}

int	AForm::getSignGrade( void ) const {
	return this->_signGrade;
}

int	AForm::getExecGrade( void ) const {
	return this->_execGrade;
}

void	AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

void	AForm::beExecuted(Bureaucrat const &bureaucrat) const {
	if (this->_signed == false)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > this->_execGrade)
		throw GradeTooLowException();
}

std::ostream	&operator<<( std::ostream &out, const AForm &form ) {
	out 	<< "Form: " << form.getName()
			<< "\nSigned: " << (form.getSigned() ? "Yes" : "No")
			<< "\nSign Grade: " << form.getSignGrade()
			<< "\nExecute Grade: " << form.getExecGrade()
			<< std::endl;
	return out;
}
