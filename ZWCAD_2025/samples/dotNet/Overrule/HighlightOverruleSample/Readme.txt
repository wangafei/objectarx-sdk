Description: 
This application demonstrates the use of the HighlightOverrule class, which can overrule the highlight related operations that Entity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use HighlightOverruleSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the HighlightOverruleSample.dll file in the output directory.
3. Execute the "HighlightOverruleOnOff" command to add the HighlightOverrule(Execute the "HighlightOverruleOnOff" again to remove). Then draw a line and a circle. The highlight behavior is overruled: the line cannot be highlighted when selecting or hovering over them, and the circle is still highlighted when deselecting or ending hovering.