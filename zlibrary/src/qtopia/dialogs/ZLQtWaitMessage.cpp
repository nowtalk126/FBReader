/*
 * Copyright (C) 2004-2007 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include <qapplication.h>
#include <qwidget.h>
#include <qlabel.h>
#include <qlayout.h>

#include "ZLQtWaitMessage.h"

ZLQtWaitMessage::ZLQtWaitMessage(const std::string &message) : QWidget(0, 0, WType_Popup) {
	resize(1, 1);
	QHBoxLayout layout(this, 24);
	QLabel *label = new QLabel(QString::fromUtf8(message.c_str()), this);
	layout.add(label);

	qApp->processEvents();

	QWidget *root = QApplication::desktop();
	move(root->width() / 2 - width() / 2, root->height() / 2 - height() / 2);
	show();
	move(root->width() / 2 - width() / 2, root->height() / 2 - height() / 2);

	qApp->processEvents();
}
