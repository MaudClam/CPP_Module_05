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

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
public:
						Form( void );
						Form( const std::string &name, const int sGrade, int eGrade );
						Form( const Form &form );
	Form				&operator=(const Form &form);
						~Form( void );
	const std::string	getName( void ) const;
	bool				getSigned( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	
	void				beSigned(Bureaucrat &bureaucrat);
	
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
};

std::ostream	&operator<<( std::ostream &out, const Form &form );

#endif
