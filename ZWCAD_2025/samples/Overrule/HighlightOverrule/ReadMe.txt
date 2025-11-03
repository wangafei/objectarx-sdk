Description: 
This application demonstrates the use of the AcDbHighlightOverrule class, which can overrule the highlight related operations that AcDbEntity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use HighlightOverrule.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the HighlightOverrule.zrx file in the output directory.
3. Execute the "addHighlightOverrule" command to add the HighlightOverrule(Execute the "removeHighlightOverrule" to remove). Then draw a line and a circle. The highlight behavior is overruled: the line cannot be highlighted when selecting or hovering over them, and the circle is still highlighted when deselecting or ending hovering.