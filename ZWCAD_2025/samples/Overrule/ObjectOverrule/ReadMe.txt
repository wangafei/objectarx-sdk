Description: 
This application demonstrates the use of the AcDbObjectOverrule class, which can overrule the operations that AcDbObject class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use ObjectOverrule.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the ObjectOverrule.zrx file in the output directory.
3. Execute the "AddObjOverruleCanCopy" or "AddObjOverruleCanNotCopy" command to add the ObjectOverrule(Execute the "RemoveObjOverrule" to remove). Draw a polyline and copy it to paste. You can find that the color of the copied polyline turns red after the "AddObjOverruleCanCopy" command and the polyline will forbid to be copied after the "AddObjOverruleCanNotCopy" command.