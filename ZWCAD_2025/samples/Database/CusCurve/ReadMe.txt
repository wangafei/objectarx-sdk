Description: 
This application implements two commands called "CreateMyCurve" and "CreateMyCurveJig" to demonstrate the use of the custom curve(derived from the AcDbCurve class).

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use CusCurve.zrx:
1. Start ZWCAD and open a new drawing .
2. Run APPLOAD command and load the CusCurve.zrx file in the output directory.
3. Execute the "CreateMyCurve" command, which draws a regular polygon with 25 sides by specifying the center point and end point.
4. Execute the "CreateMyCurveJig" command, which can draw a regular polygon with n sides.