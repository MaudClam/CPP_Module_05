/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclam <mclam@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:50:41 by mclam             #+#    #+#             */
/*   Updated: 2022/08/15 20:50:41 by mclam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
		const std::string	_target;
public:
							PresidentialPardonForm( void );
							PresidentialPardonForm( const std::string &target );
							PresidentialPardonForm( const PresidentialPardonForm &form );
	PresidentialPardonForm	&operator=(const PresidentialPardonForm &form);
							~PresidentialPardonForm( void );

	void					execute(Bureaucrat const &executor) const;
};

#endif
