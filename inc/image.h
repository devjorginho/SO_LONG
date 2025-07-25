/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:01:20 by devjorginho       #+#    #+#             */
/*   Updated: 2025/07/25 21:04:07 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_image
{
	void	*wall_img;
	void	*floor_img;
	void	*player_img;
	void	*collect_img;
	void	*exit_img;
	void	*player_on_exit;
	int		w;
	int		h;
}			t_image;

#endif