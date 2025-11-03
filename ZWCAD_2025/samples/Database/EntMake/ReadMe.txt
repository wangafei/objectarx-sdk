Description: 
This application implements two commands to demonstrate the example of modifying entitiy(s) through the resbuf linked list rather than object interfaces, and the zrx interfaces involed are:  acdbEntMake, acdbEntMod, acdbEntUpd.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use EntMake.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the EntMake.zrx file in the output directory.
3. Execute the "entMakeTest" command, which draws a red line and red circle.
4. Execute the "entModTest" command, which changes the color of lines and circles in the selection set to yellow and changes the size and position of the entity(s).