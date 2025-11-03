Description: 
This application demonstrates how to monitor and change the input point by the AcEdInputPointMonitor class and the AcEdInputPointFilter class.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use InputPoint.zrx:
1. Start ZWCAD and open a new drawing and draw a line and a circle.
2. Run APPLOAD command and load the InputPoint.zrx file in the output directory.
3. Execute the "addInputPointMonitor" command(Execute "removeInputPointMonitor" to remove). Move the mouse ans the command line will print the information of the input point. When you move the mouse over the line or circle drawn in step 1, a prompt box will pop up near the cursor to display the basic information of the entity. Draw a polyline and turn on dynamic snap, and you can find that polylines cannot be dynamically snapped.
4. Execute the "removeInputPointMonitor" command to remove the PointMonitor if you have executed the "addInputPointMonitor" command,  and then execute the "addInputPointFilter" command(Execute "removeInputPointFilter" to remove). Move the mouse ans the command line will print the information of the input point. If the option of changing the point is selected through the prompt box, a red circle with center at the new point will be drawn near the cursor.