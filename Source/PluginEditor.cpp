/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
//Constructor where we create UI programmatically
DelayManAudioProcessorEditor::DelayManAudioProcessorEditor (DelayManAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
//initializing all three attachment classes
    gainAttachment (p.state, "gain", gainSlider),
    feedbackAttachment(p.state, "feedback", feedbackSlider),
    mixAttachment(p.state, "mix", mixSlider)
{
    //creating nfunction slider style configurations
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    feedbackSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    mixSlider.setSliderStyle(juce::Slider::SliderStyle::Rotary);
    
    //iterating over slider styles specifiying values in text box below sliders based on postion
    for (auto* slider : {&gainSlider, &feedbackSlider, &mixSlider})
    {
        slider->setTextBoxStyle(juce::Slider::TextBoxAbove, true, 200, 30);
        
        //creating label variables
        juce::Label* label = new juce::Label();
        
        //assigning unique names to the label variables
        if (slider == &gainSlider)
            label->setText("Gain", juce::NotificationType::dontSendNotification);
        else if (slider == &feedbackSlider)
            label->setText("Feedback", juce::NotificationType::dontSendNotification);
        else if (slider == &mixSlider)
            label->setText("Mix", juce::NotificationType::dontSendNotification);
        
        //setting style and font size of slider labels
        label->attachToComponent(slider, false);
        label->setFont(juce::Font(14.0f));
        label->setJustificationType(juce::Justification::centred);
        
        //makes slider a child component of the audio processor editor
        addAndMakeVisible(label);
        addAndMakeVisible(slider);
    }
    
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

DelayManAudioProcessorEditor::~DelayManAudioProcessorEditor()
{
}

//==============================================================================
void DelayManAudioProcessorEditor::paint (juce::Graphics& g)
{
    //background color
    g.fillAll(juce::Colour (0xff121212));
    
    //widget background color
    g.setColour(juce::Colours::transparentBlack);
    
    juce::Rectangle<float> backgroundRect = getLocalBounds().toFloat();
    int numBackgroundRects = 60;
    juce::Point<float> offset = backgroundRect.getBottomRight() / numBackgroundRects;
    
    //adding background foundation for words
    for (int i = 0; i <numBackgroundRects; ++i)
    {
        g.drawRect(backgroundRect);
        backgroundRect += offset;
    }
    //creating  rectangle in which words will be displayed
    juce::Rectangle<int> bounds = getLocalBounds();
    juce::Rectangle<int> textArea = bounds.removeFromLeft((bounds.getWidth() * 2) / 3) .removeFromBottom(bounds.getHeight() /2) .reduced(10);
    
    //creating gradient that will be on text
    juce::ColourGradient gradient (juce::Colour (0xffe62875), textArea.toFloat().getTopLeft(), juce::Colour (0xffe43d1b), textArea.toFloat().getTopRight(), false);
    g.setGradientFill(gradient);
    
    //adding fitted text to rectangle with gradient of letters
    float fontSize = textArea.getHeight() * 0.2f; //changes font size
    g.setFont(fontSize);
    g.drawFittedText("DelayMan", textArea, juce::Justification::centred, 1);
}
//Whenever user changes window size this function will be called
void DelayManAudioProcessorEditor::resized()
{
    //Where children of parent functions will be layed out, for example if you wanted a flexble or scalable user interface
    juce::Rectangle<int> bounds = getLocalBounds();
    int margin = 20;
    
    juce::Rectangle<int> gainBounds = bounds.removeFromRight(getWidth() / 3);
    gainSlider.setBounds (gainBounds.reduced(margin));
    
    juce::Rectangle<int> knobsBounds = bounds.removeFromTop(getHeight() / 2);
    juce::Rectangle<int> feedbackBounds = knobsBounds.removeFromLeft(knobsBounds.getWidth() / 2);
    
    feedbackSlider.setBounds(feedbackBounds.reduced(margin));
    mixSlider.setBounds (knobsBounds.reduced(margin));
}
