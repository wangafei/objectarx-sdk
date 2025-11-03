Description: 
This application demonstrates the use of the DrawableOverrule class, which can overrule the draw related operations that the Drawable class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use DrawableOverruleSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the DrawableOverruleSample.dll file in the output directory.
3. Execute the "AddDrawableOverrule" command to add the DrawableOverrule(Execute the "RemoveDrawableOverrule" to remove). Then draw a line and you will find a text is drawn at the end of the line.