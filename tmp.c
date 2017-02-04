/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 19:07:17 by pbernier          #+#    #+#             */
/*   Updated: 2017/02/04 16:48:08 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

//Les spécifications de conversion sont introduites par le caractère %,
//	et se terminent par un indicateur de conversion.
//	Entre eux peuvent se trouver (dans l'ordre), zéro ou plusieurs attributs,
//	une valeur optionnelle de largeur minimal de champ, une valeur optionnelle
//	de précision, et un éventuel modificateur de longueur.

//%[flags][width][.precision][length]specifier
//Modificateur de longeur, attributs



int		main(void)
{
//	char		*len = "#0-+ ";
	//Largeur du champ 0 *m (-)
	//precision <.x> | diouxX = nb_min | aAeEfE = decimal | gG = nb_sign | sS |
	//hh, h, l, ll (diouxX)
//	char		*flags = "hljz";
//	char		*spec = "sSpdDioOuUxXcC";*/

	printf("%s\n", isolate_per("%#-0.7dje jj"));
	return (0);
}
