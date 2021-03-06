/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainTestingPluginAudioProcessorEditor  : public AudioProcessorEditor,
                                               public Slider::Listener
{
public:
    GainTestingPluginAudioProcessorEditor (GainTestingPluginAudioProcessor&);
    ~GainTestingPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    void sliderValueChanged(Slider *slider) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainTestingPluginAudioProcessor& processor;
    
    Slider gainSlider;
    AudioProcessorValueTreeState::SliderAttachment sliderAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainTestingPluginAudioProcessorEditor)
};
