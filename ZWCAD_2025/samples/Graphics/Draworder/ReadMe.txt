Description: 
This application implements a command called "DraworderExample" to adjust the draworder of entity(s)，which is similar to the command "draworder".

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use Draworder.zrx:
1. Start ZWCAD and open a new drawing , and draw some overlapping entities(such as polylines with lineweights).
2. Run APPLOAD command and load the Draworder.zrx file from the output directory.
3. Execute the "DraworderExample" command. This command can adjust the drawing order by selecting entity(s) and reference entity(s),  or directly select entity(s) as the top or bottom of the display.
