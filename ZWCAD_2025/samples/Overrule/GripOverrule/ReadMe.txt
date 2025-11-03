Description: 
This application demonstrates the use of the AcDbGripOverrule class, which can overrule the grip related operations that AcDbEntity class specifies.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use GripOverrule.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the GripOverrule.zrx file in the output directory.
3. Execute the "AddGripOverrule" command to add the GripOverrule(Execute the "RemoveGripOverrule" to remove). Then draw a line and select it. If the length of the line is less than 1000, the grip will not be displayed.