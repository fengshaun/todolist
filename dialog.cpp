/***************************************************************************
 * General Ledger, Copyright (C) 2008 Armin Moradi <feng.shaun@gmail.com>  *
 * http://fengshaun.wordpress.com                                          *
 *                                                                         *
 * This program is free software; you can redistribute it and/or modify    *
 * it under the terms of the GNU General Public License as published by    *
 * the Free Software Foundation; either version 3 of the License, or       *
 * (at your option) any later version.                                     *
 *                                                                         *
 * This program is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            *
 * GNU General Public License for more details.                            *
 *                                                                         *
 * You should have received a copy of the GNU General Public License       *
 * along with this program; if not, write to the Free Software             *
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 US  *
 ***************************************************************************/

#include <QtGui>

#include "dialog.h"

TodoDialog::TodoDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	connect(addButton, SIGNAL(clicked()), this, SLOT(add()));
	
	groupBoxLayout = new QVBoxLayout;
	groupBox->setLayout(groupBoxLayout);
}

void TodoDialog::add() {
	QString itemString = lineEdit->text();
	QCheckBox *chBox = new QCheckBox(groupBox);
	chBox->setText(itemString);
	connect(chBox, SIGNAL(toggled(bool)), chBox, SLOT(setHidden(bool)));
	groupBoxLayout->addWidget(chBox);
}