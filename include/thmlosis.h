/***************************************************************************
                          thmlosis.h  -  description
                             -------------------
    begin                : 2001-09-03
    copyright            : 2001 by CrossWire Bible Society
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef THMLOSIS_H
#define THMLOSIS_H

#include <swbasicfilter.h>

#include <defs.h>

/** this filter converts ThML text to HTML text with hrefs
 */
class SWDLLEXPORT ThMLOSIS : public SWBasicFilter {
protected:
	virtual bool handleToken(char **buf, const char *token, DualStringMap &userData);
	virtual const char *convertToOSIS(const char *);
public:
	ThMLOSIS();
	char ProcessText(char *text, int maxlen, const SWKey *, const SWModule * = 0);
};

#endif /* THMLOSIS_H */
