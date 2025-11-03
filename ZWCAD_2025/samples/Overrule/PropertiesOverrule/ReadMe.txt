Description: 
This application demonstrates the use of the AcDbPropertiesOverrule class, which can overrule the property related operations that the AcDbEntity and AcDbObject classes specify.

To run the sample:
Please use Visual Studio 2017 to open the solution called "Samples.sln" and switch to the configuration that matches with the ZWCAD version，then build the application.

To use PropertiesOverrule.zrx:
1. Start ZWCAD and open a new drawing.
2. Run APPLOAD command and load the PropertiesOverrule.zrx file in the output directory.
3. Execute the "AddPropertiesOverrule" command to add the PropertiesOverrule(Execute the "RemovePropertiesOverrule" to remove). Draw a line and execute command "List". The list information of the line has been overruled.