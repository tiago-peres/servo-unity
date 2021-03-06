//
// ServoUnityWindow.h
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0.If a copy of the MPL was not distributed with this
// file, You can obtain one at https ://mozilla.org/MPL/2.0/.
//
// Copyright (c) 2019-2020 Mozilla, Inc.
//
// Author(s): Philip Lamb
//

#pragma once

#include "servo_unity_c.h"
#include <string>

class ServoUnityWindow
{
protected:
	ServoUnityWindow(int uid, int uidExt) : m_uid(uid), m_uidExt(uidExt) { }
	int m_uid;
	int m_uidExt;
public:
	virtual ~ServoUnityWindow() {};

	enum RendererAPI {
		None = 0,
		Unknown,
		DirectX11,
		OpenGLCore
	};

	enum class BrowserEventType : uint8_t {
		None = 0,
		IME,
		Total
	};

	struct Size {
		int w;
		int h;
	};

	int uid() { return m_uid; }
	int uidExt() { return m_uidExt; }
	void setUidExt(int uidExt) { m_uidExt = uidExt; }
	virtual bool init(PFN_WINDOWCREATEDCALLBACK windowCreatedCallback, PFN_WINDOWRESIZEDCALLBACK windowResizedCallback, PFN_BROWSEREVENTCALLBACK browserEventCallback) = 0;
	virtual RendererAPI rendererAPI() = 0;
	virtual Size size() = 0;
	virtual void setSize(Size size) = 0;
	virtual int format() = 0;
	virtual void setNativePtr(void* texPtr) = 0;
	virtual void* nativePtr() = 0;
    virtual void serviceWindowEvents(void) = 0;
    virtual std::string windowTitle(void) = 0;
    virtual std::string windowURL(void) = 0;
	virtual void requestUpdate(float timeDelta) = 0;
    virtual void cleanupRenderer() = 0;
	
	virtual void CloseServoWindow() = 0;
	virtual void pointerEnter() = 0;
	virtual void pointerExit() = 0;
	virtual void pointerOver(int x, int y) = 0;
	virtual void pointerPress(int button, int x, int y) = 0;
	virtual void pointerRelease(int button, int x, int y) = 0;
	virtual void pointerClick(int button, int x, int y) = 0;
    virtual void pointerScrollDiscrete(int x_scroll, int y_scroll, int x, int y) = 0; // x and y are a discrete scroll count, e.g. count of mousewheel "clicks".
	virtual void keyEvent(int upDown, int keyCode, int character) = 0;

    virtual void refresh() = 0;
    virtual void reload() = 0;
    virtual void stop() = 0;
    virtual void goBack() = 0;
    virtual void goForward() = 0;
    virtual void goHome() = 0;
    virtual void navigate(const std::string& urlOrSearchString) = 0;
};

