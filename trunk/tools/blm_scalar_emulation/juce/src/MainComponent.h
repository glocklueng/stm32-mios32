/* -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*- */
// $Id: UploadHandler.cpp 928 2010-02-20 23:38:06Z tk $
/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  7 Feb 2010 7:52:20 pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MAINCOMPONENT_MAINCOMPONENT_4DFCBE01__
#define __JUCER_HEADER_MAINCOMPONENT_MAINCOMPONENT_4DFCBE01__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "BlmClass.h"
#include "UdpSocket.h"
#include "OscHelper.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent
    : public Component
    , public ComboBoxListener
    , public ButtonListener
    , public OscListener
    , public Timer
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	int getMidiInput(void) {return midiInput->getSelectedId();}
	int getMidiOutput(void) {return midiOutput->getSelectedId();}

    void scanMidiInDevices();
    void scanMidiOutDevices();

	void setMidiOutput(const String &port);
	void setMidiInput(const String &port);
    void sendMidiMessage(const MidiMessage& message);

    void timerCallback();

    UdpSocket* udpSocket;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void buttonClicked (Button* buttonThatWasClicked);

    void parsedOscPacket(const OscHelper::OscArgsT& oscArgs, const unsigned& methodArg);

	AudioDeviceManager audioDeviceManager;



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    BlmClass* blmClass;
    ComboBox* midiInput;
    ComboBox* midiOutput;
    Label* label;
    Label* label2;

    Label* remoteHostLabel;
    TextEditor* remoteHostLine;
    Label* portNumberReadLabel;
    TextEditor* portNumberReadLine;
    Label* portNumberWriteLabel;
    TextEditor* portNumberWriteLine;
    Button* connectButton;
    Button* disconnectButton;

    unsigned oscPort;

    int initialMidiScanCounter;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MainComponent (const MainComponent&);
    const MainComponent& operator= (const MainComponent&);
};


#endif   // __JUCER_HEADER_MAINCOMPONENT_MAINCOMPONENT_4DFCBE01__
