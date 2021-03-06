/**************************************************************************
    Lightspark, a free flash player implementation

    Copyright (C) 2011  Matthias Gehre (M.Gehre@gmx.de)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/
#include <stdint.h>

namespace lightspark
{

class ImageDecoder
{
public:
	/*
	 * Returns a new[]'ed array of decompressed data and sets width, height and format
	 * Return NULL on error
	 */
	static uint8_t* decodeJPEG(uint8_t* inData, int len, uint32_t* width, uint32_t* height);
};

}
