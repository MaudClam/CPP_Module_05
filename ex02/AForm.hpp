/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:24:38 by mclam             #+#    #+#             */
/*   Updated: 2022/08/12 13:24:38 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
public:
						AForm( void );
						AForm( const std::string &name, const int sGrade, int eGrade );
						AForm( const AForm &form );
	AForm				&operator=(const AForm &form);
	virtual				~AForm( void );
	const std::string	getName( void ) const;
	bool				getSigned( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	void				beSigned(Bureaucrat const &bureaucrat);
	void				beExecuted(Bureaucrat const &bureaucrat) const;

	virtual void		execute(Bureaucrat const & executor) const  = 0;

	//exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		const char	*what() const throw() {
			return "grade is too high!";
		}
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char	*what() const throw() {
			return "grade is too low!";
		}
	};
	class FormNotSignedException : public std::exception
	{
	public:
		const char	*what() const throw() {
			return "the form is not signed!";
		}
	};
};

std::ostream	&operator<<( std::ostream &out, const AForm &form );

#endif
