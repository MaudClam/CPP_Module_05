/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:53:18 by mclam             #+#    #+#             */
/*   Updated: 2022/08/11 12:53:18 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
						Bureaucrat( void );
						Bureaucrat( const std::string &name, int grade );
						Bureaucrat( const Bureaucrat &bureaucrat );
	Bureaucrat			&operator=( const Bureaucrat &bureaucrat );
						~Bureaucrat( void );
	const std::string	getName( void ) const;
	int					getGrade( void ) const;
	void				incrementGrade( void );
	void				decrementGrade( void );

	void				signForm( AForm &form );
	void				executeForm(AForm const &form);
	
	//exceptions
	class GradeTooHighExeption : public std::exception
	{
	public:
		const char	*what() const throw() {
			return "Grade is too high!";
		};
	};
	class GradeTooLowExeption : public std::exception
	{
	public:
		const char	*what() const throw() {
			return "Grade is too low!";
		};
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
