Description: 
This application implements a command called "DraworderCSExample" to adjust the draworder of entity(s)，which is similar to the command "draworder".

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use DrawOrder.dll:
1. Start ZWCAD and open a new drawing , and draw some overlapping entities(such as polylines with lineweights).
2. Run NETLOAD command and load the DrawOrder.dll file in the output directory.
3. Execute the "DraworderCSExample" command. This command can adjust the drawing order by selecting entity(s) and reference entity(s),  or directly select entity(s) as the top or bottom of the display.