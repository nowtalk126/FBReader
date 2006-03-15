/*
 * Copyright (C) 2004-2006 Nikolay Pultsin <geometer@mawhrin.net>
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

#ifndef __ENCODINGREADER_H__
#define __ENCODINGREADER_H__

#include "../xml/ZLXMLReader.h"

class EncodingReader : public ZLXMLReader {

protected:
	EncodingReader(const std::string &encoding) XML_SECTION;

public:
	virtual ~EncodingReader() XML_SECTION;

public:
	virtual void startElementHandler(const char *tag, const char **attributes) XML_SECTION;
	int bytesNumber() const XML_SECTION;

protected:
	const std::string myFilePath;
	int myBytesNumber;
};

class EncodingIntReader : public EncodingReader {

public:
	EncodingIntReader(const std::string &encoding) XML_SECTION;
	~EncodingIntReader() XML_SECTION;
	bool fillTable(int *map) XML_SECTION;

public:
	void startElementHandler(const char *tag, const char **attributes) XML_SECTION;

private:
	int *myMap;
};

class EncodingCharReader : public EncodingReader {

public:
	EncodingCharReader(const std::string &encoding) XML_SECTION;
	~EncodingCharReader() XML_SECTION;
	char **createTable() XML_SECTION;

public:
	void startElementHandler(const char *tag, const char **attributes) XML_SECTION;

private:
	char **myMap;
	char myBuffer[3];
};

inline int EncodingReader::bytesNumber() const { return myBytesNumber; }

#endif /* __ENCODINGREADER_H__ */
