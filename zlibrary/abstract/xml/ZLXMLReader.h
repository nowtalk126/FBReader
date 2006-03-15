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

#ifndef __ZLXMLREADER_H__
#define __ZLXMLREADER_H__

#include <string>
#include <vector>

#include <abstract/shared_ptr.h>

class ZLInputStream;
class ZLXMLReaderInternal;

class ZLXMLReader {

public:
	static size_t bufferSize() { return 2048; }

protected:
  static const char *attributeValue(const char **xmlattributes, const char *name) XML_SECTION;

protected:
	ZLXMLReader(const char *encoding = 0) XML_SECTION;
	virtual ~ZLXMLReader() XML_SECTION;

public:
	bool readDocument(shared_ptr<ZLInputStream> stream) XML_SECTION;

	virtual void startElementHandler(const char *tag, const char **attributes) XML_SECTION;
	virtual void endElementHandler(const char *tag) XML_SECTION;
	virtual void characterDataHandler(const char *text, int len) XML_SECTION;
	virtual const std::vector<std::string> &externalDTDs() const XML_SECTION;

	bool isInterrupted() const XML_SECTION;

protected:
	void interrupt() XML_SECTION;

private:
	bool myInterrupted;
	ZLXMLReaderInternal *myInternalReader;
	char *myParserBuffer;
};

inline bool ZLXMLReader::isInterrupted() const {
	return myInterrupted;
}

inline void ZLXMLReader::interrupt() {
	myInterrupted = true;
}

#endif /* __ZLXMLREADER_H__ */
