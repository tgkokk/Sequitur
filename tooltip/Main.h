/*
 * ArpTerm Copyright (c)1997-98 by Dianne Hackborn.
 * All rights reserved.
 *
 * Based (increasingly loosly) on WebTerm, a Web-based terminal
 * applet written in Java, which is
 * Copyright (C)1996 by the National Alliance for Computational
 * Science and Engineering (NACSE).
 * See <URL:http://www.nacse.org/> for more information.
 *
 * This code is not public domain, nor freely distributable.
 * Please direct any questions or requests to Dianne Hackborn,
 * at <hackbod@lucent.com> or <hackbod@angryredplanet.com>.
 *
 * ----------------------------------------------------------------------
 *
 * Main.h
 *
 * Main program entry, and application object.  The application
 * simply creates a new TerminalWin for the user to play with.
 *
 * ----------------------------------------------------------------------
 *
 * Known Bugs
 * ~~~~~~~~~~
 *
 * ----------------------------------------------------------------------
 *
 * History
 * ~~~~~~~
 *
 * 0.1: Created this file.
 *
 */

#ifndef MAIN_H
#define MAIN_H

#ifndef _APPLICATION_H
#include <be/app/Application.h>
#endif

#ifndef _ENTRY_H
#include <be/storage/Entry.h>
#endif

// Mime string of our application's signature.
extern const char* AppSig;

class MainApp : public BApplication
{
private:
	typedef BApplication inherited;
	
public:
	MainApp();
	~MainApp();
	
	virtual bool QuitRequested(void);
	virtual void AboutRequested(void);
	virtual void DispatchMessage(BMessage *message, BHandler *handler);
	virtual void MessageReceived(BMessage *message);
	virtual void ArgvReceived(int32 argc, char** argv);
	virtual void RefsReceived(BMessage* message);
	virtual void ReadyToRun(void);
	
	BMessenger mMainWin;
	BMessenger mTipWin;
	bool mCmdLine;
	
	bool MakeMainWindow(const entry_ref file = entry_ref());

private:
};

#endif
