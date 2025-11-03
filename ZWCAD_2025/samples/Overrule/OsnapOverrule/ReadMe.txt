Description: 
This application demonstrates the use of the AcDbOsnapOverrule class, which can overrule the osnap related operations that the AcDbEntity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use OsnapOverrule.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the OsnapOverrule.zrx file in the output directory.
3. Execute the "AddOsnapOverrule" command to add the OsnapOverrule(Execute the "RemoveOsnapOverrule" to remove). Draw a line and turn on dynamic snap, and then execute "POINT" command to snap near the line. You can see that the osnap behavior has been overruled.