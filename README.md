# DelayMan: An Audio Delay Plugin
DelayMan is a fully cross-platform audio delay plugin created using JUCE framework in C++. 
Works with MacOS, Windows, Linux, and any Digital Audio Workstation (DAW).

Designed specifically for musicians, producers, and sound engineers, it is a tool for creating simple to advanced delay effects and enhancing creative audio productions. 

## Setup
1. Prequisites
  * Ensure you have JUCE framework and a C++ compiler on your system (XCode preferred).
2. Clone Repo
  * Clone or download repo onto your local machine.
3. Build Project
  * Open DelayMan project in your preffered IDE or with Projucer tool.
  * Configure target platform and build configurations.
4. Audio Plugin Host
  * Load DelayMan in your DAW and scan for the plugins as normal.
  * If using standalone, open in TestHost app provided by loading component file directly.

## Functionality
<img width="404" alt="DelayMan_UI_Screenshot" src="https://github.com/CeonJones/audio-delay-plugin/assets/68616967/a1b4b777-b0bc-4c23-9ac8-f3a6127910ff">

Features customized editor UI with 3 interactive knobs and corresponding number value readout that can be "turned" by clicking and dragging up or down.

* Feedback Knob: Controls length of the delay
* Mix Knob: Dry/wet parameter which controls intensity of delay
* Gain: Overall gain of the audio input

## Credits

DelayMan uses the following external library. For extra configuration visit:

<a href="https://docs.juce.com/master/index.html">JUCE Documentation</a>: The JUCE Framework is the backbone of DelayMan and provided all the necessary tools for the development of this plugin.

## Contributing
All contributions to futher enhance DelayMan are welcome! If you's like to contribute, please follow steps below:

1. Fork repo and create new branch
2. Add your changes
3. Test and ensure modification are working as intended
4. Push to your forked repo
5. Submit pull request!

## Disclaimer
Please note DelayMan is in its first iteration and may contain limitations and errors, but stay posted for continual improvement as my expertise grows. Thank you for your patience, usage, and contributions, as your feedback is crucial to the future of DelayMan.

## Contact
For inquires, contributions, and feedback big or small <a href="mailto:ceon.j097@gmail.com">email me</a>
