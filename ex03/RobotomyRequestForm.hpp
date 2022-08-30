/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 21:18:54 by mclam             #+#    #+#             */
/*   Updated: 2022/08/15 21:18:54 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
		const std::string	_target;
public:
							RobotomyRequestForm( void );
							RobotomyRequestForm( const std::string &target );
							RobotomyRequestForm( const RobotomyRequestForm &form );
							RobotomyRequestForm	&operator=(const RobotomyRequestForm &form);
							~RobotomyRequestForm( void );

	void					execute(Bureaucrat const &executor) const;
};

#endif
