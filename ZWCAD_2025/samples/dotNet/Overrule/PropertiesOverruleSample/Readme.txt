Description: 
This application demonstrates the use of the PropertiesOverrule class, which can overrule the property related operations that the Entity and DBObject classes specify.

To run the sample:
Please use Visual Studio 2017 to open the solution called "DotNetSamples.sln"，then build the application.

To use PropertiesOverruleSample.dll:
1. Start ZWCAD and open a new drawing.
2. Run NETLOAD command and load the PropertiesOverruleSample.dll file in the output directory.
3. Execute the "AddPropertiesOverrule" command to add the PropertiesOverrule(Execute the "RemovePropertiesOverrule" to remove). Draw a line and execute command "List". The list information of the line has been overruled.