/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTestingPluginAudioProcessorEditor::GainTestingPluginAudioProcessorEditor (GainTestingPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    sliderAttachment = new AudioProcessorValueTreeState::SliderAttachment(processor.treeState, GAIN_ID, gainSlider);
    
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 35);
    gainSlider.setRange(0, 1);
    gainSlider.setValue(0.5);
    gainSlider.addListener(this);
    addAndMakeVisible(&gainSlider);
}

GainTestingPluginAudioProcessorEditor::~GainTestingPluginAudioProcessorEditor()
{
}

//==============================================================================
void GainTestingPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void GainTestingPluginAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void GainTestingPluginAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if (slider == &gainSlider)
    {
        processor.rawVolume = gainSlider.getValue() * 0.015;
    }
}
