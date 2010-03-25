/**************************************************************************
    Lightspark, a free flash player implementation

    Copyright (C) 2009,2010  Alessandro Pignotti (a.pignotti@sssup.it)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************/

#ifndef _FLASH_MEDIA_H
#define _FLASH_MEDIA_H

#include "asobjects.h"
#include "flashdisplay.h"
#include "flashnet.h"

namespace lightspark
{

class SoundTransform: public IInterface
{
public:
	static void sinit(Class_base*);
	ASFUNCTION(_constructor);
};

class Video: public DisplayObject, public IThreadJob
{
private:
	sem_t mutex;
	uint32_t width, height, videoWidth, videoHeight;
	bool initialized;
	bool frameReady;
	GLuint videoTexture;
	GLuint videoBuffers[2];
	unsigned int curBuffer;
	NetStream* netStream;
	uint8_t* tmpBuffer;
	void execute();
public:
	Video():width(320),height(240),videoWidth(0),videoHeight(0),initialized(false),frameReady(false),videoTexture(0),curBuffer(0),netStream(NULL),tmpBuffer(NULL)
	{
		sem_init(&mutex,0,1);
	}
	static void sinit(Class_base*);
	static void buildTraits(ASObject* o);
	ASFUNCTION(_constructor);
	ASFUNCTION(_getVideoWidth);
	ASFUNCTION(_getVideoHeight);
	ASFUNCTION(_getWidth);
	ASFUNCTION(_setWidth);
	ASFUNCTION(_getHeight);
	ASFUNCTION(_setHeight);
	ASFUNCTION(attachNetStream);
	void Render();
};

};

#endif