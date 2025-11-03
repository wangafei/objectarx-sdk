Description: 
This application implements two commands called "createLineTypeTest" and "applyCusLineTypeTest" to demonstrate the use of the custom linetype.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use CusLinetype.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the CusLinetype.zrx file in the output directory.
3. Execute the "createLineTypeTest" command, which create two custom linetypes called "CustomLinetype1" ans "CustomLinetype2".
4. Execute the "applyCusLineTypeTest" command, which draws two lines that apply the two custom linetypes.