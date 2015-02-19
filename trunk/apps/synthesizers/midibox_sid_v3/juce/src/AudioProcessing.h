/* -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*- */
/*
  ==============================================================================

  This file is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-7 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

  JUCE can be redistributed and/or modified under the terms of the
  GNU General Public License, as published by the Free Software Foundation;
  either version 2 of the License, or (at your option) any later version.

  JUCE is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with JUCE; if not, visit www.gnu.org/licenses or write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

  If you'd like to release a closed-source product which uses JUCE, commercial
  licenses are also available: visit www.rawmaterialsoftware.com/juce for
  more information.

  ==============================================================================
*/

#ifndef AUDIO_PROCESSING_H
#define AUDIO_PROCESSING_H

#include "../resid/resid.h"
#include "MbSidEnvironment.h"
#include "MidiProcessing.h"


// number of emulated SID(s)
// if 0: emulation disabled
#define SID_NUM 2


class AudioProcessing  : 
    public AudioProcessor, 
    public ChangeBroadcaster
{
public:
    //==============================================================================
    AudioProcessing();
    ~AudioProcessing();
  
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
  
    void processBlock (AudioSampleBuffer& buffer,
                       MidiBuffer& midiMessages);
  
    //==============================================================================
    AudioProcessorEditor* createEditor();
  
    //==============================================================================
    const String getName() const;
  
    int getNumParameters();
  
    float getParameter (int index);
    void setParameter (int index, float newValue);
  
    const String getParameterName (int index);
    const String getParameterText (int index);
  
    const String getInputChannelName (const int channelIndex) const;
    const String getOutputChannelName (const int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;
  
    bool acceptsMidi() const;
    bool producesMidi() const;

    const String getPatchName(void);
    const String getPatchNameFromBank(int bank, int patch);

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);
  
    //==============================================================================
    MidiProcessing midiProcessing;
  
    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);
  
    //==============================================================================
    // These properties are public so that our editor component can access them
    //  - a bit of a hacky way to do it, but it's only a demo!
  
    // this is kept up to date with the midi messages that arrive, and the UI component
    // registers with it so it can represent the incoming messages
    MidiKeyboardState keyboardState;
  
    // this keeps a copy of the last set of time info that was acquired during an audio
    // callback - the UI component will read this and display it.
    AudioPlayHead::CurrentPositionInfo lastPosInfo;

    //==============================================================================
    // the additional MIDI interface for SysEx data
    MidiMessageCollector midiCollector;

    // these are used to persist the UI's size - the values are stored along with the
    // SidEmu's other parameters, and the UI component will update them when it gets
    // resized.
    int lastUIWidth, lastUIHeight;

	// MIDI In/Out stored in preferences file
	String lastSysexMidiIn, lastSysexMidiOut;
	

#if SID_NUM
    SID *reSID[SID_NUM];
    MbSidEnvironment mbSidEnvironment;
#endif
  
    int reSidEnabled;
    double reSidSampleRate;
    double reSidDeltaCycleCounter;

    double mbSidUpdateCounter;

    sid_regs_t sidRegs[SID_NUM];
    sid_regs_t sidRegsShadow[SID_NUM];
    s32 RESID_Update(u32 mode);

  
    //==============================================================================
    juce_UseDebuggingNewOperator
  
private:
    float gain;
    unsigned char bank;
    unsigned char patch;
};


#endif
